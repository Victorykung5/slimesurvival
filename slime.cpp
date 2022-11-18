#include "slime.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "bullet.h"
sf::Vector2f neft2;
void slime::setup() 
{

	for (int i = 0; i < 5; i++)
	{
		shoot[i].a = 0;
	}
	shootcooldown = 3.0;
	a = 0;
	shootcur = 0;
	for (int i = 0; i < 5; i++)
	{
		shoot[i].a = 0;
		shoot[i].k = '?';
		shoot[i].shootbol = false;
    }
	slimehitbox.setRadius(18);
	slimehitbox.setOrigin(18, 13);
	Slime.setOrigin(28.f, 22.f);
	spelltxture[0].loadFromFile("acces/spell/Slow.png");
	spelltxture[2].loadFromFile("acces/spell/regen.png");
	spelltxture[1].loadFromFile("acces/spell/speed.png");
	slimetexture[7].loadFromFile("acces/greenslime/AW.png");
	slimetexture[8].loadFromFile("acces/greenslime/S.png");
	slimetexture[4].loadFromFile("acces/greenslime/AS.png");
	slimetexture[2].loadFromFile("acces/greenslime/D.png");
	slimetexture[3].loadFromFile("acces/greenslime/A.png");
	slimetexture[0].loadFromFile("acces/greenslime/W.png");
	slimetexture[1].loadFromFile("acces/greenslime/S.png");
	slimetexture[6].loadFromFile("acces/greenslime/DW.png");
	slimetexture[5].loadFromFile("acces/greenslime/DS.png");
	Txt.loadFromFile("Txtfont.ttf");
	LVtxt.setCharacterSize(40);
	LVtxt.setOutlineColor(sf::Color::Black);
	LVtxt.setOutlineThickness(3);
	LVtxt.setFillColor(sf::Color::White);
	LVtxt.setFont(Txt);
	scoretxt.setFillColor(sf::Color::White);
	scoretxt.setFont(Txt);
	scoretxt.setOutlineColor(sf::Color::Black);
	scoretxt.setOutlineThickness(5);
	scoretxt.setCharacterSize(25);
	timetxt.setFillColor(sf::Color::White);
	timetxt.setFont(Txt);
	timetxt.setOutlineColor(sf::Color::Black);
	timetxt.setOutlineThickness(5);
	timetxt.setCharacterSize(30);
	aimtex.loadFromFile("acces/greenslime/aim/aim.png");
	aim.setOrigin(11.5, 10);
	pickup.setRadius(100);
	pickup.setOrigin(100, 95);
	maxexpbar.setOutlineColor(sf::Color::Black);
	maxexpbar.setOutlineThickness(3);
	maxexpbar.setFillColor(sf::Color(131, 214, 250));
	maxexpbar.setSize(sf::Vector2f(954, 20));
	Expbar.setFillColor(sf::Color(22, 49, 137));
	maxhpbar.setOutlineColor(sf::Color::Black);
	maxhpbar.setOutlineThickness(1);
	maxhpbar.setFillColor(sf::Color::Red);
	hpbar.setFillColor(sf::Color::Green);
	slimeface = '\0';
	spellon = true;
	slimespeed = 90;
	curexp = 0, maxexp = 5;
	curhp = 5, maxhp = 5, numbullet = 1;
	score = 0;
	aimming = false;
	shootdam = 0.75;
	curcooldown = 0;
	curtime = 0, min = 0, sec = 0, dmin = 0, dsec = 0;
	Lv = 1;
	shootcur = 0;
	maxshootbar.setOutlineColor(sf::Color::Black);
	maxshootbar.setOutlineThickness(1);
	maxshootbar.setFillColor(sf::Color::Black);
	shootbar.setFillColor(sf::Color::Yellow);
		
	}
void slime::slimemove(sf::RenderWindow* window, sf::View* view1, float deltatime, char* gamestate)
{
	positionslime = Slime.getPosition();
	positionview = view1->getCenter();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		*gamestate = 'p';
	//hitbox
	{
		slimehitbox.setPosition(positionslime.x, positionslime.y);
	}
	//main slimemove
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
			{
				gx = -1;
				slimeface = 'w';
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				gy = 1;
				slimeface = 's';
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				gx = 1;
				slimeface = 'd';
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				gx = -1;
				slimeface = 'a';
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				slimeface = '3';
				gx = -1;
				gy = 1;
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				slimeface = '4';
				gx = 1;
				gy = 1;

			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				slimeface = '1';
				gx = 1;
				gy = -1;
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
			{
				slimeface = '2';
				gx = -1;
				gy = -1;
			}

			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
			{
				gx = 0;
				slimeface = lastlog;
			}
			else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
			{
				gy = 0;
				slimeface = lastlog;
			}
			else
			{
				lastlog = slimeface;
			}
		}
		{
			if (slimeface == 'w')
			{
				if (gy != 0)
				{
					if (positionslime.y > 85 && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
					{
						Slime.move(0, -slimespeed * deltatime);
					}
					if (positionview.y > 390 && positionslime.y < 931 && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						view1->move(0, -slimespeed * deltatime);
					}
				}
				Slime.setTexture(slimetexture[0]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == 's')
			{
				if (gx != 0)
				{
					if (positionview.y < 931 && positionslime.y>390 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						view1->move(0, slimespeed * deltatime);
					}
					if (positionslime.y < 1250 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						Slime.move(0, slimespeed * deltatime);
					}
				}
				Slime.setTexture(slimetexture[1]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == 'd')
			{
				if (gx != 0)
				{
					if (positionslime.x < 2480 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						Slime.move(slimespeed * deltatime, 0.f);
					if (positionview.x < 2020 && positionslime.x > 480 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						view1->move(slimespeed * deltatime, 0.f);
				}
				Slime.setTexture(slimetexture[2]);
				Slime.setTextureRect(sf::IntRect(56.5 * animation, 0, 56.5, 44));
			}
			else if (slimeface == 'a')
			{
				if (gx != 0)
				{
					if (positionslime.x > 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						Slime.move(-slimespeed * deltatime, 0.f);
					if (positionview.x > 480 && positionslime.x < 2020 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						view1->move(-slimespeed * deltatime, 0.f);
				}
				Slime.setTexture(slimetexture[3]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == '3')
			{
				if (gx != 0)
				{
					if (positionslime.y < 1250 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						Slime.move(0, slimespeed * deltatime / sqrt(2));
					}
					if(positionslime.x > 10&& sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						Slime.move(-slimespeed * deltatime / sqrt(2),0);
					if (positionview.y < 931 && positionslime.y>390 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						view1->move(0, slimespeed * deltatime / sqrt(2));
					}
					if(positionview.x > 480 && positionslime.x < 2020 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						view1->move(-slimespeed * deltatime / sqrt(2),0);
				}
				Slime.setTexture(slimetexture[4]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == '4')
			{
				if (gx != 0)
				{
					if ((positionslime.y < 1250 && sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
					{
						Slime.move(0, slimespeed * deltatime / sqrt(2));
					}
					if ((positionslime.x < 2480 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
						Slime.move(slimespeed * deltatime / sqrt(2),0 );
					if (positionview.y < 931 && positionslime.y>390 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						view1->move(0, slimespeed* deltatime / sqrt(2));;
					}
					if(positionview.x < 2020 && positionslime.x > 390 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						view1->move(slimespeed * deltatime / sqrt(2),0);
				}
				Slime.setTexture(slimetexture[5]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == '1')
			{
				if (gx != 0)
				{
					if ((positionslime.x < 2480 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
						Slime.move(slimespeed * deltatime / sqrt(2),0);
					if((positionslime.y > 85 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
						Slime.move(0, -slimespeed * deltatime / sqrt(2));
					if (positionview.y > 390 && positionslime.y < 931 && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						view1->move(0, -slimespeed * deltatime / sqrt(2));
					}
					if((positionview.x < 2020 && positionslime.x > 390 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
						view1->move(slimespeed * deltatime / sqrt(2),0);
				}
				Slime.setTexture(slimetexture[6]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == '2')
			{
				if (gx != 0) 
				{
					if ((positionslime.y > 85 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
					{
						Slime.move(0, -slimespeed * deltatime / sqrt(2));
					}
					if((positionslime.x > 10 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
						Slime.move(-slimespeed * deltatime / sqrt(2),0);
					if (positionview.y > 390 && positionslime.y < 931 && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						view1->move(0, -slimespeed * deltatime / sqrt(2));
					}
					if(positionview.x > 480 && positionslime.x < 2020 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						view1->move(-slimespeed * deltatime / sqrt(2),0);
				}
				Slime.setTexture(slimetexture[7]);
				Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
			else if (slimeface == '\0')
			{
			Slime.setTexture(slimetexture[8]);
			Slime.setTextureRect(sf::IntRect(55.33 * animation, 0, 55.33, 44));
			}
		}

		//animation
		totaltime += deltatime;
		if (totaltime >= swichtime)
		{
			totaltime -= swichtime;
			animation++;
			if (animation >= 6)
			{
				animation = 0;
			}
			tolonganime = 0;
		}

	}

	//aim
	if (true) {
		aim.setTexture(aimtex);
		if (slimeface == 'd')
		{
			aim.setRotation(0);
			aim.setPosition(positionslime.x + 40, positionslime.y);
		}
		else if (slimeface == 'a')
		{
			aim.setPosition(positionslime.x - 40, positionslime.y + 3.5);
			aim.setRotation(180);
		}
		else if (slimeface == 'w')
		{
			aim.setPosition(positionslime.x - 3.5, positionslime.y - 35);
			aim.setRotation(270);
		}
		else if (slimeface == 's' || slimeface == '\0')
		{
			aim.setPosition(positionslime.x + 3.5, positionslime.y + 40);
			aim.setRotation(90);
		}
		else if (slimeface == '3')
		{
			aim.setPosition(positionslime.x - 35, positionslime.y + 35);
			aim.setRotation(135);
		}
		else if (slimeface == '2')
		{
			aim.setPosition(positionslime.x - 35, positionslime.y - 25);
			aim.setRotation(225);
		}
		else if (slimeface == '1')
		{
			aim.setPosition(positionslime.x + 35, positionslime.y - 25);
			aim.setRotation(315);
		}
		else if (slimeface == '4')
		{
			aim.setPosition(positionslime.x + 35, positionslime.y + 35);
			aim.setRotation(45);
		}
	}

	//shoot
	if (true)
	{
		a += deltatime;		
		for (int i = 0; i < 5; i++)
		{
			if (a >= 0.04 * (i)) 
			{
				if (aimming == false)
				{
					aimming = true;
				}
				if (i == 0)
				{
					shoot[i].drawbullet(slimeface, deltatime, &window,positionslime,shootcooldown,positionview,numbullet,i);
				}
				else
				{
					shoot[i].drawbullet(shoot[0].k, deltatime, &window, positionslime,shootcooldown,positionview,numbullet,i);
				}
			}
			for (int i = numbullet; i < 5; i++)
			{
				shoot[i].shoot.setRadius(0);
			}
			if(!shoot[i].shoot.getGlobalBounds().intersects(slimehitbox.getGlobalBounds()))
		    	window->draw(shoot[i].shoot);
		}
	}
	//pickup
	 if (true)
	 {
		 pickup.setPosition(positionslime.x, positionslime.y);
		 pickup.setRadius(100);
	 }
	 	 
	 //immor
	 if (damageable == false)
	 {
		 t += deltatime;
		 if (t > 1.5)
		 {
			 damageable = true;
			 t = 0;
		 }
	 }

	 //Levelup
	 if (curexp >= maxexp) {
		 Lv++;
		 maxhp += 1;
		 curhp += 1;
		 if (Lv == 3)
		 {
			 spellon = true;
		 }
		 curexp -= maxexp;
		 if(Lv>10)
		 maxexp += 10;
		 else
		 {
			 maxexp += 5;
		 }
		 *gamestate = 'm';
	 }
	 
	 //Ui
	 if (true)
	 {
		 //shootbar
		 if(true) {
			 shootcur += deltatime;
			 if (shootcur > shootcooldown)
				 shootcur -= shootcooldown;
			 maxshootbar.setSize(sf::Vector2f(50, 5));
			 maxshootbar.setPosition(positionslime.x, positionslime.y + 60);
			 shootbar.setPosition(positionslime.x, positionslime.y + 60);
			 shootbar.setSize(sf::Vector2f(shootcur * 50 / shootcooldown, 5));
			 maxshootbar.setOrigin(25, 5);
			 shootbar.setOrigin(25, 5);


		 }
		 //Lv
		 
		 //time
		  curtime += deltatime;
		 if (curtime >= 1)
		 {
			 curtime -= 1;
			 sec++;
			 if (sec == 10)
			 {
				 sec -= 10;
				 dsec++;
				 if (dsec >= 6)
			     {
					 min++;
					 dsec -= 6;
					 if (min == 10)
					 {
						 dmin++;
						 min -= 10;
					 }
			     }
			 }
			 
		 }
		 //expbar
		 if (true)
		 {
			 maxexpbar.setPosition(positionview.x - 477, positionview.y - 337);
			 Expbar.setPosition(positionview.x - 477, positionview.y - 337);
			 Expbar.setSize(sf::Vector2f(curexp * 954 / maxexp, 20));
		 }
		 //hpbar
		 if (true)
		 {
			 maxhpbar.setSize(sf::Vector2f(50, 5));
			 maxhpbar.setPosition(positionslime.x,positionslime.y + 55);
			 hpbar.setPosition(positionslime.x, positionslime.y +55);
			 hpbar.setSize(sf::Vector2f(curhp * 50 / maxhp, 5));
			 maxhpbar.setOrigin(25, 5);
			 hpbar.setOrigin(25, 5);
		 }
		 //score
		 if (true)
		 {
			 		 
		 }
		 
	  }
	 
	 //spell
	 if (spellon==true)
	 {
		 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&curcooldown>=cooldown)
		 {
			 spelling = true;
			 if (spelltype == 's')
			 {
				 spell.setPosition(positionslime.x, positionslime.y);
				 spellcastbuf[0].loadFromFile("acces/sound/Ice-spell-cast-hit-657.wav");
				 spellcast.setBuffer(spellcastbuf[0]);
				 spellcast.play();

			 }
			 else if (spelltype == 't')
			 {
				 slimespeed += 150;
				 spellcastbuf[1].loadFromFile("acces/sound/Electric-lance-cast-453.wav");
				 spellcast.setBuffer(spellcastbuf[1]);
				 spellcast.play();
			 }
			 else if (spelltype == 'r')
			 {
				 slimespeed += 50;
				 spellcastbuf[2].loadFromFile("acces/sound/Heal-Sound-Effect.wav");
				 spellcast.setBuffer(spellcastbuf[2]);
				 spellcast.play();

			 }
			 curcooldown = 0;
		 }
		 if (curcooldown < cooldown&&spelling==false)
		 {
			 curcooldown += deltatime;
		 }
		 maxcooldownbar.setOutlineColor(sf::Color::Black);
		 maxcooldownbar.setOutlineThickness(1);
		 maxcooldownbar.setFillColor(sf::Color::Black);
		 if (spelltype == 's')
		 {
			 curcooldownbar.setFillColor(sf::Color::Cyan);
			 cooldown = 20;
		 }
		 else if (spelltype == 't')
		 {
			 curcooldownbar.setFillColor(sf::Color::Yellow);
			 cooldown = 20;
		 }
		 else if (spelltype == 'r')
		 {
			 curcooldownbar.setFillColor(sf::Color::Magenta);
			 cooldown = 20;
		 }

		 maxcooldownbar.setOrigin(50, 10);
		 maxcooldownbar.setPosition(positionview.x-420, positionview.y-200);
		 maxcooldownbar.setSize(sf::Vector2f(100, 20));
		 curcooldownbar.setPosition(positionview.x - 420, positionview.y - 200);
		 curcooldownbar.setOrigin(50, 10);
		 curcooldownbar.setSize(sf::Vector2f(curcooldown * 100 / cooldown, 20));
		 if (spelling==true&&spelltype == 's')
		 {
			 spell.setRadius(125);
			 spell.setTexture(&spelltxture[0], true);
			 spell.setOrigin(125, 125);
			 si += deltatime;
			 if (si > 5)
			 {
				 spelling = false;
				 si = 0;
				 spell.setRadius(0);
				 int i = rand() % 2;
				 if (i == 1)
					 spelltype = 't';
				 else
					 spelltype = 'r';
			 }
		 }
		 if (spelling == true && spelltype == 't')
		 {
			 spell.setRadius(35);
			 spelltxture[1].loadFromFile("acces/spell/speed.png");
			 spell.setTexture(&spelltxture[1], true);
			 spell.setOrigin(35, 35);
			 spell.setPosition(positionslime.x, positionslime.y);
			 si += deltatime;
			 if (si > 3)
			 {
				 spelling = false;
				 si = 0;
				 spell.setRadius(0);
				 slimespeed -= 150;
				 int i = rand() % 2;
				 if (i == 1)
					 spelltype = 's';
				 else
					 spelltype = 'r';
			 }
		 }
		 if (spelling == true && spelltype == 'r')
		 {
			 spell.setRadius(35);
			 spelltxture[2].loadFromFile("acces/spell/regen.png");
			 spell.setTexture(&spelltxture[2], true);
			 spell.setOrigin(35, 35);
			 spell.setPosition(positionslime.x, positionslime.y);
			 si += deltatime;
			 regenrate += deltatime;
			 if (regenrate > 1)
			 {
				 regenrate -= 1;
				 if (curhp < maxhp - maxhp / 5)
					 curhp += maxhp / 5;
				 else if (curhp < maxhp)
					 curhp += maxhp - curhp;
			 }
			 if (si > 3)
			 {
				 int i = rand() % 2;
				 spelling = false;
				 slimespeed -= 30;
				 si = 0;
				 spell.setRadius(0);
				 if (i == 1)
					 spelltype = 't';
				 else
					 spelltype = 's';
			 }
		 }
	 }
	 //game rule
	 if (true)
	 {

	 }
	
 }
 void slime::drawslime(sf::RenderWindow* window,char *gamestate)
 {
	 
	 //time
	 if (true)
	 {
		 timetxt.setPosition(positionview.x - 50, positionview.y - 310);
		 char timestr[50];
		 sprintf_s(timestr, "%0.f%0.f : %0.f%0.f", dmin, min, dsec, sec);
		 timetxt.setString(timestr);
	 }

	 //score
	 if (true)
	 {
		 scoretxt.setPosition(positionview.x + 310, positionview.y - 305);
		 char scorestr[50];
		 sprintf_s(scorestr, "score = %d", score);
		 scoretxt.setString(scorestr);
	 }
	 
	 //LV
	 if (true)
	 {
		
		 LVtxt.setPosition(positionview.x-480, positionview.y-310);
		 char LVstr[50];
		 if(Lv<10)
		 sprintf_s(LVstr, " LV \n  %d", Lv);
		 else
		 sprintf_s(LVstr, " LV \n %d", Lv);
		 LVtxt.setString(LVstr);
		 
	 }
	 //darw
	 {		
		 window->draw(LVtxt);
		 window->draw(Slime); 
		 window->draw(aim);
		 window->draw(maxexpbar);
		 window->draw(Expbar);
		 window->draw(maxshootbar);
		 window->draw(shootbar);
		 window->draw(maxhpbar);
		 window->draw(hpbar);
		 window->draw(timetxt);
		 window->draw(scoretxt);
		 if (spellon == true)
		 {
			 window->draw(maxcooldownbar);
			 window->draw(curcooldownbar);
		 }
	 }
 }