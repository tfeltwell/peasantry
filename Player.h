#ifndef PLAYER_H
#define PLAYER_H

// Dependencies
#include <string>

class Player
{
    public:
        Player(int x, int y);
        ~Player();
        void        update();
        int         getX();
        int         getY();
        int         getMoveAmount(int dir);
        std::string getName();
        int         getSkill(int ID);
        void        setX(int change);
        void        setY(int change);
        
    private:
        void generateName();
        void generateSkills();
        int         x;
        int         y;
        std::string charName;
        int         age;
        bool        sex; // False = Male, True = Female
        int         strength;
        int         intelligence;
        int         charisma;
        int         luck;
        int         moveSpeed;
        // Birthday
};

#endif
