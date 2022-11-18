#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <Windows.h>
class bullet
{
public:
	sf::SoundBuffer soundbuff;
	sf::Sound piew;
	sf::CircleShape shoot;
	int bulletspeed = 600;
	float a = 0;
	bool shootbol = true;
	bullet();
	void drawbullet(char slimeface, float deltatime, sf::RenderWindow** window, sf::Vector2f positionslime,float shootime, sf::Vector2f positionview,int numbullet,int i);
	char k = '?';
private:
	
};

