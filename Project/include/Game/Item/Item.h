#pragma once
#include <string>
using namespace std;


// Item class
class Item {
protected:
   string name;
   int price;
public:
    virtual ~Item() {};
    virtual string GetName() const { return name; };
    inline virtual int GetPrice() const { return price; };
};