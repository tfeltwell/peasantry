#ifndef FIELD_H
#define FIELD_H

// Dependencies
#include <string>
#include <SDL/SDL.h>

enum FIELD_STATE {
    F_FALLOW,
    F_PLANTED,
    F_GROWING,
    F_MATURE,
    F_STUBBLE,
    F_DEAD
};
               
enum CROP_TYPE {
    C_GRASS,
    C_WHEAT,
    C_RYE,
    C_BARLEY
};

class Field
{
    public:
        Field();
        ~Field();
        void            update();
        void            grow();
        void            setCrop(CROP_TYPE newCrop);
        void            setState(FIELD_STATE newState);
        int             getX();
        int             getY();
        void            setXY(int x, int y);
        CROP_TYPE       getCrop();
        int             getCropAge();
        FIELD_STATE     getState();
        bool            isPlanted();
        bool            setSurface(SDL_Surface* newSurface, int sizeX, int sizeY);
        SDL_Surface*    surface;
        
    private:
        int             x;
        int             y;
        int             sizeX;
        int             sizeY;
        CROP_TYPE       cropType;
        bool            planted;
        int             age;
        FIELD_STATE      state;
};



#endif
