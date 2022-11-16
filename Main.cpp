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
	sf::SoundBuffer playingbuff[2];
	playingbuff[0].loadFromFile("acces/sound/main.ogg");
	playingbuff[1].loadFromFile("acces/sound/play.ogg");
	char gamestate = 's';
	sf::Vector2u windowsize;
	slime slime1;
	sf::Clock deltatime1;
	int numspawn = 1;
	float deltatime = 0.f;
	int maxknight = 10;
	/////field
	sf::Sprite field;
	sf::Texture texfield;
	texfield.loadFromFile("acces/map/fullmap.png");
	field.setTexture(texfield);
	float timespawn = 0;
	float spawnrate = 15;
	float clock1min = 0;
	sf::CircleShape Test2;
	sf::Time time2;
	float clock15sec = 0;
	int numknight = 1;
	char laststate = 's';
	std::vector<knight*> knight1;
	playing.setBuffer(playingbuff[0]);
	srand(time(NULL));
	slime1.Slime.setPosition(2000, 500);
	int k = 1, a = 0, b = 0;
	float mmainknightspeed = 50, mmainknighthelth = 3, damknight = 1, expknight = 5, scoreknight = 5;
	mainmenu mainmenu;
	sf::View view1;
	view1.setSize(960, 680);
	view1.setCenter(2000, 500);
	playing.setLoop(true);
	playing.setVolume(3);
	bool reset = false;
	playing.play();
	knight1.push_back(new knight('k', mmainknighthelth, mmainknightspeed, damknight, expknight, scoreknight));
	float debount = 0;
	slime1.setup();
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Slime Survival 2", sf::Style::Default);
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
			}

		}
		//game
		if (gamestate == 'g')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			{
				slime1.curhp = 1;
			}
			window.draw(field);
			window.draw(slime1.spell);
			slime1.slimemove(&window, &view1, deltatime, &gamestate);
			timespawn += deltatime;
			clock1min += deltatime;
			clock15sec += deltatime;
			if (clock1min > 5)
			{
				for (int i = 0; i < numspawn; i++)
				{
					char type;
					int k = rand() % 2;
					if (k == 1)
						type = 'k';
					else
					{
						type = 'n';
					}
					knight1.push_back(new knight(type, mmainknighthelth, mmainknightspeed, damknight, expknight, scoreknight));
				}
				clock1min -= 5;
			}
			if (clock15sec > 60)
			{
				numspawn++;
				mmainknightspeed += 5;
				mmainknighthelth += 3;
				damknight += 1.5;
				scoreknight += 10;
				expknight += 10;
				clock15sec -= 60;
			}
			for (int i = 0; i < knight1.size(); i++)
			{
				knight1[i]->knightmove(&window, slime1, slime1.positionslime.x,
					slime1.positionslime.y, slime1.positionview.x, slime1.positionview.y, deltatime, knight1, numknight, i);

			}
			logic.logic(&window, view1, &slime1, knight1, deltatime, &gamestate);
			slime1.drawslime(&window, &gamestate);
			window.setView(view1);
			if (slime1.curhp <= 0)
			{
				mainmenu.scoreboard[5].scoreint = slime1.score;

			}
		}
		//interface
		if (true)
		{
			//start
			if (gamestate == 's' || gamestate == 'p' || gamestate == 'm' || gamestate == 'i' || gamestate == 'l' || gamestate == 'o')
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
			}
			if (reset == true)
			{
				knight1.clear();
				logic.exp.clear();
				logic.hp.clear();
				slime1.setup();
				slime1.Slime.setPosition(2000, 500);
				view1.setCenter(2000, 500);
				mmainknightspeed = 50, mmainknighthelth = 3, damknight = 1, expknight = 5, scoreknight = 5;
				timespawn = 0;
				numspawn = 1;
				clock1min = 0;
				clock15sec = 0;
				reset = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && gamestate == 'o')
			{
				reset = true;
			}
			laststate = gamestate;
			windowsize = window.getSize();
			window.display();
			window.clear();
		}
	}
}

