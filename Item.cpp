#include "Item.h"

Item::Item()
{
    surface = NULL;
    x = y = 50;
    sizeX = SPRITE_DEFAULT_X;
    sizeY = SPRITE_DEFAULT_Y;
}

Item::~Item()
{

}

int Item::getX()
{
    return x;
}

int Item::getY()
{
    return y;
}

