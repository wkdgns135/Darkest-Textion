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


using namespace std;

#pragma region ������
Player::Player(string name)
{
	mob = nullptr;
	this->name = name;
	additionalExp = 0;
	additionalStress = 0;
	level = 1;
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

/*Player::Player(string name, int level, int currentHealth, int exp, int gold, int stress, vector<Item*>& inventory) // �������� �ҷ��ö� ���� ������
{
	this->name = name;
	this->level = level;
	this->gold = gold;
	this->stress = stress;
	damage = 30 + (level - 1 * levelUpDamage);
	this->currentHealth = currentHealth;;
	health = 200 + (level - 1 * levelUpHealth);
	this->exp = exp;
	this->inventory = inventory;
}*/

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
		if (RandomProbability(10))
		{
			cout << "ȸ�� ����!!" << endl;
		}
		else 
		{
			currentHealth -= damage;
			IsDie();
		}
	}
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
	if (RandomProbability(50))
	{
		//Todo : ������ ���� �Լ��� �ҷ��´�
		mob->SetStateSturnToMonster(3);
		mob->Hit(FinalDamage());
	}
	else 
	{
		cout << "���ݿ� �����ߴ�!!" << endl;
	}
}
void Player::Skill2()
{
	srand((unsigned int)time(NULL));
	int rnd = rand() % 100;

	currentHealth += rnd;
	if (currentHealth > health)
	{
		currentHealth = health;
	}
}
void Player::Skill3()
{
	mob->Hit(FinalDamage() * 2);
}
void Player::Skill4()
{
	srand((unsigned int)time(NULL));
	int rnd = rand() % 100;
	float damagernd = rnd * 0.1;

	mob->Hit((int)(FinalDamage() * damagernd));
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

#pragma endregion �̺�Ʈ�Լ�

