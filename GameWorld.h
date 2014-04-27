#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// Game World header for 1600 (Sixteen Hundred) C++ port
// Author: Tom Feltwell, 2014

class GameWorld
{
    public:
        GameWorld();
        ~GameWorld(); 
        void init();   
        int hour;
        int day;
        int month;
        int year;
        void update();
    
    private:
        
        void    upHour();
        void    upDay();
        void    upMonth();
        void    upYear();
        int     getMonthLen(int monthID);

};

#endif
