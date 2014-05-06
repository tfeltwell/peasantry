#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <string>

// Game World header for 1600 (Sixteen Hundred) C++ port
// Author: Tom Feltwell, 2014

// Feature request: Look up the day (Tues...) accurately to date

enum SEASON {
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER
};
    

class GameWorld
{
    public:
        GameWorld();
        ~GameWorld(); 
        void            init();   
        void            update();
        int             getMonthLen(int monthID);
        int             getHour();
        int             getDay();
        int             getMonth();
        int             getYear();
        SEASON          getSeason();        // Current season
        std::string     getSeasonStr();
        
    
    private:
        int     hour;
        int     day;
        int     month;
        int     year;
        SEASON  currentSeason;
        
        void    setDate(int h, int d, int m, int y); // Only used at init
        void    upHour();
        void    upDay();
        void    upMonth();
        void    upYear();
        bool    checkSeason();
        bool    setSeason(SEASON newSeason);
        

};

#endif
