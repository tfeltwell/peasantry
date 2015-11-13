#ifndef CHARACTER_H
#define CHARACTER_H

// Dependencies
#include <string>
#include "Inventory.h"

class Character
{
    public:
        Character();
        ~Character();
        void        update();
        int         getX();
        int         getY();
        int         getMoveAmount(int dir);
        std::string getName();
        int         getSkill(int ID);
        int         getHealth();
        void        setPos(int x, int y);
        void        setX(int change);
        void        setY(int change);
        Inventory * characterInv;
        void        printDetails();
        
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
        int         health;
        // Birthday
};

#endif
