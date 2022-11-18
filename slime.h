#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "bullet.h"
class slime
{  public:
	float slimespeed =90;
	int curexp=0,maxexp=5;
	int curhp = 5, maxhp = 5,numbullet=1;
	int score=0;
	bool aimming = false;
	float shootdam = 0.75;
	float curtime = 0, min = 0, sec = 0,dmin=0,dsec=0;
	int Lv = 1;
	sf::Text timetxt,scoretxt;
	sf::RectangleShape Expbar;
	sf::RectangleShape maxexpbar;
	sf::RectangleShape hpbar;
	sf::RectangleShape maxhpbar;
	sf::Texture aimtex;
	sf::Sprite Slime;
	bool damageable=true;
	sf::Sprite aim;
	sf::Vector2f positionslime;
	sf::Vector2f positionview;
	bullet shoot[10];
	char neft = '?';
	char spelltype = 't' ; //s=slow t=speed r=regen
	sf::Clock slimeclock3sec;
	sf::CircleShape pickup;
	sf::CircleShape slimehitbox;
	bool spelling= false;
	char slimeface= '\0',k='\0';
	void setup();
	float shootcooldown = 3.0;
	void slimemove(sf::RenderWindow* window,sf::View *view1,float deltatime,char* gamestate);
	void drawslime(sf::RenderWindow* window, char* gamestate);
	sf::CircleShape spell;
	float shootcur = 0;
private:
	sf::Font Txt;
	bool spellon=false;
	sf::Sound spellcast;
	sf::SoundBuffer spellcastbuf[3];
	sf::Texture speedspelltxture;
	float curcooldown=0;
	sf::RectangleShape maxcooldownbar;
	sf::RectangleShape curcooldownbar;
	sf::Texture spelltxture[3];
	float cooldown=6;
	sf::Text Level;
	sf::Text LVtxt;
	float totaltime = 0, swichtime = 0.13, t = 0;
	sf::Texture slimetexture[9];
	int animation = 0;
	int tolonganime = 0;
	int gy = 0, gx = 0;
	float a = 0;
	char lastlog = '?';
	float si = 0,regenrate=0;
	sf::RectangleShape maxshootbar;
	sf::RectangleShape shootbar;
};