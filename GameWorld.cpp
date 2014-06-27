#include <stdio.h>
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
    doTime();
    doWeather();
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

std::string GameWorld::getTimeDayStr(){
    switch(currentTimeDay){
        case DAWN:
            return "Dawn";
            break;
        case MORNING:
            return "Morning";
            break;
        case AFTERNOON:
            return "Afternoon";
            break;
        case DUSK:
            return "Dusk";
            break;
        case EVENING:
            return "Evening";
            break;
        case NIGHT:
            return "Night";
            break;
    }
}

// Private

void GameWorld::setDate(int h, int d, int m, int y){
    hour = h;
    day = d;
    month = m;
    year = y;
    checkSeason(); // Ensure we get right season
    checkTimeDay();
}

void GameWorld::doTime(){
    checkTimeDay();
    upHour();
}

void GameWorld::doWeather(){
    switch(checkSeason()){
        case WINTER:
                break;
        case SPRING:
                break;
        case SUMMER:
                break;
        case AUTUMN:
                break;
        default: ;
    }
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

void GameWorld::setTemp(bool inc){
    if(inc==true){
        temperature += 0.5;
    }
    else{
        temperature -= 0.5;
    }
}


TIMEDAY GameWorld::getTimeDay(){
    return currentTimeDay;
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

void GameWorld::checkTimeDay(){
    switch(currentSeason){
        case WINTER:
            if(0<=hour<=6){ currentTimeDay = NIGHT; }
            else if(hour==7){ currentTimeDay = DAWN; }
            else if(8<=hour<=11){ currentTimeDay = MORNING; }
            else if(12<=hour<=15){ currentTimeDay = AFTERNOON; }
            else if(hour<=16){ currentTimeDay = DUSK; }
            else if(17<=hour<=23){ currentTimeDay = EVENING; }
            break;
            
        case SPRING:
            // 0--5, 6, 7--11, 12--17, 18, 19--23 
            if(0<=hour<=5){ currentTimeDay = NIGHT; }
            else if(hour==6){ currentTimeDay = DAWN; }
            else if(7<=hour<=11){ currentTimeDay = MORNING; }
            else if(12<=hour<=17){ currentTimeDay = AFTERNOON; }
            else if(hour==18){ currentTimeDay = DUSK; }
            else if(19<=hour<=23){ currentTimeDay = NIGHT; }
            break;
            
        case SUMMER:
            // 0--4, 5, 6--11, 12--20, 21, 22--23
            if(hour==5){ currentTimeDay = DAWN; }
            else if(hour>=6 && hour<=11){ currentTimeDay = MORNING; }
            else if(hour>=12 && hour<=20){ currentTimeDay = AFTERNOON; }
            else if(hour==21){ currentTimeDay = DUSK; }
            else if(hour>=22 && hour<=23){ currentTimeDay = NIGHT; }
            break;
            
        case AUTUMN:
            // 0--5, 6, 7--11, 12--17, 18, 19--23 
            if(0<=hour<=5){ currentTimeDay = NIGHT; }
            else if(hour==6){ currentTimeDay = DAWN; }
            else if(7<=hour<=11){ currentTimeDay = MORNING; }
            else if(12<=hour<=17){ currentTimeDay = AFTERNOON; }
            else if(hour==18){ currentTimeDay = DUSK; }
            else if(19<=hour<=23){ currentTimeDay = NIGHT; }
            break;
            
        default: ;
    }
}

