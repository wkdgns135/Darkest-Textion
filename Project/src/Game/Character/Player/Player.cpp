#include <iostream>
#include <string>
#include "Character/Player/Player.h"
#include "Item/Item.h"
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
}

Player::Player(string name, int level, int currentHealth, int exp, int gold, vector<Item*> &inventory) // �������� �ҷ��ö� ���� ������
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
#pragma endregion ������

#pragma region GetSet
void Player::AddItem(Item* myItem)
{
	if(inventory.size() < 10)
	inventory.push_back(myItem);
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

void Player::Attack() 	//ĳ���Ͱ� ���ݽ� �߻��� �Լ�
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

void Player::UseItem(int num)
{
	if (num < inventory.size())
	{
		//inventory[num].Use(*this);
	}
}

#pragma endregion �̺�Ʈ�Լ�

