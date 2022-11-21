#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "slime.h"
class knight
{ 
public:	
float knightspeed;
float knighthelth;
float mainknighthelth,knightdam ;
float knightmainspeed;
float knightexp;
sf::RectangleShape knighthitbox;
sf::Sprite Knight0;
float knightscore;
sf::Vector2f knightposition;
int knightready = 0;
char knighttype = 'n';
knight(char type, float mmainknighthelth, float mmainknightspeed, float damknight, float expknight, float scoreknight, slime slime1, sf::Texture knighttxt[5]);
void setup();
void knightmove(sf::RenderWindow* window, slime slime, float slimex,float slimey,float viewx,float viewy, float deltatime, std::vector<knight*> &knight1,int numknight,int knighti);
void update(sf::RenderWindow* windwo, slime *slime1, float deltatime,char* gamestate);
private:
float totaltime = 0, switchtime = 0.3;
float knightspeedx, knightspeedy,dx,dy;
int knightframe = 0;
sf::CircleShape exp;
int speedrand=0;
sf::CircleShape hp;
int rannum = 0;
sf::Texture knightTexture[5];
bool hpdrop = false;
sf::SoundBuffer soundbuffer[3];//0=eatfood 1=knightattackslime  2=expget
sf::Sound eatfood;
bool expdrop=false;
bool moving[4]{true,true,true,true};

};