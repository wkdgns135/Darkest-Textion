#pragma once
#include "Character.h"
#include "Item.h"

class Monster : Character{
public:
    virtual ~Monster() {}
    virtual string GetName() const = 0;
    virtual Item* DropItem() = 0; // Logic for item drop
};