#pragma once
#include <string>
using namespace std;


// Item class
class Item {
public:
    virtual ~Item() {};
    virtual string GetName() const = 0;
};