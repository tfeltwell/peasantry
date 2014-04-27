#include "GameWorld.h"

GameWorld::GameWorld(){
    
}

GameWorld::~GameWorld(){

}

void GameWorld::init(){
    hour = 0;
    day = 11;
    month = 2;
    year = 1600;
}

void GameWorld::update(){
    upHour();
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
