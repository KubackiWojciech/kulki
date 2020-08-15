#ifndef FRONT_END_H
#define FRONT_END_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "Loading_Textures.h"
#include "Animation.h"
#include "Back_end.h"

#include <string>
#include <conio.h>

#include <iostream> //logs
#include <windows.h> //logs

#define FPS 120

#define BASE_POINT_X 42
#define BASE_POINT_Y 11

class Front_end
{
    sf::RenderWindow window;
    sf::Event eve;

    Loading_Textures background;
    Loading_Textures balls;
    Loading_Textures gray_ball;
    Loading_Textures enter_your_nickname;
    Loading_Textures your_score;
    Loading_Textures top10Scores;

    sf::Font font;

    sf::Text showing_points;
    sf::Text scoreboard_text;
    sf::Text name;

    Back_end tech_stuff;

    bool game_over;
    int level;

    void show_score();

    void update_SFML_events();
    void update();
    void render();

public:
    Front_end();
    ~Front_end();
    void run();

    friend void arrow_rotating(sf::RenderWindow&);
};

#endif // FRONT_END_H
