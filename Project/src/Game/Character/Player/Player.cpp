#include <iostream>
#include <string>
#include "Character/Player/Player.h"
#include "Item/Item.h"
using namespace std;

#pragma region 생성자
Player::Player(string name)
{
	this->name = name;
	level = 1;
	health = currentHealth = 200;
	gold = 0;
	damage = 30;
	exp = 0;
}

Player::Player(string name, int level, int currentHealth, int exp, int gold, vector<Item*> &inventory) // 저장파일 불러올때 사용될 생성자
{
	this->name = name;
	this->level = level;
	this->gold = gold;
	damage = 30 + (level - 1 * levelUpDamage);
	this->currentHealth = currentHealth;;
	health = 200 + (level - 1 * levelUpHealth);
	this->exp = exp;
	this->inventory = inventory;
}
#pragma endregion 생성자

#pragma region GetSet
void Player::AddItem(Item* myItem)
{
	if(inventory.size() < 10)
	inventory.push_back(myItem);
}

#pragma endregion GetSet함수

#pragma region 이벤트함수

void Player::Hit(int damage) //캐릭터 피격시 발생할 함수
{
	if (IsDie())
	{
		currentHealth -= damage;
		IsDie();
	}
}

void Player::Attack() 	//캐릭터가 공격시 발생할 함수
{

}

bool Player::IsDie() //캐릭터 사망시 발생할 함수
{
	if (currentHealth > 0)
	{
		return true;
	}
	else
	{
		//Todo:캐릭터가 죽을시 발생할 이벤트 작성
		cout << "플레이어가 사망했습니다!" << endl;
		return false;
	}
}

void Player::ShowStatus() // 캐릭터 스테이터스 보여주는 함수
{
	//플레이어 스탯을 표시함 함수
	cout << "이름 : " << name << " || " << "레벨 : " << level << " || " << "최대체력 : " << health << " || " << "현재체력 : " << currentHealth << " || " << "공격력 : " << damage << " || " << "현재경험치 : " << exp << endl;
}

void Player::LevelUp()
{
	if (level < 10)
	{
		level++;
		AddDamage(levelUpDamage);
		AddHealth(levelUpHealth);
		currentHealth = health;
	}

}

void Player::UseItem(int num)
{
	if (num < inventory.size())
	{
		//inventory[num].Use(*this);
	}
}

#pragma endregion 이벤트함수

