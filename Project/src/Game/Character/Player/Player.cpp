#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Character/Player/Player.h"
#include "Item/Item.h"
#include "Item/Consumable/Consumable.h";
#include "Item/Artifact/Artifact.h";
#include "Character/Monster/Monster.h"
#include "Utility.h"
#include "Global/ProjectEnum.h"

using namespace std;

#pragma region ������
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

#pragma endregion ������

#pragma region GetSet
void Player::AddItem(Item* item, int num)
{
	if (inventory.size() < 10)
	{
		// inventory map�� item.name �� Ű������ �����ϸ� count���� ������Ű�� ������ ���� �߰����ش�
		if (inventory.find(item->GetName()) != inventory.end()) //�������� �̸����� Ű�� �����Ҷ�
		{
			inventory[item->GetName()].AddCount(num);
		}
		else //Ű�� �������� ������
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

#pragma endregion GetSet�Լ�

#pragma region �̺�Ʈ�Լ�

void Player::Hit(int damage) //ĳ���� �ǰݽ� �߻��� �Լ�
{
	if (IsDie())
	{
		if (GetRandomValue(0, 100) <= 10)
		{
			cout << "ȸ�� ����!!" << endl;
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

bool Player::IsDie() //ĳ���� ����� �߻��� �Լ�
{
	if (currentHealth > 0)
	{
		return true;
	}
	else
	{
		//Todo:ĳ���Ͱ� ������ �߻��� �̺�Ʈ �ۼ�
		cout << "�÷��̾ ����߽��ϴ�!" << endl;
		return false;
	}
}

void Player::ShowStatus() // ĳ���� �������ͽ� �����ִ� �Լ�
{
	//�÷��̾� ������ ǥ���� �Լ�
	cout << "�̸� : " << name << " || " << "���� : " << level << " || " << "�ִ�ü�� : " << health << " || " << "����ü�� : " << currentHealth << " || " << "���ݷ� : " << damage << " || " << "�������ġ : " << exp << endl;
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
		if (typeid(inventory[name].GetItem()) == typeid(Consumable)) //�������� ��밡���� �������϶�
		{
			static_cast<Consumable*>(inventory[name].GetItem())->Use(*this);
			inventory[name].AddCount(-1);
			if (inventory[name].GetCount() == 0)
			{
				DeleteItem(name);
			}
		}
		else // ���Ұ����� �������϶�
		{
			cout << "Error : ���Ұ����� ������ �Դϴ�";
		}
	}
	else
	{
		cout << "Error : �ش� �������� �������� �ʽ��ϴ�" << endl;
	}
}

void Player::EquipItem(string name) //�κ��丮���� �������� ����
{
	if (equipInventory.size() < 2) {
		if (typeid(inventory[name].GetItem()) == typeid(Artifact))
		{
			// �������� ȿ�� ����ϱ�
			equipInventory.insert({name,inventory[name]});
			static_cast<Artifact*>(equipInventory[name].GetItem())->Attach(*this);
			inventory.erase(name);
		}
		else
		{
			cout << "Error : ���� �Ұ����� ������ �Դϴ�" << endl;
		}
	}
	else
	{
		cout << "�ִ� ���� ������ �ʰ��Ͽ����ϴ�" << endl;
	}
}

void Player::UnEquipItem(string name) //�������� ���� �����ؼ� �ٽ� �κ��丮��
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
		cout << "���ݿ� �����ߴ�!!" << endl;
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
		cout << "ġ��Ÿ �ߵ�" << endl;
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


#pragma endregion �̺�Ʈ�Լ�

