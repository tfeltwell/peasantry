#include "Character.h"
#include "NameGenerator.h"
#include <ctime>
#include <cstdlib>

NameGenerator nameGen;

// Make a nice way to init characters with differing degrees of specificity
Character::Character(){
    std::srand(time(0)); //Init random number using current time
    sex = false;
    generateName();
    generateSkills();
    health = 100;
    characterInv = new Inventory();
}

Character::Character(bool gender){
    std::srand(time(0));
    sex = gender;
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
    std::string charName = firstName + " " + lastName;
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
    firstName = nameGen.generateFirst(sex);
    lastName = nameGen.generateLast();
    return;
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
    printf("Name: %s Age: %i Sex: %i Health: %i\n",getName().c_str(),age,sex,health);
    printf("Skills: STR %i | INT %i | CHA %i | LUC %i",strength,intelligence,charisma,luck);
}


