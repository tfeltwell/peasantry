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
        Field(int x, int y);
        ~Field();
        void            update();
        void            grow();
        void            setCrop(CROP_TYPE newCrop);
        void            setState(FIELD_STATE newState);
        int             getX();
        int             getY();
        CROP_TYPE       getCrop();
        int             getCropAge();
        FIELD_STATE      getState();
        bool            isPlanted();
        SDL_Surface*    surface;
        
    private:
        int             x;
        int             y;
        CROP_TYPE       cropType;
        bool            planted;
        int             age;
        FIELD_STATE      state;
};



#endif
