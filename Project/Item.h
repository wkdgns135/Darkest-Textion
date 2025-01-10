#pragma once
#include <string>
#include "Player.h"
using namespace std;

// Item class
class Item {
protected:
    string Name;

public:
    virtual ~Item() {}
    virtual string GetName() const = 0;
    virtual void Use(Player& Player) = 0;
};