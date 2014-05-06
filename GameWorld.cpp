#include "GameWorld.h"

// Public

GameWorld::GameWorld(){
    
}

GameWorld::~GameWorld(){

}

void GameWorld::init(){
    setDate(0,11,6,1600);
}

void GameWorld::update(){
    checkSeason();
    upHour();
}

int GameWorld::getMonthLen(int monthID){
    switch(monthID){
        case 1: return 31; break;
        case 2: return 28; break;
        case 3: return 31; break;
        case 4: return 30; break;
        case 5: return 31; break;
        case 6: return 30; break;
        case 7: return 31; break;
        case 8: return 31; break;
        case 9: return 30; break;
        case 10: return 31; break;
        case 11: return 30; break;
        case 12: return 31; break;
        default: break;
    }
}

int GameWorld::getHour(){
    return hour;
}

int GameWorld::getDay(){
    return day;
}

int GameWorld::getMonth(){
    return month;
}

int GameWorld::getYear(){
    return year;
}

SEASON GameWorld::getSeason(){
    return currentSeason;
}

std::string GameWorld::getSeasonStr(){
    switch(currentSeason){
        case SPRING: return "Spring"; break;
        case SUMMER: return "Summer"; break;
        case AUTUMN: return "Autumn"; break;
        case WINTER: return "Winter"; break;
        default: ;
    }
}

// Private

void GameWorld::setDate(int h, int d, int m, int y){
    hour = h;
    day = d;
    month = m;
    year = y;
    checkSeason(); // Ensure we get right season
}

void GameWorld::upHour(){
    if(hour+1 >= 24){upDay();}
    else{hour++;}
}

void GameWorld::upDay(){
    if(day+1 > getMonthLen(month)){upMonth();}
    else{
        hour = 0;
        day++;
    }
}

void GameWorld::upMonth(){
    if(this->month+1 > 12){upYear();}
    else{ 
        month++;
        day = 1;
        hour = 0;
    }
}

void GameWorld::upYear(){
    year++;
    month = 1;
    day = 1;
    hour = 0;
}

bool GameWorld::checkSeason(){
    switch(month){
        case 12:
        case 1:
        case 2: return setSeason(WINTER);
                break;
        case 3:
        case 4:
        case 5: return setSeason(SPRING);
                break;
        case 6:
        case 7:
        case 8: return setSeason(SUMMER);
                break;
        case 9:
        case 10:
        case 11: return setSeason(AUTUMN);
                break;
                
        default: ;
    }
}

// Maybe refactor this so it checks before this is called?
bool GameWorld::setSeason(SEASON newSeason){
    if(newSeason!=currentSeason){
        currentSeason = newSeason;
        return true;
    }
    else{
        return false;
    }
    
}


