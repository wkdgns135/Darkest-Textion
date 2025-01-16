#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Character/Player/Player.h"
#include "Item/Item.h"
#include "Item/Consumable/Consumable.h"
#include "Item/Artifact/Artifact.h"
#include "Character/Monster/Monster.h"
#include "Utility.h"
#include "Global/ProjectEnum.h"

using namespace std;

#pragma region 생성자
Player::Player(string name)
{
	mob = nullptr;
	this->name = name;
	additionalExp = 0;
	additionalStress = 0;
	level = 1;
	isStress = false;
	health = currentHealth = 200;
	criticalProbability = 10;
	criticalDamage = 1.5f;
	evasion = 10;
	gold = 0;
	damage = 30;
	speed = 5;
	exp = 0;
	stress = 0;
}

#pragma endregion 생성자

#pragma region GetSet
void Player::AddItem(Item* item, int num)
{
	if (inventory.size() < 10)
	{
		// inventory map에 item.name 이 키값으로 존재하면 count값만 증가시키고 없으면 새로 추가해준다
		if (inventory.find(item->GetName()) != inventory.end()) //아이템의 이름으로 키가 존재할때
		{
			inventory[item->GetName()].AddCount(num);
		}
		else //키가 존재하지 않을때
		{
			Inventory inven(item, num);
			inventory.insert({ item->GetName(),inven });
		}
	}
	else
	{

	}
}
void Player::AddCurrentHealth(int health)
{
	if(currentHealth < this->health)
	{
		currentHealth += health;
		if (currentHealth > this->health)
		{
			currentHealth = health;
		}
	}
}

void Player::AddGold(int gold) 
{
	if (gold + this->gold >= 0) {
		this->gold += gold;
	}
}

#pragma endregion GetSet함수

#pragma region 이벤트함수

void Player::Hit(int damage) //캐릭터 피격시 발생할 함수
{
	if (IsDie())
	{
		if (GetRandomValue(0, 100) <= 10)
		{
			cout << "회피 성공!!" << endl;
		}
		else 
		{
			currentHealth -= damage;
			IsDie();
		}
	}
	SetAttliction();
}

void Player::Attack()
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

void Player::UseItem(string name)
{
	if (inventory.find(name) != inventory.end())
	{
		if (typeid(inventory[name].GetItem()) == typeid(Consumable)) //아이템이 사용가능한 아이템일때
		{
			static_cast<Consumable*>(inventory[name].GetItem())->Use(*this);
			inventory[name].AddCount(-1);
			if (inventory[name].GetCount() == 0)
			{
				DeleteItem(name);
			}
		}
	}
}

void Player::EquipItem(string name) //인벤토리에서 아이템을 장착
{
	if (equipInventory.size() < 2) {
		if (typeid(inventory[name].GetItem()) == typeid(Artifact))
		{
			// 아이템의 효과 사용하기
			equipInventory.insert({name,inventory[name]});
			static_cast<Artifact*>(equipInventory[name].GetItem())->Attach(*this);
			inventory.erase(name);
		}
	}
}

void Player::UnEquipItem(string name) //아이템을 장착 해제해서 다시 인벤토리로
{
	inventory.insert({ name,equipInventory[name] });
	static_cast<Artifact*>(equipInventory[name].GetItem())->Detach(*this);
	equipInventory.erase(name);
}

void Player::DeleteItem(string name)
{
	inventory.erase(name);
}
void Player::SellItem(string name, int num)
{
	if (inventory[name].GetCount() - num > 0)
	{
		inventory[name].AddCount(-num);
	}
	else
	{
		DeleteItem(name);
	}
}

bool Player::RandomProbability(int num)
{
	srand((unsigned int)time(NULL));
	int rnd = rand() % 100;

	if (rnd < num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::Skill1()
{
	mob->Hit((int)(FinalDamage() * (GetRandomValue(75,120)*0.01)));
}

void Player::Skill2()
{
	mob->Hit((int)(FinalDamage() * (GetRandomValue(1,20)*0.1)));
}

void Player::Skill3()
{
	if (RandomProbability(50))
	{
		mob->SetStateSturnToMonster(1);
		mob->Hit((int)(FinalDamage()*0.2));
	}
	else 
	{
		cout << "공격에 실패했다!!" << endl;
	}
}

void Player::Skill4()
{
	currentHealth += (int)(damage * 0.2);
	if (currentHealth > health)
	{
		currentHealth = health;
	}
}

int Player::FinalDamage()
{
	int finalDamage;
	if (RandomProbability(criticalProbability))
	{
		cout << "치명타 발동" << endl;
		finalDamage = damage * criticalDamage;
	}
	else
	{
		finalDamage = damage;
	}
	return finalDamage;
}

void Player::SetAttliction() 
{
	if (myAffliction = Normal)
	{
		if (stress >= 100)
		{
			myAffliction = (EAffliction)GetRandomValue(1, 3);
			switch (myAffliction)
			{
			case Paranoid:
				evasion += 10;
				speed += 2;
				damage -= 20;
				break;
			case Selfish:
				evasion += 5;
				damage -= 10;
				break;
			case Irrational:
				evasion -= 5;
				speed += 2;
				damage -= 10;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		if (stress == 0)
		{
			switch (myAffliction)
			{
			case Paranoid:
				evasion -= 10;
				speed -= 2;
				damage += 20;
				break;
			case Selfish:
				evasion -= 5;
				damage += 10;
				break;
			case Irrational:
				evasion += 5;
				speed -= 2;
				damage += 10;
				break;
			default:
				break;
			}
			myAffliction = Normal;
		}
		if (stress >= 200) 
		{
			if (myAffliction != DeathDoor)
			{
				myAffliction = DeathDoor;
				currentHealth = 1;
				stress = 170;
			}
			else if(myAffliction == DeathDoor)
			{
				IsDie();
			}
		}

	}
}


#pragma endregion 이벤트함수

