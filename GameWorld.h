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

enum TIMEDAY {
    DAWN,
    MORNING,
    AFTERNOON,
    DUSK,
    EVENING,
    NIGHT
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
        TIMEDAY         getTimeDay();       // Time of day
        std::string     getSeasonStr();
        std::string     getTimeDayStr();
        
    
    private:
        // *** Members *** //
        int     hour;
        int     day;
        int     month;
        int     year;
        SEASON  currentSeason;
        float   temperature;
        TIMEDAY currentTimeDay;
        
        // *** Methods *** //
        void    setDate(int h, int d, int m, int y); // Only used at init
        // System control methods
        void    doTime();
        void    doWeather();
        // Setters
        bool    setSeason(SEASON newSeason);
        void    setTemp(bool inc);
        // Time stuff
        void    upHour();
        void    upDay();
        void    upMonth();
        void    upYear();
        // Checkers
        bool    checkSeason();
        void    checkTimeDay();
};

#endif
