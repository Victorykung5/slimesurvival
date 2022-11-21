#include "mainmenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "slime.h"
#include <Windows.h>
#include <fstream>

sf::Texture slimetxt;
using namespace sf;
int i = 0;
sf::RectangleShape a[5];
float debount = 0;
sf::Sprite name;
sf::Texture nametxtt;
int rgbspeed = 1;
std::fstream score;
sf::Text non[5], nos[5];
float rplus = 0, bplus = 0, gplus = 0, pow1 = 2;
sf::Sprite crown[3];
int how = 0;
sf::Texture corwntxt[3];
mainmenu::mainmenu()
{
    score.open("acces/scoreboard.txt");
    for (int i = 0; i < 5; i++)
    {
        std::getline(score, scoreboard[i].name);
        std::getline(score, scoreboard[i].scorestr);
        scoreboard[i].scoreint = stoi(scoreboard[i].scorestr);
    }
    score.close();
    corwntxt[0].loadFromFile("acces/bg/gold.png");
    corwntxt[1].loadFromFile("acces/bg/silver.png");
    corwntxt[2].loadFromFile("acces/bg/redgold.png");
}
void mainmenu::writefile()
{
    score.open("acces/scoreboard.txt");
    score << scoreboard[0].name<<"\n"<<scoreboard[0].scoreint << "\n" << scoreboard[1].name << "\n" << scoreboard[1].scoreint << "\n" << scoreboard[2].name << "\n"
        << scoreboard[2].scoreint << "\n"<< scoreboard[3].name << "\n" << scoreboard[3].scoreint << "\n" << scoreboard[4].name << "\n" << scoreboard[4].scoreint;
    score.close();
}
void mainmenu::checkhightscore(int scoreslime)
 {
    score.open("acces/scoreboard.txt");
    for (int i = 0; i < 6; ++i) 
    {
        for (int j = i + 1; j < 6;j++) 
        {
            if (scoreboard[i].scoreint < scoreboard[j].scoreint)
            {
                temp.name = scoreboard[i].name;
                temp.scoreint = scoreboard[i].scoreint;
                temp.scorestr = scoreboard[i].scorestr;
                scoreboard[i].name = scoreboard[j].name;
                scoreboard[i].scoreint = scoreboard[j].scoreint;
                scoreboard[i].scorestr = scoreboard[j].scorestr;
                scoreboard[j].name = temp.name;
                scoreboard[j].scoreint = temp.scoreint;
                scoreboard[j].scorestr = temp.scorestr;
            }
        }
    }
    score.close();
}
void mainmenu::mainmenudraw(sf::RenderWindow* window, sf::View View1, char* gamestate, slime* slime1, float deltatime, bool* reset, sf::Event ev)
{
    //rgb
    if (true)
    {
        if (pow1 == 2)
        {
            if (rplus < 252)
                rplus += rgbspeed;
            else if (bplus < 252)
                bplus += rgbspeed;
            else if (gplus < 252)
                gplus += rgbspeed;
            else
                pow1 = 1;
        }
        else if (pow1 == 1)
        {
            if (rplus > 130)
                rplus -= rgbspeed;
            else if (bplus > 130)
                bplus -= rgbspeed;
            else if (gplus > 130)
                gplus -= rgbspeed;
            else
                pow1 = 2;
        }
    }
    sf::Font font4;
    font4.loadFromFile("Txtfont.ttf");
    sf::Sound botton;
    sf::SoundBuffer bottonbuff;
    bottonbuff.loadFromFile("acces/sound/AnyConv.com__sound_click_sound.wav");
    botton.setBuffer(bottonbuff);
    debount += deltatime;
    Font font1;
    viewpos = View1.getCenter();
    font1.loadFromFile("SunnyspellsRegular-MV9ze.otf");
    Font font2;
    font2.loadFromFile("Plaguard-ZVnjx.otf");
    Font font3;
    font3.loadFromFile("Copse-6YR9o.ttf");
    //mainmenu
    if (*gamestate == 's')
    {
        viewpos = View1.getCenter();
        sf::Sprite bg;
        sf::Texture bgtxt;
        bgtxt.loadFromFile("acces/bg/unnamed.png");
        bg.setTexture(bgtxt);
        bg.setPosition(viewpos.x - 480, viewpos.y - 340);
        Text gamename;
        gamename.setFillColor(sf::Color(50, 205, 50));
        gamename.setFont(font1);
        gamename.setOutlineColor(sf::Color(rplus, bplus, gplus));
        gamename.setOutlineThickness(10);
        gamename.setCharacterSize(130);
        gamename.setPosition(viewpos.x - 330, viewpos.y - 350);
        sf::String s;
        s = "Slime survivals 2";
        gamename.setString(s);
        //start Plaguard-ZVnjx.otf

        Text start;
        start.setFillColor(sf::Color::Green);
        start.setFont(font2);
        start.setOutlineColor(sf::Color::Black);
        start.setOutlineThickness(2);
        start.setCharacterSize(60);
        start.setPosition(viewpos.x - 90, viewpos.y - 150);
        sf::String st;
        st = "Start";
        start.setString(st);
        //leaderboard
        Text board;
        board.setFillColor(sf::Color::Green);
        board.setFont(font2);
        board.setOutlineColor(sf::Color::Black);
        board.setOutlineThickness(2);
        board.setCharacterSize(60);
        board.setPosition(viewpos.x - 200, viewpos.y - 50);
        st = "Leaderboard";
        board.setString(st);
        //exit
        Text how;
        how.setFillColor(sf::Color::Green);
        how.setFont(font2);
        how.setOutlineColor(sf::Color::Black);
        how.setOutlineThickness(4);
        how.setCharacterSize(60);
        how.setPosition(viewpos.x - 180, viewpos.y + 50);
        st = "How to play";
        how.setString(st);

        //exit
        Text exit;
        exit.setFillColor(sf::Color::Green);
        exit.setFont(font2);
        exit.setOutlineColor(sf::Color::Black);
        exit.setOutlineThickness(4);
        exit.setCharacterSize(60);
        exit.setPosition(viewpos.x - 60, viewpos.y + 150);
        st = "Exit";
        exit.setString(st);

        //exit
        Text name;
        name.setFillColor(sf::Color(rplus,gplus,bplus));
        name.setFont(font3);
        name.setOutlineColor(sf::Color::Black);
        name.setOutlineThickness(4);
        name.setCharacterSize(30);
        name.setPosition(viewpos.x - 460, viewpos.y + 300);
        st = "65010244 Thanith kongsmoot";
        name.setString(st);
        //start
        a[0].setFillColor(sf::Color::White);
        a[0].setSize(sf::Vector2f(187, 63));
        a[0].setOutlineColor(sf::Color::Black);
        a[0].setOutlineThickness(4);
        a[0].setPosition(viewpos.x - 95, viewpos.y - 143);
        //leaderboard
        a[1].setFillColor(sf::Color::White);
        a[1].setSize(sf::Vector2f(430, 63));
        a[1].setOutlineColor(sf::Color::Black);
        a[1].setOutlineThickness(4);
        a[1].setPosition(viewpos.x - 205, viewpos.y - 40);
        //how
        a[2].setFillColor(sf::Color::White);
        a[2].setSize(sf::Vector2f(390, 63));
        a[2].setOutlineColor(sf::Color::Black);
        a[2].setOutlineThickness(4);
        a[2].setPosition(viewpos.x - 184, viewpos.y + 56.5);
        //exit
        a[3].setFillColor(sf::Color::White);
        a[3].setSize(sf::Vector2f(120, 63));
        a[3].setOutlineColor(sf::Color::Black);
        a[3].setOutlineThickness(4);
        a[3].setPosition(viewpos.x - 63, viewpos.y + 156.5);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && debount > 0.25)
        {
            i++;
            if (i == 4)
                i = 0;
            botton.play();
            debount = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && debount > 0.2)
        {
            i--;
            if (i == -1)
                i = 3;
            botton.play();
            debount = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if (i == 0)
            {
                // //Sleep(100);
                *gamestate = 'i';
                i = 0;
            }
            else if (i == 1)
            {
                *gamestate = 'l';
                i = 0;
            }
            else if (i==2)
            {
                *gamestate = 't';
                Sleep(100);
                i = 0;
            }
            else if (i == 3)
                window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
        }
        window->draw(bg);
        window->draw(a[i]);
        window->draw(gamename);
        window->draw(start);
        window->draw(board);
        window->draw(how);
        window->draw(exit);
        window->draw(name);
    }
    //pause
    if (*gamestate == 'p')
    {
        sf::Text bullettxt;
        sf::Text hastetxt;
        viewpos = View1.getCenter();
        Text Pause;
        int pausepos;
        Pause.setFillColor(sf::Color(rplus,gplus,bplus));
        Pause.setFont(font2);
        Pause.setOutlineColor(sf::Color::White);
        Pause.setOutlineThickness(2);
        Pause.setCharacterSize(130);
        Pause.setPosition(viewpos.x - 208, viewpos.y - 350);
        sf::String s;
        s = "Pause";
        Pause.setString(s);
        //start Plaguard-ZVnjx.otf
        Text resume;
        resume.setFillColor(sf::Color::White);
        resume.setFont(font2);
        resume.setOutlineColor(sf::Color::Black);
        resume.setOutlineThickness(2);
        resume.setCharacterSize(60);
        resume.setPosition(viewpos.x +50, viewpos.y - 150);
        sf::String st;
        st = "Resume";
        resume.setString(st);
        //leaderboard
        Text mainmenu;
        mainmenu.setFillColor(sf::Color::White);
        mainmenu.setFont(font2);
        mainmenu.setOutlineColor(sf::Color::Black);
        mainmenu.setOutlineThickness(2);
        mainmenu.setCharacterSize(60);
        mainmenu.setPosition(viewpos.x +50, viewpos.y - 50);
        st = "Restart";
        mainmenu.setString(st);
        //exit
        Text exit;
        exit.setFillColor(sf::Color::White);
        exit.setFont(font2);
        exit.setOutlineColor(sf::Color::Black);
        exit.setOutlineThickness(2);
        exit.setCharacterSize(60);
        exit.setPosition(viewpos.x +50, viewpos.y + 50);
        st = "Exit";
        exit.setString(st);

        //start
        //a[0].setFillColor(sf::Color::Blue);
        a[0].setSize(sf::Vector2f(253, 63));
        a[0].setOutlineColor(sf::Color::White);
        a[0].setOutlineThickness(2);
        a[0].setPosition(viewpos.x +40, viewpos.y - 143);
        //leaderboard
        //a[1].setFillColor(sf::Color::Blue);
        a[1].setSize(sf::Vector2f(265, 63));
        a[1].setOutlineColor(sf::Color::White);
        a[1].setOutlineThickness(2);
        a[1].setPosition(viewpos.x +40, viewpos.y - 40);
        //exit
       // a[2].setFillColor(sf::Color::Blue);
        a[2].setSize(sf::Vector2f(135, 63));
        a[2].setOutlineColor(sf::Color::White);
        a[2].setOutlineThickness(2);
        a[2].setPosition(viewpos.x +40, viewpos.y + 56.5);

        slime1->maxhpbar.setOutlineColor(sf::Color::Black);
        slime1->maxhpbar.setOutlineThickness(1);
        slime1->maxhpbar.setFillColor(sf::Color::Red);
        slime1->maxhpbar.setOrigin(125, 40);
        slime1->maxhpbar.setPosition(viewpos.x - 260, viewpos.y + 80);
        slime1->maxhpbar.setSize(sf::Vector2f(250, 40));
        slime1->hpbar.setFillColor(sf::Color::Green);
        slime1->hpbar.setPosition(viewpos.x - 260, viewpos.y + 80);
        slime1->hpbar.setOrigin(125, 40);
        slime1->hpbar.setSize(sf::Vector2f(slime1->curhp * 250 / slime1->maxhp, 40));
        sf::Texture spritetex[5];

        spritetex[0].loadFromFile("acces/market/helth.png");
        spritetex[1].loadFromFile("acces/market/boot.png");
        spritetex[2].loadFromFile("acces/market/damage.png");
        spritetex[3].loadFromFile("acces/market/bullet3.png");
        spritetex[4].loadFromFile("acces/market/depositphotos_14691629-stock-illustration-retro-icon-of-pixel-clock.png");
        slimetxt.loadFromFile("acces/greenslime/KK.png");
        slime2.setTexture(slimetxt);
        slime2.setPosition(viewpos.x - 430, viewpos.y - 250);
        //hp
        slime1->maxhpbar.setOutlineColor(sf::Color::Black);
        slime1->maxhpbar.setOutlineThickness(1);
        slime1->maxhpbar.setFillColor(sf::Color::Red);
        slime1->maxhpbar.setOrigin(125, 40);
        slime1->maxhpbar.setPosition(viewpos.x - 260, viewpos.y + 80);
        slime1->maxhpbar.setSize(sf::Vector2f(250, 40));
        slime1->hpbar.setFillColor(sf::Color::Green);
        slime1->hpbar.setPosition(viewpos.x - 260, viewpos.y + 80);
        slime1->hpbar.setOrigin(125, 40);
        slime1->hpbar.setSize(sf::Vector2f(slime1->curhp * 250 / slime1->maxhp, 40));
        hp.setFillColor(sf::Color::White);
        hp.setFont(font1);
        hp.setOutlineColor(sf::Color::Black);
        hp.setOutlineThickness(5);
        hp.setCharacterSize(40);
        hp.setPosition(viewpos.x - 300, viewpos.y + 33);
        char hpstr[50];
        sprintf_s(hpstr, " %d / %d", slime1->curhp, slime1->maxhp);
        hp.setString(hpstr);
        sprite2[0].setTexture(spritetex[0]);
        sprite2[0].setPosition(viewpos.x - 440, viewpos.y + 38);

        slimetxt.loadFromFile("acces/greenslime/KK.png");
        slime2.setTexture(slimetxt);
        slime2.setPosition(viewpos.x - 430, viewpos.y - 250);

        //speed

        sprite2[1].setTexture(spritetex[1]);
        sprite2[1].setPosition(viewpos.x - 440, viewpos.y + 95);
        speed.setFillColor(sf::Color::White);
        speed.setFont(font1);
        speed.setOutlineColor(sf::Color::Black);
        speed.setOutlineThickness(5);
        speed.setCharacterSize(40);
        speed.setPosition(viewpos.x - 380, viewpos.y + 95);
        char speedstr[99];
        sprintf_s(speedstr, "%.1f  m/s", slime1->slimespeed);
        speed.setString(speedstr);

        //attack

        sprite2[2].setTexture(spritetex[2]);
        sprite2[2].setPosition(viewpos.x - 440, viewpos.y + 152);
        attack.setFillColor(sf::Color::White);
        attack.setFont(font1);
        attack.setOutlineColor(sf::Color::Black);
        attack.setOutlineThickness(5);
        attack.setCharacterSize(40);
        attack.setPosition(viewpos.x - 380, viewpos.y + 152);
        char attackstr[20];
        sprintf_s(attackstr, "%.2f  dam", slime1->shootdam);
        attack.setString(attackstr);

        //bullet

        sprite2[3].setTexture(spritetex[3]);
        sprite2[3].setPosition(viewpos.x - 452, viewpos.y + 205);
        bullettxt.setFillColor(sf::Color::White);
        bullettxt.setFont(font1);
        bullettxt.setOutlineColor(sf::Color::Black);
        bullettxt.setOutlineThickness(5);
        bullettxt.setCharacterSize(40);
        bullettxt.setPosition(viewpos.x - 380, viewpos.y + 210);
        char bullettxtstr[20];
        sprintf_s(bullettxtstr, "%d bullet", slime1->numbullet);
        bullettxt.setString(bullettxtstr);

        //hates
        sprite2[4].setTexture(spritetex[4]);
        sprite2[4].setPosition(viewpos.x - 445, viewpos.y + 275);
        hastetxt.setFillColor(sf::Color::White);
        hastetxt.setFont(font1);
        hastetxt.setOutlineColor(sf::Color::Black);
        hastetxt.setOutlineThickness(5);
        hastetxt.setCharacterSize(40);
        hastetxt.setPosition(viewpos.x - 380, viewpos.y + 270);
        char hastetxtstr[30];
        sprintf_s(hastetxtstr, "%.3f s/round", slime1->shootcooldown);
        hastetxt.setString(hastetxtstr);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && debount > 0.2)
        {
            i++;
            if (i == 3)
                i = 0;
            debount = 0;
            botton.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && debount > 0.2)
        {
            i--;
            if (i == -1)
                i = 2;
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && debount > 0.25)
        {
            if (i == 0)
            {
                //Sleep(100);
                *gamestate = 'g';
                i = 0;
            }
            else if (i == 1)
            {
                *reset = true;
                *gamestate = 'g';
                i = 0;
                //Sleep(100);
            }
            else if (i == 2)
            {
                *reset = true;
                *gamestate = 's';
                input.clear();
                scoreboard[5].scorestr = slime1->score;
                Sleep(300);
                i = 0;
            }
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            *gamestate = 'g';
            Sleep(200);


        }
        window->draw(slime2);
        window->draw(slime1->maxhpbar);
        window->draw(slime1->hpbar);
        window->draw(hp);
        window->draw(a[i]);
        window->draw(Pause);
        window->draw(resume);
        window->draw(mainmenu);
        window->draw(exit);
        window->draw(sprite2[0]);
        window->draw(sprite2[1]);
        window->draw(sprite2[2]);
        window->draw(sprite2[3]);
        window->draw(sprite2[4]);
        window->draw(speed);
        window->draw(attack);
        window->draw(bullettxt);
        window->draw(hastetxt);
    }
    //market
    if (*gamestate == 'm')
    {
        sf::Text bullettxt;
        sf::Text hastetxt;
        viewpos = View1.getCenter();
        Text Pause;
        int pausepos;
        Pause.setFillColor(sf::Color::Yellow);
        Pause.setFont(font2);
        Pause.setOutlineColor(sf::Color::Black);
        Pause.setOutlineThickness(2);
        Pause.setCharacterSize(130);
        Pause.setPosition(viewpos.x - 350, viewpos.y - 350);
        sf::String s;
        s = "Level UP!!!";
        Pause.setString(s);
        //start Plaguard-ZVnjx.otf
        Text resume;
        resume.setFillColor(sf::Color::White);
        resume.setFont(font2);
        resume.setOutlineColor(sf::Color::Black);
        resume.setOutlineThickness(2);
        resume.setCharacterSize(50);
        resume.setPosition(viewpos.x -20, viewpos.y - 150);
        sf::String st;
        st = "UPgrade HP";
        resume.setString(st);
        //leaderboard 
        Text mainmenu;
        mainmenu.setFillColor(sf::Color::White);
        mainmenu.setFont(font2);
        mainmenu.setOutlineColor(sf::Color::Black);
        mainmenu.setOutlineThickness(2);
        mainmenu.setCharacterSize(50);
        mainmenu.setPosition(viewpos.x-20, viewpos.y - 50);
        st = "UPgrade Speed";
        mainmenu.setString(st);
        //exit
        Text exit;
        exit.setFillColor(sf::Color::White);
        exit.setFont(font2);
        exit.setOutlineColor(sf::Color::Black);
        exit.setOutlineThickness(2);
        exit.setCharacterSize(50);
        exit.setPosition(viewpos.x - 20, viewpos.y + 50);
        st = "UPgrade damage";
        exit.setString(st);
        //bullet
        Text bullet;
        bullet.setFillColor(sf::Color::White);
        bullet.setFont(font2);
        bullet.setOutlineColor(sf::Color::Black);
        bullet.setOutlineThickness(2);
        bullet.setCharacterSize(50);
        bullet.setPosition(viewpos.x - 20, viewpos.y+150);
        st = "UPgrade Bullet";
        bullet.setString(st);
        //haste
        Text haste;
        haste.setFillColor(sf::Color::White);
        haste.setFont(font2);
        haste.setOutlineColor(sf::Color::Black);
        haste.setOutlineThickness(2);
        haste.setCharacterSize(50);
        haste.setPosition(viewpos.x - 20, viewpos.y + 250);
        st = "UPgrade Haste";
        haste.setString(st);
        Text max5;
        max5.setFillColor(sf::Color::White);
        max5.setFont(font2);
        max5.setOutlineColor(sf::Color::Black);
        max5.setOutlineThickness(2);
        max5.setCharacterSize(15);
        max5.setPosition(viewpos.x +410, viewpos.y + 180);
        st = "(max 5)";
        max5.setString(st);
        //start
        a[0].setFillColor(sf::Color::Blue);
        a[0].setSize(sf::Vector2f(300, 53));
        a[0].setOutlineColor(sf::Color::White);
        a[0].setOutlineThickness(2);
        a[0].setPosition(viewpos.x -25, viewpos.y - 143);
        //leaderboard
        a[1].setFillColor(sf::Color::Blue);
        a[1].setSize(sf::Vector2f(390, 53));
        a[1].setOutlineColor(sf::Color::White);
        a[1].setOutlineThickness(2);
        a[1].setPosition(viewpos.x - 25, viewpos.y - 45);
        //exit
        a[2].setFillColor(sf::Color::Blue);
        a[2].setSize(sf::Vector2f(435, 53));
        a[2].setOutlineColor(sf::Color::White);
        a[2].setOutlineThickness(2);
        a[2].setPosition(viewpos.x - 25, viewpos.y + 56.5);
        //exit
        if (slime1->numbullet < 5)
            a[3].setFillColor(sf::Color::Blue);
        else
            a[3].setFillColor(sf::Color::Red);
        a[3].setSize(sf::Vector2f(425, 53));
        a[3].setOutlineColor(sf::Color::White);
        a[3].setOutlineThickness(2);
        a[3].setPosition(viewpos.x - 25, viewpos.y + 155.5);
        //exit
        if (slime1->shootcooldown >1.25)
            a[4].setFillColor(sf::Color::Blue);
        else
            a[4].setFillColor(sf::Color::Red);
        a[4].setSize(sf::Vector2f(400, 53));
        a[4].setOutlineColor(sf::Color::White);
        a[4].setOutlineThickness(2);
        a[4].setPosition(viewpos.x - 25, viewpos.y + 255.5);
        sf::Texture spritetex[5];
        sf::Sprite sprite[5];
        spritetex[0].loadFromFile("acces/market/helth.png");
        spritetex[1].loadFromFile("acces/market/boot.png");
        spritetex[2].loadFromFile("acces/market/damage.png");
        spritetex[3].loadFromFile("acces/market/bullet3.png");
        spritetex[4].loadFromFile("acces/market/depositphotos_14691629-stock-illustration-retro-icon-of-pixel-clock.png");
        sprite[0].setTexture(spritetex[0]);
        sprite[0].setPosition(viewpos.x -  100, viewpos.y - 143);
        sprite[1].setPosition(viewpos.x - 100, viewpos.y - 45);
        sprite[1].setTexture(spritetex[1]);
        sprite[2].setPosition(viewpos.x - 100, viewpos.y + 56.5);
        sprite[2].setTexture(spritetex[2]);
        sprite[3].setPosition(viewpos.x - 110, viewpos.y + 147.5);
        sprite[3].setTexture(spritetex[3]);
        sprite[4].setPosition(viewpos.x -100, viewpos.y + 260);
        sprite[4].setTexture(spritetex[4]);
        //Ui
        if (true) 
        {
            slimetxt.loadFromFile("acces/greenslime/KK.png");
            slime2.setTexture(slimetxt);
            slime2.setPosition(viewpos.x - 450, viewpos.y - 250);
            //hp
            {
                slime1->maxhpbar.setOutlineColor(sf::Color::Black);
                slime1->maxhpbar.setOutlineThickness(1);
                slime1->maxhpbar.setFillColor(sf::Color::Red);
                slime1->maxhpbar.setOrigin(125, 40);
                slime1->maxhpbar.setPosition(viewpos.x - 280, viewpos.y + 80);
                slime1->maxhpbar.setSize(sf::Vector2f(250, 40));
                slime1->hpbar.setFillColor(sf::Color::Green);
                slime1->hpbar.setPosition(viewpos.x - 280, viewpos.y + 80);
                slime1->hpbar.setOrigin(125, 40);
                slime1->hpbar.setSize(sf::Vector2f(slime1->curhp * 250 / slime1->maxhp, 40));
                hp.setFillColor(sf::Color::White);
                hp.setFont(font1);
                hp.setOutlineColor(sf::Color::Black);
                hp.setOutlineThickness(5);
                hp.setCharacterSize(40);
                hp.setPosition(viewpos.x - 320, viewpos.y + 33);
                char hpstr[50];
                sprintf_s(hpstr, " %d / %d", slime1->curhp, slime1->maxhp);
                hp.setString(hpstr);
                sprite2[0].setTexture(spritetex[0]);
                sprite2[0].setPosition(viewpos.x - 460, viewpos.y +38);
            }
            //speed
            {
                sprite2[1].setTexture(spritetex[1]);
                sprite2[1].setPosition(viewpos.x - 460, viewpos.y + 95);
                speed.setFillColor(sf::Color::White);
                speed.setFont(font1);
                speed.setOutlineColor(sf::Color::Black);
                speed.setOutlineThickness(5);
                speed.setCharacterSize(40);
                speed.setPosition(viewpos.x - 400, viewpos.y + 95);
                char speedstr[99];
                sprintf_s(speedstr, "%.1f  m/s", slime1->slimespeed);
                speed.setString(speedstr);
            }
            //attack
            {
                sprite2[2].setTexture(spritetex[2]);
                sprite2[2].setPosition(viewpos.x - 460, viewpos.y + 152);
                attack.setFillColor(sf::Color::White);
                attack.setFont(font1);
                attack.setOutlineColor(sf::Color::Black);
                attack.setOutlineThickness(5);
                attack.setCharacterSize(40);
                attack.setPosition(viewpos.x - 400, viewpos.y + 152);
                char attackstr[99];
                sprintf_s(attackstr, "%.2f  dam", slime1->shootdam);
                attack.setString(attackstr);
            }
            //bullet
            {
                sprite2[3].setTexture(spritetex[3]);
                sprite2[3].setPosition(viewpos.x - 472, viewpos.y + 205);
                bullettxt.setFillColor(sf::Color::White);
                bullettxt.setFont(font1);
                bullettxt.setOutlineColor(sf::Color::Black);
                bullettxt.setOutlineThickness(5);
                bullettxt.setCharacterSize(40);
                bullettxt.setPosition(viewpos.x - 400, viewpos.y + 210);
                char bullettxtstr[99];
                sprintf_s(bullettxtstr, "%d bullet", slime1->numbullet);
                bullettxt.setString(bullettxtstr);
            }
            //hates
            sprite2[4].setTexture(spritetex[4]);
            sprite2[4].setPosition(viewpos.x - 465, viewpos.y + 275);
            hastetxt.setFillColor(sf::Color::White);
            hastetxt.setFont(font1);
            hastetxt.setOutlineColor(sf::Color::Black);
            hastetxt.setOutlineThickness(5);
            hastetxt.setCharacterSize(40);
            hastetxt.setPosition(viewpos.x - 400, viewpos.y + 270);
            char hastetxtstr[30];
            sprintf_s(hastetxtstr, "%.3f s/round", slime1->shootcooldown);
            hastetxt.setString(hastetxtstr);
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && debount > 0.2)
        {
            i++;
            if (i == 5)
                i = 0;
            debount = 0;
            botton.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && debount > 0.2)
        {
            i--;
            if (i == -1)
               i = 4;
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if (i == 0)
            {
                slime1->maxhp += 5;
                if (slime1->curhp <= slime1->maxhp - 5)
                    slime1->curhp += 5;
                else
                    slime1->curhp += slime1->maxhp - slime1->curhp;
                i = 0;
            }
            else if (i == 1)
                slime1->slimespeed += 10;
            else if (i == 2)
            {
                slime1->shootdam += 0.5;
                i = 0;
            }
            if ((i != 3&&i!=4) || (i == 3 && slime1->numbullet < 5)|| (i == 4 && slime1->shootcooldown > 1.25))
            {
                if (i == 3 && slime1->numbullet < 5)
                    slime1->numbullet+=1;
                if (i == 4 && slime1->shootcooldown > 1.25)
                {
                    for (int i = 0; i < 5; i++)

                    {
                        slime1->shoot[i].a = 0 - 0.04 * i;
                    }
                    slime1->shootcur = 0;
                    slime1->shootcooldown -= 0.125;
                }
                i = 0;
                *gamestate = 'g';
            }
        }
        //ui
        window->draw(a[i]);
        window->draw(slime2);
        window->draw(Pause);
        window->draw(resume);
        window->draw(slime1->maxhpbar);
        window->draw(slime1->hpbar);
        window->draw(hp);
        window->draw(mainmenu);
        window->draw(bullet);
        window->draw(haste);
        window->draw(max5);
        window->draw(exit);
        window->draw(sprite[0]);
        window->draw(sprite[1]);
        window->draw(sprite[2]);
        window->draw(sprite[3]);
        window->draw(sprite[4]);
        window->draw(sprite2[0]);
        window->draw(sprite2[1]);
        window->draw(sprite2[2]);
        window->draw(sprite2[3]);
        window->draw(sprite2[4]);
        window->draw(speed);
        window->draw(attack);
        window->draw(bullettxt);
        window->draw(hastetxt);       
                                                                                              
    }  //input 
    //input
    if(*gamestate == 'i')
    {
        nametxtt.loadFromFile("acces/map/wooden-game-ui-vector-8957695.png");
        name.setTexture(nametxtt);
        name.setOrigin(300, 243);
        name.setPosition(viewpos.x, viewpos.y);
        {
            if (ev.type==sf::Event::TextEntered && debount > 0.2)
            {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)&&debount > 0.05&&input.getSize()>0)
                input.erase(input.getSize() - 1);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && debount > 0.05 && input.getSize() > 0)
            {
                //Sleep(100);
                scoreboard[5].name = input;
                *gamestate = 'g';
            }
            else if(ev.text.unicode>33&&ev.text.unicode<122&&input.getSize()<10)
            input +=ev.text.unicode;
            debount = 0;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Sleep(150);
            *gamestate = 's';
        }
        sf::Sprite bg;
        sf::Texture bgtxt;
        bgtxt.loadFromFile("acces/bg/unnamed.png");
        bg.setTexture(bgtxt);
        bg.setPosition(viewpos.x - 480, viewpos.y - 340);
        window->draw(bg);
        window->draw(name);
        inputtext.setString(input);
        inputtext.setPosition(name.getPosition().x-165, name.getPosition().y-45);
        inputtext.setFont(font3);
        inputtext.setCharacterSize(43);
        inputtext.setFillColor(sf::Color(rplus,gplus,bplus));
        inputtext.setOutlineColor(sf::Color(sf::Color::Black));
        inputtext.setOutlineThickness(2);
        window->draw(inputtext);
    }
    //scoreboard
    if(*gamestate=='l')
    {
        sf::Text Leaderboard;
        Leaderboard.setFont(font3);
        Leaderboard.setFillColor(sf::Color(rplus, gplus, bplus));
        Leaderboard.setCharacterSize(100); sf::Sprite bg;
        sf::String Leaderboards;
        Leaderboards = "Leader Board";
        Leaderboard.setString(Leaderboards);
        Leaderboard.setOutlineColor(sf::Color::White);
        Leaderboard.setOutlineThickness(2);
        Leaderboard.setPosition(viewpos.x - 270, viewpos.y - 320);
        //no1
        for (int i = 0; i < 5; i++)
        {
            non[i].setFont(font4);
            non[i].setFillColor(sf::Color(sf::Color::Black));
            non[i].setCharacterSize(50);
            non[i].setOutlineColor(sf::Color(bplus, gplus, rplus));
            non[i].setOutlineThickness(2);
            char no1cn[20];
            sprintf_s(no1cn, "%s", scoreboard[i].name);
            non[i].setString(no1cn);
            nos[i].setFont(font4);
            nos[i].setFillColor(sf::Color(sf::Color::Black));
            nos[i].setCharacterSize(50);
            nos[i].setOutlineColor(sf::Color(bplus, gplus, rplus));
            nos[i].setOutlineThickness(2);
            char no1cs[20];
            sprintf_s(no1cs, "%d", scoreboard[i].scoreint);
            nos[i].setString(no1cs);
            non[i].setPosition(viewpos.x - 250, viewpos.y - 100 + 70 * i);
            nos[i].setPosition(viewpos.x +130, viewpos.y - 100 + 70 * i);
        }
        sf::Text namescore;
        namescore.setFont(font4);
        namescore.setFillColor(sf::Color(sf::Color::White));
        namescore.setCharacterSize(30); 
       
        Leaderboards = "Name";
        namescore.setString(Leaderboards);
        namescore.setOutlineColor(sf::Color::White);
        namescore.setOutlineThickness(1);
        namescore.setPosition(viewpos.x - 250, viewpos.y - 170);

        sf::Text scorescore;
        scorescore.setFont(font4);
        scorescore.setFillColor(sf::Color(sf::Color::White));
        scorescore.setCharacterSize(30);
        Leaderboards = "Score";
        scorescore.setString(Leaderboards);
        scorescore.setOutlineColor(sf::Color::White);
        scorescore.setOutlineThickness(1);
        scorescore.setPosition(viewpos.x + 130, viewpos.y - 170);
       
        crown[0].setTexture(corwntxt[0]);
        crown[0].setPosition(viewpos.x -310, viewpos.y - 100);
        
        crown[1].setTexture(corwntxt[1]);
        crown[1].setPosition(viewpos.x - 305, viewpos.y  -15);

        crown[2].setTexture(corwntxt[2]);
        crown[2].setPosition(viewpos.x - 300, viewpos.y + 60);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Sleep(200);
            *gamestate = 's';
        }
        window->draw(namescore);
        window->draw(scorescore);
        window->draw(Leaderboard);
        for (int i = 0; i < 3; i++)
        {
            window->draw(crown[i]);
        }
        for (int i = 0; i < 5; i++)
        {
            window->draw(nos[i]);
            window->draw(non[i]);
        }
    }
    //gameover
    if (*gamestate == 'o')
    {
        sf::Font font1;
        if (!font1.loadFromFile("SunnyspellsRegular-MV9ze.otf"))
        {
            std::cout << "error!!";
        }
        sf::Text gameover;
        gameover.setFillColor(sf::Color::Red);//(50, 205, 50)
        gameover.setFont(font1);
        gameover.setOutlineColor(sf::Color::White);
        gameover.setOutlineThickness(2);
        gameover.setCharacterSize(150);
        gameover.setPosition(viewpos.x - 300, viewpos.y - 330);
        sf::String s;
        s = "Game Over!!!";
        gameover.setString(s);
        sf::Text score;
        score.setFont(font1);
        score.setFillColor(sf::Color(rplus,gplus,bplus));//(50, 205, 50)
        score.setFont(font4);
        score.setOutlineColor(sf::Color::White);
        score.setOutlineThickness(2);
        score.setCharacterSize(60);
        score.setPosition(viewpos.x-200, viewpos.y-140);
        char scorest[50];
        sprintf_s(scorest, "Your Score = %d", slime1->score);
        score.setString(scorest);

        sf::Text playagain;
        playagain.setFillColor(sf::Color::Red);//(50, 205, 50)
        playagain.setFont(font4);
        playagain.setOutlineColor(sf::Color::White);
        playagain.setOutlineThickness(2);
        playagain.setCharacterSize(60);
        playagain.setPosition(viewpos.x - 130, viewpos.y - 20);
        s = "Play Again";
        playagain.setString(s);

        sf::Text Mainmenu;
        Mainmenu.setFillColor(sf::Color::Red);//(50, 205, 50)
        Mainmenu.setFont(font4);
        Mainmenu.setOutlineColor(sf::Color::White);
        Mainmenu.setOutlineThickness(2);
        Mainmenu.setCharacterSize(60);
        Mainmenu.setPosition(viewpos.x - 130, viewpos.y + 70);
        s = "Mainmenu";
        Mainmenu.setString(s);

        sf::Text Exit;
        Exit.setFillColor(sf::Color::Red);//(50, 205, 50)
        Exit.setFont(font4);
        Exit.setOutlineColor(sf::Color::White);
        Exit.setOutlineThickness(2);
        Exit.setCharacterSize(60);
        Exit.setPosition(viewpos.x - 50, viewpos.y + 160);
        s = "Exit";
        Exit.setString(s);

        //start
        a[0].setFillColor(sf::Color::Blue);
        a[0].setSize(sf::Vector2f(300, 72));
        a[0].setOutlineColor(sf::Color::White);
        a[0].setOutlineThickness(2);
        a[0].setPosition(viewpos.x - 135, viewpos.y -10);
        //leaderboard
        a[1].setFillColor(sf::Color::Blue);
        a[1].setSize(sf::Vector2f(300, 72));
        a[1].setOutlineColor(sf::Color::White);
        a[1].setOutlineThickness(2);
        a[1].setPosition(viewpos.x - 135, viewpos.y + 80);
        //exit
        a[2].setFillColor(sf::Color::Blue);
        a[2].setSize(sf::Vector2f(120, 60));
        a[2].setOutlineColor(sf::Color::White);
        a[2].setOutlineThickness(2);
        a[2].setPosition(viewpos.x - 55, viewpos.y +170);
        checkhightscore(slime1->score);
        writefile();

        window->draw(a[i]);
        window->draw(gameover);
        window->draw(score);
        window->draw(playagain);
        window->draw(Mainmenu);
        window->draw(Exit);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && debount > 0.2)
        {
            i++;
            if (i == 3)
                i = 0;
            debount = 0;
            botton.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && debount > 0.2)
        {
            i--;
            if (i == -1)
                i = 2;
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && debount > 0.25)
        {
            if (i == 0)
            {
                //Sleep(100);
                *gamestate = 'g';
                *reset = true;
                i = 0;
            }
            else if (i == 1)
            {
                *reset = true;
                *gamestate = 's';
                input.clear();
                i = 0;
                Sleep(250);
            }
            else if (i == 2)
            {
                window->close();
            }
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window->close();
        }
              
    }
    //howtoplay
    if (*gamestate == 't') {
        sf::Sprite howtoplay;
        sf::Texture howtxt[2];
        howtxt[0].loadFromFile("acces/tt/11.png");
        howtxt[1].loadFromFile("acces/tt/12.png");
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && debount > 0.2)
        {
            how++;
            if (how == 2)
                how = 0;
            debount = 0;
            Sleep(100);
            botton.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && debount > 0.2)
        {
            how--;
            if (how == -1)
                how = 1;
            Sleep(100);
            debount = 0;
            botton.play();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            *gamestate = 's';
            Sleep(200);
        }
        if (how == 0)
        {
            howtoplay.setTexture(howtxt[0]);
            howtoplay.setPosition(viewpos.x - 480, viewpos.y - 340);
        }
        if (how == 1)
        {
            howtoplay.setTexture(howtxt[1]);
            howtoplay.setPosition(viewpos.x - 480, viewpos.y - 340);
        }
        window->draw(howtoplay);
    }
}
