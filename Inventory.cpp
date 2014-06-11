#include "Inventory.h"

Inventory::Inventory()
{
    inventorySlots.resize(INVENTORY_SLOT_MAX); // in constructor resize the inventorySlots vector to the max inventory slot count
}

Inventory::~Inventory()
{

}

int Inventory::getSize()
{
    return int(INVENTORY_SLOT_MAX);
}
