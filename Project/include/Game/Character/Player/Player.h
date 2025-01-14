#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Character/Character.h"
#include "Item/Item.h"
#include "Inventory.h"
#include "Character/Monster/Monster.h"


class Player : Character {
private:
	const int levelUpDamage = 5;
	const int levelUpHealth = 20;
	int level;
	int exp;
	int additionalExp;
	int additionalStress;
	int gold;
	int stress;
	map<string, Inventory> inventory;
	map<string, Inventory> equipInventory;
	Monster* mob;

public:
	Player(string name);
	//Player(string name,int level,int currentHealth,int exp,int gold,int stress,vector<Item*> &inventory);
	virtual void Hit(int damage) override;
	virtual void Attack() override;
	void ShowStatus();

	inline string GetName() const { return name; }
	inline int GetHealth() const { return health; }
	inline int GetDamage() const { return damage; }
	inline int GetLevel() const { return level; }
	inline int GetGold() const { return gold; }
	inline int GetStress() const { return stress; }
	inline map<string,Inventory> GetItem() const { return inventory; }
	inline void AddHealth(int health) { this->health += health;; } //아이템으로 인한 변동될때 사용할 함수
	inline void AddDamage(int damage) { this->damage += damage; }
	inline void AddExp(int exp) { this->exp += exp+additionalExp; };
	inline void AddStress(int stress) {this->stress += stress+additionalStress;}
	inline void SetMonster(Monster* mob) { this->mob = mob; }
	void AddGold(int gold);
	void AddItem(Item* item,int num);
	void UseItem(string name);
	void DeleteItem(string name);
	void EquipItem(string name);
	void UnEquipItem(string name);
	void LevelUp();
	bool IsDie();
};