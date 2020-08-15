#include "Animation.h"

Animation::Animation()
{

}

Animation::~Animation()
{
    //dtor
}

void Animation::constructor(int fps, COLOR c)
{
    actual_status=0;
    cc=c;
    this->fps=fps;
    is_on=false;

    all_frames.constructor("graphics/animation.png");

}

void Animation::update()
{
    if(is_on) actual_status++;
    if(actual_status>=fps*ANIMATION_TIME/2) current_frame_of_animation=all_frames.get(cc,0);
    if(actual_status>=fps*ANIMATION_TIME)
    {
        current_frame_of_animation=all_frames.get(cc,1);
        actual_status=0;
        is_on=false;
    }
}
