#ifndef ITEM_H
#define ITEM_H

#define SPRITE_DEFAULT_X 32
#define SPRITE_DEFAULT_Y 32

#include <SDL/SDL.h>



class Item
{
    public:
        Item();
        ~Item();
        SDL_Surface*    surface;
        int             getX();
        int             getY();
        
    private:
        int         x;
        int         y;
        int         sizeX;
        int         sizeY;
};

#endif
