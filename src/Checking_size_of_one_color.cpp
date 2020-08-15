#include "Checking_size_of_one_color.h"

Checking_size_of_one_color::Checking_size_of_one_color(COLOR cc,int rx, int ry, Back_end i_need_only_array)
{
    ball_color=cc;
    open_list.push_front({rx,ry});
    arr=i_need_only_array.balls;
}

Checking_size_of_one_color::~Checking_size_of_one_color()
{
    std::list<ball_data>::iterator considering_ball;


    while(!open_list.empty()) //main loop
    {
        strike++;
        considering_ball=open_list.begin();
        closed.push_front({considering_ball->x,considering_ball->y});
        open_list.erase(considering_ball);
        if(considering_ball->x>0)
        {
            if
        }
    }
}

