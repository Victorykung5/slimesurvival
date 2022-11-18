#include "knight.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "slime.h"
sf::Sprite test;
sf::Texture food[4];
int rannum = 0;
knight::knight(char type,float mmainknighthelth,float mmainknightspeed ,float damknight ,float expknight,float scoreknight,slime slime1)
{
	knighttype = type;
	rannum = 0;
	food[0].loadFromFile("acces/food/1.png");
	food[1].loadFromFile("acces/food/2.png");
	food[2].loadFromFile("acces/food/3.png");
	food[3].loadFromFile("acces/food/4.png");
	knighthitbox.setSize(sf::Vector2f(30, 50));
	knighthitbox.setOrigin(20, 25);
	if (knighttype == 'k')
	{
		knightTexture[0].loadFromFile("acces/Brave/Nknight/s.png");
		knightTexture[1].loadFromFile("acces/Brave/Nknight/w.png");
		knightTexture[2].loadFromFile("acces/Brave/Nknight/d.png");
		knightTexture[3].loadFromFile("acces/Brave/Nknight/a.png");
		knightTexture[4].loadFromFile("acces/Brave/Nknight/s.png");
	}
	else if (knighttype == 'n')
	{
		knightTexture[0].loadFromFile("acces/Brave/ninja/s.png");
		knightTexture[1].loadFromFile("acces/Brave/ninja/w.png");
		knightTexture[2].loadFromFile("acces/Brave/ninja/d.png");
		knightTexture[3].loadFromFile("acces/Brave/ninja/a.png");
		knightTexture[4].loadFromFile("acces/Brave/ninja/s.png");
	}
	Knight0.setOrigin(26.f, 30.f);
	if (knighttype == 'k')
	{
		knightspeed = mmainknightspeed;
		knighthelth = mmainknighthelth;
		mainknighthelth = mmainknighthelth,
		knightdam = damknight;
		knightmainspeed = mmainknightspeed;
		switchtime = 0.3;
	}
	else if(knighttype=='n')
    {
		knightspeed = mmainknightspeed*2.5;
		knighthelth = 0.5;
		mainknighthelth = 0.5;
		if (slime1.Lv > 10)
			knightdam = damknight * 1.5;
		else
			knightdam = damknight;
		knightmainspeed = mmainknightspeed*2.5;
		switchtime = 0.15;
	}
	knightexp = expknight;
	knightscore = scoreknight;
	sf::Vector2f knightposition;
	knightready = 0;
	totaltime = 0, 
	knightframe = 0;
	speedrand = 0;
	rannum = 0;
	hpdrop = false;
	expdrop = false;
	for (int i = 0; i < 4; i++)
	{
		moving[i] = true;
		knockbacking[i] = true;
	}
}
void knight::setup()
{
}
void knight::knightmove(sf::RenderWindow* window, slime slime1, float slimex, float slimey,float viewx, float viewy, float deltatime,std::vector<knight*> &knight1,int numknight,int knighti)
{   //mainmove
	if (knightready == 0)
	{
		int readyx = 0, readyy = 0;
		do {
			readyx = rand() % 2500;
			readyy = rand() % 1321;
	    	} while ((readyx<viewx + 480 && readyx>viewx - 480) || (readyy<viewy + 340 && readyy>viewy - 340));
		Knight0.setPosition(readyx, readyy);
		speedrand = rand() % 8;
		knightready = 1;
	}
	if (true)
	{   
		knightspeed = knightmainspeed + speedrand;
		if ((knighthitbox.getGlobalBounds().intersects(slime1.spell.getGlobalBounds())) && slime1.spelltype == 's')
		{
			knightspeed = 10;
		}
	    sf::Vector2f positionknight = Knight0.getPosition();
		float knightspeedx = knightspeed, knightspeedy = knightspeed;
		float dx = slimex - positionknight.x;
		float dy = slimey - positionknight.y;
		Knight0.setTextureRect(sf::IntRect(0, 0, 50, 60));
		knightspeedx = abs(knightspeed*dx/ sqrt(pow(dx, 2) + pow(dy, 2)));
		knightspeedy = abs(knightspeed * dy / sqrt(pow(dx, 2) + pow(dy, 2)));
		
		{
			if (dy > 0)
			{
				    Knight0.setTexture(knightTexture[0]);
					Knight0.setTextureRect(sf::IntRect(52 * knightframe, 0, 52, 60));
					moving[0] = true;
					if (knight1.size() > 0)
					{
						for (int i = 0; i < knight1.size(); i++)
						{
							if (knighthitbox.getGlobalBounds().contains(knight1[i]->knightposition.x, knight1[i]->knightposition.y - 25) && i != knighti)
							{
								moving[0] = false;
								break;
							}
						}
					}
					if (knighttype == 'k')
					{
						if (moving[0] == true)
							Knight0.move(0.f, knightspeedy * deltatime);
					}
					else if(knighttype=='n')
						Knight0.move(0.f, knightspeedy * deltatime);
			}
			if (dy < 0)
			{
			    	Knight0.setTexture(knightTexture[1]);
					Knight0.setTextureRect(sf::IntRect(52.6 * knightframe, 0, 52.6, 60));
					moving[1] = true;
					if (knight1.size() > 0)
					{
						for (int i = 0; i < knight1.size(); i++)
						{
							if (knighthitbox.getGlobalBounds().contains(knight1[i]->knightposition.x, knight1[i]->knightposition.y + 25) && i != knighti)
							{
								moving[1] = false;
								break;
							}
						}
					}
					if (moving[1] == true)
					{
						if (knighttype == 'k')
						{
							if (moving[1] == true)
								Knight0.move(0.f, -knightspeedy * deltatime);
						}
						else if (knighttype == 'n')
						{
						   Knight0.move(0.f, -knightspeedy * deltatime);
						}
					}

			}
			if (dx > 0)
			{
				Knight0.setTexture(knightTexture[2]);
				Knight0.setTextureRect(sf::IntRect(51 * knightframe, 0, 51, 60));
				moving[2] = true;
				if (knight1.size() > 0)
				{
					for (int i = 0; i < knight1.size(); i++)
					{
						if (knighthitbox.getGlobalBounds().contains(knight1[i]->knightposition.x - 15, knight1[i]->knightposition.y) && i != knighti)
						{
							moving[2] = false;
							break;
						}
					}
				}
				if (knighttype == 'k')
				{
					if (moving[2] == true)
						Knight0.move(knightspeedx * deltatime, 0.f);
				}
				else if(knighttype=='n')
					Knight0.move(knightspeedx * deltatime, 0.f);
			}
			if (dx < 0)
			{
				Knight0.setTexture(knightTexture[3]);
				Knight0.setTextureRect(sf::IntRect(50 * knightframe, 0, 50, 60));
				moving[3] = true;
				if (knight1.size() > 0)
				{
					for (int i = 0; i < knight1.size(); i++)
					{
						if (knighthitbox.getGlobalBounds().contains(knight1[i]->knightposition.x + 15, knight1[i]->knightposition.y) && i != knighti)
						{
							moving[3] = false;
							break;
						}
					}
				}
				if (knighttype == 'k')
				{
					if (moving[3] == true)
						Knight0.move(-knightspeedx * deltatime, 0.f);
				}
				else if (knighttype == 'n')
				{
					Knight0.move(-knightspeedx * deltatime, 0.f);
				}
			}
			if (dx == 0 && dy == 0)
			{
				Knight0.setTexture(knightTexture[4]);
				Knight0.setTextureRect(sf::IntRect(0, 0, 52.6, 60));
			}
		}
		//animation
		totaltime += deltatime;
		if (totaltime>=switchtime) {
			knightframe++;
			totaltime -= switchtime;
			if (knightframe >= 2)
			{
				knightframe = 0;
			}
		}
	}
	//hitbox
	knightposition = Knight0.getPosition();
	knighthitbox.setPosition(knightposition.x, knightposition.y);
	knighthitbox.setFillColor(sf::Color(sf::Color::Black));

	//update
	if(knightposition.x<=viewx+480&&knightposition.x>=viewx-480&&knightposition.y<=viewy+340&&knightposition.y>=viewy-340)
	window->draw(Knight0);
}
void knight::update(sf::RenderWindow* window, slime *slime1, float deltatime,char* gamestate)
{
	hp.setTexture(&food[rannum], true);
	//enimetakedam
	for(int i=0;i<slime1->numbullet;i++)
	{ 
		if (knighthitbox.getGlobalBounds().intersects(slime1->shoot[i].shoot.getGlobalBounds()))
		{
			knighthelth -= slime1->shootdam;
			if (knighthelth <= 0)
			{
				int a = rand() % 100;
				//expdrop
				if (a < 100)
				{		
					
						int xplus = pow(-1, rand() % 2) * (rand() % 20);
						int yplus = pow(-1, rand() % 2) * (rand() % 50);
						exp.setOutlineColor(sf::Color::Black);
						exp.setFillColor(sf::Color::Cyan);
						exp.setOrigin(6, 6);
						exp.setOutlineThickness(1.5);
						exp.setRadius(6);
						exp.setPosition(knightposition.x + xplus, knightposition.y + yplus);
						expdrop = true;
					
				}
				//hpdrop
				if (a < 20)
				{
					int xplus = pow(-1, rand() % 2) * (rand() % 30);
					int yplus = pow(-1, rand() % 2) * (rand() % 45);
					hp.setRadius(20);
					hp.setOrigin(20,20);
					hp.setPosition(knightposition.x + xplus, knightposition.y + yplus);
					hpdrop = true;
					rannum = rand() % 4;
				}
				knightready = 0;
				knighthelth = mainknighthelth;
				slime1->score += knightscore;
			}
			else
			{
				if (slime1->shoot[i].k == 'd')
				{

					Knight0.move(14, 0);
				}
				else if (slime1->shoot[i].k == 'a' && moving[3] == true)
				{
					Knight0.move(-14, 0);
				}
				else if (slime1->shoot[i].k == 'w' && moving[0] == true)
				{
					Knight0.move(0, -14);
				}
				else if (slime1->shoot[i].k == 's' && moving[1] == true)
				{
					Knight0.move(0, 14);
				}
				else if (slime1->shoot[i].k == '3' && moving[3] == true && moving[1] == true)
				{
					Knight0.move(-30/sqrt(2), 30 / sqrt(2));
				}
				else if (slime1->shoot[i].k == '2' && moving[3] == true && moving[0] == true)
				{
					Knight0.move(-30 / sqrt(2), -30 / sqrt(2));
				}
				else if (slime1->shoot[i].k == '1' && moving[0] == true && moving[3] == true)
				{
					Knight0.move(30 / sqrt(2), -30 / sqrt(2));
				}
				else if (slime1->shoot[i].k == '4' && moving[1] == true && moving[3] == true)
				{
					Knight0.move(30 / sqrt(2), 30 / sqrt(2));
				}
			}
			slime1->shoot[i].shootbol = false;
			slime1->shoot[i].shoot.setPosition(slime1->positionslime.x, slime1->positionslime.y);
			slime1->shoot[i].shoot.setRadius(0);
		}
    }
	//pickup
	//exppickup
	if (exp.getGlobalBounds().intersects(slime1->pickup.getGlobalBounds())&&expdrop==true)
	{
		sf::Vector2f positionexp = exp.getPosition();
		float expspeedx = 50, expspeedy = 50;
		float dx = slime1->positionslime.x - positionexp.x;
		float dy = slime1->positionslime.y - positionexp.y;
		if (abs(dx) <= abs(dy) && dx != 0)
		{
			expspeedx = abs(knightspeed * dx / dy);
		}
		else if (abs(dx) > abs(dy) && dy != 0)
		{
			expspeedy = abs(knightspeed * dy / dx);
		}
		if (dy > 0)
		{
			exp.move(0.f, expspeedy*5 * deltatime);
		}
		else if (dy < 0)
		{
			exp.move(0.f,-expspeedy*5*deltatime);
		}
		if (dx > 0)
		{
			exp.move(expspeedx*5*deltatime, 0.f);
		}
		else if (dx < 0)
		{
			exp.move(-expspeedx*5* deltatime, 0.f);
		}
		if (exp.getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
		{
			eatfood.setBuffer(soundbuffer[2]);
			eatfood.setVolume(10);
			eatfood.play();
			exp.setRadius(0);
			expdrop = false;
			slime1->curexp += knightexp;
		}
	}
	//hppickup
	if (hp.getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
	{
		eatfood.setBuffer(soundbuffer[0]);
		eatfood.play();
		hp.setRadius(0);
		hpdrop = false;
		if (slime1->curhp < slime1->maxhp)
			slime1->curhp += 1;
	}
	//slimetakedam
	if (knighthitbox.getGlobalBounds().intersects(slime1->slimehitbox.getGlobalBounds()))
	{
		if (slime1->damageable==true)
		{
			slime1->curhp -= knightdam;
			slime1->damageable = false;
			eatfood.setBuffer(soundbuffer[1]);
			eatfood.play();
			if (slime1->curhp <= 0)
			{
				*gamestate = 'o';
				slime1->curhp = slime1->maxhp;
			}
		}
	}
	//draw
	if (true)
	{
		window->draw(hp);
		window->draw(Knight0);
		window->draw(exp);						
		window->draw(test);
		
	}
}
