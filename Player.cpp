#include "Player.h"
#include <ctime>
#include <cstdlib>

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
    std::srand(time(0)); //Init random number using current time
    generateName();
    generateSkills();
}

Player::~Player(){

}

int Player::getX(){
    return x;
}

int Player::getY(){
    return y;
}

// Amount of movement in given direction
int Player::getMoveAmount(int dir){
    return moveSpeed * dir;
}


std::string Player::getName(){
    return charName;
}

int Player::getSkill(int ID){
    switch(ID){
        case 0: return strength; break;
        case 1: return intelligence; break;
        case 2: return charisma; break;
        case 3: return luck; break;
        default: return 999; break; // Trigger exception here
    }
}

void Player::generateName(){
    charName = "Patrick DuPerdinet";
}

void Player::generateSkills(){
    strength = (std::rand() % 10) + 1;
    intelligence = (std::rand() % 10) + 1;
    charisma = (std::rand() % 10) + 1;
    luck = (std::rand() % 10) + 1;
    moveSpeed = (std::rand() % 11) + 1;
}

void Player::setX(int change){
    x += change;
}

void Player::setY(int change){
    y += change;
}


