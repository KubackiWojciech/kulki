#ifndef ANIMATION_H
#define ANIMATION_H

#include "Loading_Textures.h"

#define ANIMATION_TIME 0.4 //in seconds

class Animation
{
private:
    int actual_status;
    int fps;
    COLOR cc;
    Loading_Textures all_frames;
    sf::Sprite current_frame_of_animation;
    bool is_on;

public:
    Animation();
    void constructor(int fps, COLOR c);
    virtual ~Animation();

    void update();
    sf::Sprite get_frame() {return current_frame_of_animation;}
    void turn_on() {is_on=true;}

};

#endif // ANIMATION_H
