#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character/Character.h"
#include "Item/Item.h"


class Player : Character {
private:
	const int levelUpDamage = 5;
	const int levelUpHealth = 20;
	vector<Item*> inventory;
	int level;
	int exp;
	int gold;

public:
	Player(string name);
	Player(string name,int level,int currentHealth,int exp,int gold,vector<Item*> &inventory);
	virtual void Hit(int damage) override;
	virtual void Attack() override;
	void ShowStatus();

	string GetName() const;
	int GetHealth() const;
	int GetDamage() const;
	int GetLevel() const;
	void AddHealth(int health); //아이템으로 인한 변동될때 사용할 함수
	void AddDamage(int damage);
	void AddGold(int gold);
	void AddItem(Item* myItem);
	void UseItem(int num);
	void LevelUp();
	bool IsDie();
};