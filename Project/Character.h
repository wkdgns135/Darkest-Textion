#pragma once
#include <string>
using namespace std;

class Character abstract
{
protected:
	string Name;
	int Health;
	int Damage;

public:
	virtual void Hit(int Damage) = 0;
	virtual void Attack() = 0;
};

