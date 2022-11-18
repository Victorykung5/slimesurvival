#include <SFML/Graphics.hpp>
#include "slime.h"
#include <fstream>
#include <SFML/Audio.hpp>
#include <iostream>
class mainmenu
{
public:
	sf::Vector2f viewpos;
	sf::RectangleShape center;
	sf::Sprite slime2;
	sf::Texture spritetex2[5];
	sf::Sprite sprite2[5];
	struct scoreboardstruck
	{
		std::string name;
		std::string scorestr;
		int scoreint;
	}scoreboard[6],temp;
	mainmenu();
	void writefile();	
	sf::String input;
	void checkhightscore(int score);
	void mainmenudraw(sf::RenderWindow* window, sf::View View1, char* gamestate, slime* slime1, float deltatime, bool* reset, sf::Event ev);
private:
	sf::Text inputtext;

	sf::Text speed, attack;
	sf::Text hp;
};
