#ifndef FIELD_H
#define FIELD_H

// Dependencies
#include <string>
#include <SDL/SDL.h>

enum fieldState {
                FALLOW,
                PLANTED,
                GROWING,
                MATURE,
                STUBBLE,
                DEAD
               };

class Field
{
    public:
        Field();
        Field(int x, int y);
        ~Field();
        void            update();
        void            grow();
        void            setCrop(int cropID);
        int             getX();
        int             getY();
        std::string     getCrop();
        int             getCropAge();
        bool            isPlanted();
        SDL_Surface*     surface;
        fieldState      state;
        
        
        
    private:
        int             x;
        int             y;
        std::string     cropType;
        bool            planted;
        int             age;
};



#endif
