#include "Loading_Textures.h"

Loading_Textures::Loading_Textures()
{
    //nothing
}

Loading_Textures::~Loading_Textures()
{
    //nothing
}

void Loading_Textures::constructor(std::string path)
{
    first_download_and_corrections.loadFromFile(path);
        first_download_and_corrections.createMaskFromColor(sf::Color::White);
    middleman.loadFromImage(first_download_and_corrections);
    final_version.setTexture(middleman);
}

sf::Sprite Loading_Textures::get(COLOR cc)
{
    final_version.setTextureRect(sf::IntRect(int(cc),1,34,33));
    return final_version;
}

sf::Sprite Loading_Textures::get(COLOR cc, int status)
{
    final_version.setTextureRect(sf::IntRect(int(cc),status*33,33,33));
    return final_version;
}

void Loading_Textures::set_rotate(float angle)
{
    final_version.setRotation(angle);
}

void Loading_Textures::set_origin(float x, float y)
{
    final_version.setOrigin(x,y);
}
