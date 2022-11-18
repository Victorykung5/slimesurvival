#pragma once
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
#include "SFML/Audio/Music.hpp"
class gamelogic
{
public:
	gamelogic();
	std::vector<sf::CircleShape*> hp;
	std::vector<sf::CircleShape*> exp;
	void logic(sf::RenderWindow* window, sf::View view, slime *slime1, std::vector<knight*> &knight1, float deltatime, char* gamestate,float knightexp);
private:
	int rannum = 0;
	sf::Texture knightTexture[5];
	float expspeedx, expspeedy;
	sf::SoundBuffer soundbuffer[5];//0=eatfood 1=knightattackslime  2=expget
	sf::Sound eatfood[5];
	sf::Texture food[4];
	bool moving[4]{ true,true,true,true };
	bool knockbacking[4]{ true,true,true,true };
};

