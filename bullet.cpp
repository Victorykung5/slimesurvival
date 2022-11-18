#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"
#include "slime.h"
sf::Texture bullettex;
void bullet::drawbullet(char slimeface, float deltatime, sf::RenderWindow** window, sf::Vector2f positionslime,float shootime, sf::Vector2f positionview)
{
	a += deltatime;
	shoot.setOrigin(6, 3);
	shoot.setFillColor(sf::Color::Yellow);
	shoot.setOutlineColor(sf::Color::Black);
	shoot.setOutlineThickness(2);
	bullettex.loadFromFile("acces/food/B.png");
	
	if (a >= shootime &&shootbol==false)
	{
		a -= shootime;
		shootbol = true;
		shoot.setPosition(positionslime.x, positionslime.y);
		k = slimeface;
	}
	if (a <= 1.5 && shootbol == true)
	{
		shoot.setRadius(6);
		if (k == 'd')
		{
			shoot.move(bulletspeed * deltatime, 0);
		}
		else if (k == 'a')
		{
			shoot.move(-bulletspeed * deltatime, 0);
		}
		else if (k == 'w')
		{
			shoot.move(0, -bulletspeed * deltatime);
		}
		else if (k == 's' || slimeface == '\0')
		{
			shoot.move(0, bulletspeed * deltatime);
		}
		else if (k == '3')
		{
			shoot.move(-bulletspeed * deltatime/sqrt(2), bulletspeed * deltatime / sqrt(2));
		}
		else if (k == '2')
		{
			shoot.move(-bulletspeed * deltatime / sqrt(2), -bulletspeed * deltatime / sqrt(2));
		}
		else if (k == '1')
		{
			shoot.move(bulletspeed * deltatime / sqrt(2), -bulletspeed * deltatime / sqrt(2));
		}
		else if (k == '4')
		{
			shoot.move(bulletspeed * deltatime / sqrt(2), bulletspeed * deltatime / sqrt(2));
		}
	}
	if ((shootbol == true && a >=1)||shoot.getPosition().x>positionview.x+480||shoot.getPosition().x<positionview.x-480||shoot.getPosition().y>positionview.y+340||shoot.getPosition().y<positionview.y-340)
	{
		shootbol = false;
		shoot.setRadius(0);
	}
}
