#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Character/Character.h"
#include "Item/Item.h"
#include "Inventory.h"
#include "Global/ProjectEnum.h"
//#include "Character/Monster/Monster.h"

class Monster;

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
	int speed;
	int evasion;
	int criticalProbability;
	float criticalDamage;
	bool isStress;
	map<string, Inventory> inventory;
	map<string, Inventory> equipInventory;
	EAffliction myAffliction = Normal;
	Monster* mob;


public:
	Player(string name);
	virtual void Hit(int damage) override;
	virtual void Attack() override;
	void ShowStatus();

	inline string GetName() const { return name; }
	inline int GetHealth() const { return health; }
	inline int GetCurrentHealth() const { return currentHealth; }
	inline int GetDamage() const { return damage; }
	inline int GetLevel() const { return level; }
	inline int GetGold() const { return gold; }
	inline int GetStress() const { return stress; }
	inline int GetSpeed() const { return speed; }
	inline map<string,Inventory> GetItem() const { return inventory; }
	inline void AddHealth(int health) { this->health += health;} //아이템으로 인한 변동될때 사용할 함수
	void AddCurrentHealth(int health);
	inline void AddDamage(int damage) { this->damage += damage;}
	inline void AddExp(int exp) {this->exp += exp+additionalExp;}
	inline void AddStress(int stress) {this->stress += stress+additionalStress;}
	inline void AddSpeed(int speed) { this->speed += speed; }
	inline void SetMonster(Monster* mob) {this->mob = mob;}
	inline void SetAdditionalStress(int stress) { additionalStress = stress; }
	inline void SetAdditionExp(int exp) { additionalExp = exp;}
	inline int GetAdditionalStress() { return additionalStress; }
	inline int GetAdditionExp() { return additionalExp; }
	void SellItem(string name, int num);
	int FinalDamage();
	void AddGold(int gold);
	void SelectItem(string name);
	void AddItem(Item* item,int num);
	void UseItem(string name);
	void DeleteItem(string name);
	void EquipItem(string name);
	void UnEquipItem(string name);
	void Skill1();
	void Skill2();
	void Skill3();
	void Skill4();
	bool RandomProbability(int num); //임시함수
	void LevelUp();
	bool IsDie();
	void SetAttliction();
};