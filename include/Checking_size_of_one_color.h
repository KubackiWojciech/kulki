#ifndef CHECKING_SIZE_OF_ONE_COLOR_H
#define CHECKING_SIZE_OF_ONE_COLOR_H

#include "Back_end.h"

#include <list>

struct ball_data
{
    //position in array
    int x;
    int y;
};

class Checking_size_of_one_color
{
    std::list<ball_data> open_list;
    std::list<ball_data> closed;
    int strike=0;
    COLOR ball_color;
    COLOR arr[];

public:
    Checking_size_of_one_color(COLOR,int,int,Back_end);
    ~Checking_size_of_one_color();

    bool is_on_map(int,int);
    void check_all_neighbors();

};

#endif // CHECKING_SIZE_OF_ONE_COLOR_H
