#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
class bullet
{
public:
	sf::CircleShape shoot;
	int bulletspeed = 800;
	float a = 0;
	bool shootbol = true;
	void drawbullet(char slimeface, float deltatime, sf::RenderWindow** window, sf::Vector2f positionslime,float shootime, sf::Vector2f positionview);
	char k = '?';
private:
	
};

