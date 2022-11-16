#include "gamelogic.h"
gamelogic::gamelogic()
{
	food[0].loadFromFile("acces/food/1.png");
	food[1].loadFromFile("acces/food/2.png");
	food[2].loadFromFile("acces/food/3.png");
	food[3].loadFromFile("acces/food/4.png");
	soundbuffer[1].loadFromFile("acces/sound/Battle-melee-accent-sword-swing-902.wav");
	soundbuffer[0].loadFromFile("acces/sound/EatingFood1.wav");
	soundbuffer[2].loadFromFile("acces/sound/Minecraft-XP-Sound.wav");
	float knightexp = 5;
	float knightscore = 5;
	rannum = 0;
	for (int i = 0; i < 4; i++)
	{
		moving[i] = true;
		knockbacking[i] = true;
	}
}

void gamelogic::logic(sf::RenderWindow* window, sf::View view, slime* slime1, std::vector<knight*>& knight1, float deltatime, char* gamestate)
{
	//damage
	for (int i = 0; i < knight1.size(); i++)
		{
		    //enimetakedam
			for (int p = 0; p < slime1->numbullet; p++)
			{
				if (knight1[i]->knighthitbox.getGlobalBounds().intersects(slime1->shoot[p].shoot.getGlobalBounds()))
				{
					knight1[i]->knighthelth -= slime1->shootdam;
					if (knight1[i]->knighthelth <= 0)
					{
						int a = rand() % 100;
						//expdrop
						if (a < 100)
						{
							int xplus = pow(-1, rand() % 2) * (rand() % 20);
							int yplus = pow(-1, rand() % 2) * (rand() % 50);
							exp.push_back(new sf::CircleShape);
							exp[exp.size()-1]->setOutlineColor(sf::Color::Black);
							exp[exp.size()-1]->setFillColor(sf::Color::Cyan);
							exp[exp.size()-1]->setOrigin(6, 6);
							exp[exp.size()-1]->setOutlineThickness(1.5);
							exp[exp.size()-1]->setRadius(6);
							exp[exp.size()-1]->setPosition(knight1[i]->knightposition.x + xplus,knight1[i]->knightposition.y + yplus);
							int k = exp[exp.size() - 1]->getRadius();
			
				     	}
						//hpdrop
						if (a < 90)
						{
							int xplus = pow(-1, rand() % 2) * (rand() % 30);
							int yplus = pow(-1, rand() % 2) * (rand() % 45);
							hp.push_back(new sf::CircleShape);
							hp[hp.size() - 1]->setRadius(20);
							hp[hp.size() - 1]->setOrigin(20, 20);
							hp[hp.size() - 1]->setPosition(knight1[i]->knightposition.x + xplus,knight1[i]->knightposition.y + yplus);
							hp[hp.size()-1]->setTexture(&food[rand() % 4]);

						}
		                knight1.erase(knight1.begin()+i);
						slime1->score += knight1[i]->knightscore;
					}
					else
					{
						if (slime1->shoot[i].k == 'd')
						{

							knight1[i]->Knight0.move(14, 0);
						}
						else if (slime1->shoot[i].k == 'a' && moving[3] == true)
						{
							knight1[i]->Knight0.move(-14, 0);
						}
						else if (slime1->shoot[i].k == 'w' && moving[0] == true)
						{
							knight1[i]->Knight0.move(0, -14);
						}
						else if (slime1->shoot[i].k == 's' && moving[1] == true)
						{
							knight1[i]->Knight0.move(0, 14);
						}
						else if (slime1->shoot[i].k == '3' && moving[3] == true && moving[1] == true)
						{
							knight1[i]->Knight0.move(-30 / sqrt(2), 30 / sqrt(2));
						}
						else if (slime1->shoot[i].k == '2' && moving[3] == true && moving[0] == true)
						{
							knight1[i]->Knight0.move(-30 / sqrt(2), -30 / sqrt(2));
						}
						else if (slime1->shoot[i].k == '1' && moving[0] == true && moving[3] == true)
						{
							knight1[i]->Knight0.move(30 / sqrt(2), -30 / sqrt(2));
						}
						else if (slime1->shoot[i].k == '4' && moving[1] == true && moving[3] == true)
						{
							knight1[i]->Knight0.move(30 / sqrt(2), 30 / sqrt(2));
						}
					}
					slime1->shoot[p].shootbol = false;
					slime1->shoot[p].shoot.setPosition(slime1->positionslime.x, slime1->positionslime.y);
					slime1->shoot[p].shoot.setRadius(0);
				}
			}
			//slimetakedam
			if (knight1[i]->knighthitbox.getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
			{
				if (slime1->damageable == true)
				{
					slime1->curhp -= knight1[i]->knightdam;
					slime1->damageable = false;
					eatfood[1].setBuffer(soundbuffer[1]);
					eatfood[1].play();
					if (slime1->curhp <= 0)
					{
						*gamestate = 'o';
						
					}
					if (knight1[i]->knighttype == 'n')
					{
						knight1.erase(knight1.begin() + i);
					}
				}
			}
			
		}
	//exppickup
	if (exp.size() > 0)
	{
			for (int i = 0; i < exp.size(); i++)
		    {
			if (exp[i]->getGlobalBounds().intersects(slime1->pickup.getGlobalBounds()))
			{
				sf::Vector2f positionexp = exp[i]->getPosition();
				float dx = slime1->positionslime.x - positionexp.x;
				float dy = slime1->positionslime.y - positionexp.y;
				expspeedx = 50 * dx / abs(sqrt(pow(dx, 2) + pow(dy, 2)));
				expspeedy = 50 * dy / abs(sqrt(pow(dx, 2) + pow(dy, 2)));
				{
					exp[i]->move(expspeedx * 5 * deltatime, expspeedy*5*deltatime);
				}
				if (exp[i]->getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
				{
					eatfood[2].setBuffer(soundbuffer[2]);
					eatfood[2].setVolume(10);
					eatfood[2].play();
					exp.erase(exp.begin() + i);
					slime1->curexp += knight1[i]->knightexp;
				}
			}
		}
	}
	//hppickup
	if (hp.size() > 0)
		{
			for (int i = 0; i < hp.size(); i++)
			{
				if (hp[i]->getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
				{
					eatfood[0].setBuffer(soundbuffer[0]);
					eatfood[0].play();
					hp[i]->setRadius(0);
					if (slime1->curhp < slime1->maxhp)
						slime1->curhp += 1;
				}
			}
		}
	//draw
	if (true)
		{
			if (hp.size() > 0)
			{
				for (int i = 0; i < hp.size(); i++)
					window->draw(*hp[i]);
			}
			if (exp.size() > 0)
			{
				for(int i=0;i<exp.size();i++)
				window->draw(*exp[i]);
			}
			if (knight1.size() > 0)
			{
				for (int i = 0; i < exp.size(); i++)
				{
				   window->draw(knight1[i]->Knight0);
				}
			}
		}
}


