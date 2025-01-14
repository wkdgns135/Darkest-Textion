#include <iostream>
#include <string>
#include <typeinfo>
#include "Character/Player/Player.h"
#include "Item/Item.h"
#include "Item/Consumable/Consumable.h";
#include "Item/Artifact/Artifact.h";

using namespace std;

#pragma region ������
Player::Player(string name)
{
	this->name = name;
	level = 1;
	health = currentHealth = 200;
	gold = 0;
	damage = 30;
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
		currentHealth -= damage;
		IsDie();
	}
}

void Player::Attack()
{
	//���͸� �޾ƿͼ� �׸����� Hit �Լ��� ȣ��
	mob->Hit(damage);
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
	equipInventory.erase(name);
}

void Player::DeleteItem(string name)
{
	inventory.erase(name);
}

#pragma endregion �̺�Ʈ�Լ�

