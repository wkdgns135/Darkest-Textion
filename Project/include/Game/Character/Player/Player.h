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
	int stress;

public:
	Player(string name);
	Player(string name,int level,int currentHealth,int exp,int gold,vector<Item*> &inventory);
	virtual void Hit(int damage) override;
	virtual void Attack() override;
	void ShowStatus();

	inline string GetName() const { return name; }
	inline int GetHealth() const { return health; }
	inline int GetDamage() const { return damage; }
	inline int GetLevel() const { return level; }
	inline int GetGold() const { return gold; }
	inline int GetStress() const { return stress; }
	inline void AddHealth(int health) { this->health += health;; } //아이템으로 인한 변동될때 사용할 함수
	inline void AddDamage(int damage) { this->damage += damage; }
	inline void AddGold(int gold) { this->gold += gold; }
	inline void AddStress(int stress) {this->stress += stress;}
	void AddItem(Item* myItem);
	void UseItem(int num);
	void LevelUp();
	bool IsDie();
};