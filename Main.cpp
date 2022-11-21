#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "slime.h"
#include "test.h"
#include "knight.h"
#include "game.h"
#include "mainmenu.h"
#include "SFML/Audio/Music.hpp"
#include "gamelogic.h"
int main()
{
    gamelogic logic;
	sf::Sound playing;
	sf::SoundBuffer playingbuff[3];
	playingbuff[0].loadFromFile("acces/sound/main.ogg");
	playingbuff[1].loadFromFile("acces/sound/play.ogg");
	playingbuff[2].loadFromFile("acces/sound/Sad Violin - Sound Effect1 (HD)_01.ogg");
	char gamestate = 's';
	slime slime1;
	sf::Clock deltatime1;
	sf::Image icon;
	icon.loadFromFile ("acces/logo/unnamed.png"); // File/Image/Pixel
	int numspawn = 1;
	float deltatime = 0.f;
	/////field
	sf::Sprite field;
	sf::Texture texfield;
	texfield.loadFromFile("acces/map/fullmap.png");
	field.setTexture(texfield);
	float timespawn = 0;
	float spawnrate = 5;
	float clock1min = 0;
	sf::CircleShape Test2;
	sf::Time time2;
	float clock15sec = 0;
	int numknight = 1;
	char laststate = '?';
	std::vector<knight*> knight1;
	playing.setBuffer(playingbuff[0]);
	srand(time(NULL));
	slime1.Slime.setPosition(2000, 500);
	int k = 1, a = 0, b = 0;
	float mmainknightspeed = 50, mmainknighthelth = 1.5, damknight = 1, expknight = 5, scoreknight = 5;
	mainmenu mainmenu;
	sf::View view1;
	view1.setSize(960, 680);
	view1.setCenter(2000, 500);
	playing.setLoop(true);
	playing.setVolume(3);
	bool reset = false;
	playing.play();
	float numknightin = 0;
	float debount = 0;
	slime1.setup();
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Slime Survival 2", sf::Style::Default);
	window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
	window.setKeyRepeatEnabled(true);
	//start
	while (window.isOpen())
	{
		debount += deltatime;
		deltatime = deltatime1.restart().asSeconds();
		window.setFramerateLimit(90);
		sf::Event event;
		sf::Vector2f positionview = view1.getCenter();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				
				break;
			case sf::Event::LostFocus:
				if(gamestate == 'g')
				gamestate = 'p';
			default:
				break;
			}
		}
		//game
		if (gamestate == 'g')
		{
			window.draw(field);
			if (slime1.spelling == true)
			{
				window.draw(slime1.spell);
			}
			slime1.slimemove(&window, &view1, deltatime, &gamestate);
			timespawn += deltatime;
			clock1min += deltatime;
			clock15sec += deltatime;
			numknightin += deltatime;
			if (clock1min > spawnrate)
			{
				for (int i = 0; i < numspawn; i++)
				{
					char type;
					int k = rand() % 2;
					if (k == 1)
						type = 'n';
					else
					{
						type = 'k';
					}
					knight1.push_back(new knight(type, mmainknighthelth, mmainknightspeed, damknight, expknight, scoreknight,slime1));
				}
				clock1min -= spawnrate;
			}
			if (numknightin > 90)
			{
				numspawn++;
				numknightin -= 90;
			}
			if (clock15sec > 60)
			{
				numknight++;
				mmainknighthelth += 3;
				damknight += 1;
				scoreknight += 10;
				expknight += 2;
				clock15sec -= 60;
				/*if (spawnrate > 3)
				{
					spawnrate -= 0.25;
				}*/
			}
			if (knight1.size() > 0)
			{
				for (int i = 0; i < knight1.size(); i++)
				{
					knight1[i]->knightmove(&window, slime1, slime1.positionslime.x,
						slime1.positionslime.y, slime1.positionview.x, slime1.positionview.y, deltatime, knight1, numknight, i);
				}
			}
			logic.logic(&window, view1, &slime1, knight1, deltatime, &gamestate,expknight);
			slime1.drawslime(&window, &gamestate);
			window.setView(view1);
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}
			if (slime1.curhp <= 0)
			{
				mainmenu.scoreboard[5].scoreint = slime1.score;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				gamestate = 'p';
			}
		}
		//interface
		if (true)
		{
			//start
			if (gamestate == 's' || gamestate == 'p' || gamestate == 'm' || gamestate == 'i' || gamestate == 'l' || gamestate == 'o'||gamestate=='t')
			{
				window.setView(view1);
				mainmenu.mainmenudraw(&window, view1, &gamestate, &slime1, deltatime, &reset, event);
			}
			if (laststate != gamestate)
			{
				if (gamestate == 's')
				{
					playing.setBuffer(playingbuff[0]);
					playing.play();
				}
				else if (gamestate == 'g' && (laststate != 'm' && laststate != 'p'))
				{
					playing.setBuffer(playingbuff[1]);
					playing.play();
				}
				else if (gamestate == 'o')
				{
					playing.setBuffer(playingbuff[2]);
					playing.play();
				}

			}
			if (reset == true)
			{
				knight1.clear();
				logic.exp.clear();
				logic.hp.clear();
				slime1.setup();
				slime1.Slime.setPosition(2000, 500);
				view1.setCenter(2000, 500);
				mmainknightspeed = 50, mmainknighthelth = 1.5, damknight = 1, expknight = 5, scoreknight = 5;
				spawnrate = 5;
				timespawn = 0;
				numspawn = 1;
				clock1min = 0;
				clock15sec = 0;
				reset = false;
			}
			laststate = gamestate;
			window.display();
			window.clear();
		}
	}
}

