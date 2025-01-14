#include "Shop/Shop.h"
#include "Character/Player/Player.h"

//������ Ŭ����
#include "Item/Item.h"
#include "Item/Artifact/SpeedStone.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/ExpStone.h"

#include <vector>
#include <iostream>
#include <map>
#include <memory>

using namespace std;

Shop::Shop(Player* player) : player(player) //������ �� ���� �ʱ�ȭ
{
	itemlist["SpeedStone"] = Item(speedstone.GetName(), speedstone.GetPrice());
	itemlist["SnakeOil"] = Item(snake0il.GetName(), snake0il.GetPrice());
	itemlist["knightscrest"] = Item(knightscrest.GetName(), knightscrest.GetPrice());
	itemlist["healthstone"] = Item(healthstone.GetName(), healthstone.GetPrice());
	itemlist["expstone"] = Item(expstone.GetName(), expstone.GetPrice());
}

void Shop::PurchaseItem(int index, int gold, int count) //������ ����
{
	if (index < 1 || index >= static_cast<int>(itemlist.size())) // ������ �迭 ��ȣ �ĺ�
	{
		cout << prefix << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (GetInventorySize() >= 10) //������ 10�� �̻��̸� �߰��ȵ�
	{
		cout << prefix << "�κ��丮�� ���� á���ϴ�." << endl;
		return;
	}

	// ������ �ݾ� ���
	auto it = itemlist.begin(); //����Ʈ ù���� ĭ
	advance(it, index); //index��ŭ �ڷ� �̵�
	int totalprice = it->second.GetPrice() * count; //�ش� ���� ���� + ����

	if (gold < totalprice) // ������ ���ݺ��� ���� �ݾ� �Է� ����
	{
		cout << prefix << "�ݾ��� �����մϴ�." << endl;
		return;
	}
	player->AddGold(-totalprice); //��� ����
	player->AddItem(make_unique<Item>(it->second), count); // ������ �߰� ������ŭ
}

void Shop::SellItem(int index, int count) //������ �Ǹ�
{
	if (index < 1 || index > itemlist.size())  //������ �迭 �ĺ�
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (GetInventorySize() >= 10)  //������ 10�� �̻��̸� �߰��ȵ�
	{
		cout << "�κ��丮�� ���� á���ϴ�." << endl;
		return;
	}
	if (!IsItemAvailable(index)) //�÷��̾� ������ ���� ����
	{
		cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�." << endl;
		return;
	}
	int itemPrice = itemlist[index].GetPrice();
	player->AddGold(itemPrice * count * 0.6); //������ �°� ��� �߰�

	for (int i = 0; i < count; ++i) { player->UseItem(index);  } // ������ �°� �������� ����ϴ� ������� �Ǹ� ó��;
}

// ������ ���� ������ Ȯ���ϴ� ���� �Լ� (���÷��� ���� ������ ���) �̶�� ���ͳ� ã�ƺ�
int Shop::GetInventorySize()
{
	int count = 0;
	try
	{
		// 10���� �ʰ��� ��� �˻� (�־��� ��Ȳ ����)
		for (int i = 0; i < 10; ++i)
		{
			player->UseItem(i);  // �ӽ÷� ������ ��� �޼��带 ȣ���� �˻�
			++count;
		}
	}
	catch (...)
	{
		// ���ܰ� �߻��ϸ� �κ��丮 ���� �����ߴٰ� ����
	}
	return count;
}

//�÷��̾� ������ ���� ���� �˻� �Լ�
bool Shop::IsPlayerItemAvailable(int index)
{
	try
	{
		player->UseItem(index);  // ��ȿ�� �ε������� �˻�
		return true;
	}
	catch (...)
	{
		return false;
	}
}

void Shop::ShowItemList()
{
	for (const auto& pair : itemlist)
	{
		cout << pair.first << ": " << pair.second.GetName() << ", ����: " << pair.second.GetPrice() << endl;
	}
}
