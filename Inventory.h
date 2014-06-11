#ifndef INVENTORY_H
#define INVENTORY_H

#define INVENTORY_SLOT_MAX 20

#include <vector>
#include "Item.h"
#include <cstdlib> // Includes NULL

// Source: http://www.gamedev.net/topic/645730-inventory-system/ 

class Inventory
{
    struct Slot
    {
        
        Item * item;
        unsigned int count;
        
        Slot(): item(NULL), count(0){}
    };

    public:
        Inventory();
        ~Inventory();
        int     getSize();
        
    private:
        std::vector<Slot> inventorySlots; // A vector containing all the inventory slots
    
};
#endif
