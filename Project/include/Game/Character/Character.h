#pragma once
#include <string>
using namespace std;

class Character abstract
{
protected:
	string name;
	int health;
	int currentHealth;
	int damage;

public:
	virtual void Hit(int damage) = 0;
	virtual void Attack() = 0;
};

