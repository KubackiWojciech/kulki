#ifndef BACK_END_H
#define BACK_END_H

#include "Loading_Textures.h"

#include "SFML/Graphics.hpp"

#include <cmath>
#include <cstdio>
#include <ctime>
#include <list>
#include <fstream>
#include <iostream> //logs
#include <cstdio> //logs
#include <windows.h> //logs

#define ARROW_X 346.0
#define ARROW_Y 596.0
#define BASIC_ROTATION -80.0
#define ARROW_X_ORIGIN 24.0
#define ARROW_Y_ORIGIN 89.0

#define ARRAY_X_SIZE 17
#define ARRAY_Y_SIZE 16

#define BALL_SPEED 6

#define BASE_POINT_X 42
#define BASE_POINT_Y 11

#define BALL_RADIUS 16.5

#define SCOREBOARD_SIZE 10
#define NAME_SIZE 20

#define GRAY_BALLS_NUMBER 4

    //======= ball's pops =======
struct point
{
    int x;
    int y;
};

struct ball
{
    point pkt;
    int live_stage;
    COLOR ball_color;
    bool is_connected_with_roof;
};

struct score
{
    //char name[NAME_SIZE];
    std::string name;
    int points;
};

enum DIRECTION
{
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
};

class Back_end
{
    Loading_Textures arrow;
    Loading_Textures actual_ball;
    Loading_Textures next_ball;
    int gray_ball_number;

    COLOR actual_ball_color;
    COLOR next_ball_color;
    float actual_ball_x_speed;
    float actual_ball_y_speed;

    bool is_ball_moving=false;
    int points;
    bool existing_colors[6];

public:
    void increase_gray_ball_number() {gray_ball_number++; Sleep(150);}
    ball balls[ARRAY_X_SIZE][ARRAY_Y_SIZE];

    Back_end();
    ~Back_end() {}

    void arrow_rotating(sf::RenderWindow&);

//get:
    sf::Sprite get_arrow() {return arrow.get();}
    sf::Sprite get_actual_ball() {return actual_ball.get(actual_ball_color);}
    sf::Sprite get_next_ball() {return next_ball.get(next_ball_color);}


    int get_points() {return points;}
    int get_gray_ball_number() {return gray_ball_number;}
    std::string get_name() {return actual_name;}

    void ball_to_throw();

    void throwing_ball(float, float);
    bool moving_ball();
    bool collision_detection();
    bool saving_ball();
    void set_color_of_all_balls();
    void update_colors_existing();
    void random_next_ball_color();
    void deleting_balls_from_closed_list();
    void are_all_balls_connected_with_roof();

    //============= ball's pops =============

private:
    std::list<ball> open;
    std::list<ball> closed;
    std::list<ball>::iterator considering_ball;
    int counter;
    std::string actual_name;

    bool is_on_map(int,int,DIRECTION);
    bool is_in_closed_or_open(int,int,DIRECTION);
    bool checking_color(int,int,DIRECTION);
    bool is_working(int,int,DIRECTION);
    void is_connected_with_roof(int);
    bool is_in_closed(int,int);
    bool is_blank(int,int,DIRECTION);
    bool can_go_this_way(int,int,DIRECTION);
    void remove_from_closed(int,int);
    void falling();
    bool is_bot_reached();
    void update_grey_balls();


    //scoreboard:

    void scoreboard_loading();

    //logs:
    void show();

public:
    std::list<score> scoreboard;

    void update_scoreboard();
    void checking_size_of_the_color(int,int);
    void name_load(char,bool);
    bool operator<(score& a) {return points < a.points;}
    void reset();
};

#endif // BACK_END_H
