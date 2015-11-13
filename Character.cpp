#include "Character.h"
#include <ctime>
#include <cstdlib>

Character::Character(){
    std::srand(time(0)); //Init random number using current time
    generateName();
    generateSkills();
    health = 100;
    characterInv = new Inventory();
}

Character::~Character(){

}

void Character::setPos(int x, int y){
    this->x = x;
    this->y = y;
}

int Character::getX(){
    return x;
}

int Character::getY(){
    return y;
}

// Amount of movement in given direction
int Character::getMoveAmount(int dir){
    return moveSpeed * dir;
}


std::string Character::getName(){
    return charName;
}

int Character::getSkill(int ID){
    switch(ID){
        case 0: return strength; break;
        case 1: return intelligence; break;
        case 2: return charisma; break;
        case 3: return luck; break;
        default: return 999; break; // Trigger exception here
    }
}

int Character::getHealth(){
    return health;
}

void Character::generateName(){
    charName = "Patrick DuPerdinet";
}

void Character::generateSkills(){
    strength = (std::rand() % 10) + 1;
    intelligence = (std::rand() % 10) + 1;
    charisma = (std::rand() % 10) + 1;
    luck = (std::rand() % 10) + 1;
    moveSpeed = (std::rand() % 11) + 1;
}

void Character::setX(int change){
    x += change;
}

void Character::setY(int change){
    y += change;
}

void Character::printDetails(){
    printf("Name: %s Age: %i Sex: %i Health: %i\n",charName.c_str(),age,sex,health);
    printf("Skills: STR %i | INT %i | CHA %i | LUC %i",strength,intelligence,charisma,luck);
}


