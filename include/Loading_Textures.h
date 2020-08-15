#ifndef LOADING_TEXTURES_H
#define LOADING_TEXTURES_H

#include "SFML/Graphics.hpp"
#include "SFML/window.hpp"

#include <iostream>

enum COLOR
{
    RED=1,
    PURPLE=36,
    BRIGHT_BLUE=71,
    BLUE=106,
    YELLOW=141,
    GREEN=176,
    BLANK=211
};

class Loading_Textures
{
    sf::Image   first_download_and_corrections;
    sf::Texture middleman;
    sf::Sprite  final_version;

public:
    Loading_Textures();
    ~Loading_Textures();

    void constructor(std::string);

    sf::Sprite get() {return final_version;}
    sf::Sprite get(COLOR);
    sf::Sprite get(COLOR,int);
    void set_position(float x, float y) {final_version.setPosition(x,y);}
    void set_rotate(float);
    void set_origin(float,float);
    void moving(float x,float y) {final_version.move(x,y);}

    float get_rotate() {return final_version.getRotation();}
    void get_position(float& x, float& y) {x=final_version.getPosition().x;y=final_version.getPosition().y;}


};

#endif // LOADING_TEXTURES_H
