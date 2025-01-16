#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Character/Character.h"
#include "Item/Item.h"
#include "Inventory.h"
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
	inline int GetCurrentHealth() const { return currentHealth; }
	inline int GetDamage() const { return damage; }
	inline int GetLevel() const { return level; }
	inline int GetGold() const { return gold; }
	inline int GetStress() const { return stress; }
	inline int GetSpeed() const { return speed; }
	inline map<string,Inventory>& GetItem() { return inventory; }
	inline void AddHealth(int health) { this->health += health;} //���������� ���� �����ɶ� ����� �Լ�
	inline void AddDamage(int damage) { this->damage += damage;}
	inline void AddExp(int exp) {this->exp += exp+additionalExp;}
	inline void AddStress(int stress) {this->stress += stress+additionalStress;}
	inline void AddSpeed(int speed) { this->speed += speed; }
	inline void SetMonster(Monster* mob) {this->mob = mob;}
	int FinalDamage();
	void AddGold(int gold);
	void AddItem(Item* item,int num);
	void UseItem(string name);
	void DeleteItem(string name);
	void EquipItem(string name);
	void UnEquipItem(string name);
	void Skill1();
	void Skill2();
	void Skill3();
	void Skill4();
	bool RandomProbability(int num); //�ӽ��Լ�
	void LevelUp();
	bool IsDie();
};