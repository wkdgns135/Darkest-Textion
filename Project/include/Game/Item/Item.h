#pragma once
#include <string>
using namespace std;


// Item class
class Item {
protected:
   string name;
   int price;
   string imagePath;
public:
    virtual ~Item() {};
    virtual string GetName() const { return name; };
    inline virtual int GetPrice() const { return price; };
    virtual string GetImagePath() const { return imagePath; };
};