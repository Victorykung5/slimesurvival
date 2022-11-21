#include "knight.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "slime.h"
sf::Sprite test;
sf::Texture food[4];
int rannum = 0;
knight::knight(char type,float mmainknighthelth,float mmainknightspeed ,float damknight ,float expknight,float scoreknight,slime slime1,sf::Texture knightTexture1[5])
{
	for (int i = 0; i < 5; i++)
		knightTexture[i] = knightTexture1[i];
	knighttype = type;
	rannum = 0;
	knighthitbox.setSize(sf::Vector2f(30, 50));
	knighthitbox.setOrigin(20, 25);
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
		speedrand = rand() % 10;
		knightready = 1;
	}
	if (true)
	{   
		knightspeed = knightmainspeed + speedrand;
		if ((knighthitbox.getGlobalBounds().intersects(slime1.spell.getGlobalBounds())) && slime1.spelltype == 's')
		{
			knightspeed = 10;
		}
		knightposition = Knight0.getPosition();
	  	dx = slimex - knightposition.x;
		dy = slimey - knightposition.y;
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
	knighthitbox.setPosition(knightposition.x, knightposition.y);
	knighthitbox.setFillColor(sf::Color(sf::Color::Black));

	//update
	if(knightposition.x<=viewx+480&&knightposition.x>=viewx-480&&knightposition.y<=viewy+340&&knightposition.y>=viewy-340)
	window->draw(Knight0);
}
