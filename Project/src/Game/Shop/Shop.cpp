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
	if (index < 1 || index >= static_cast<int>(itemlist.size())) // �������� �ش� ��ȣ�� �ִ��� 0���� Ȯ��
	{
		cout << prefix << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (GetInventorySize() + count > 10) //�κ��丮 ������ + ������ ������ 10�� �̻��̸� �߰��ȵ�
	{
		cout << prefix << "�κ��丮�� ���� á���ϴ�." << endl;
		return;
	}

	// ������ �ݾ� ���
	auto it = itemlist.begin(); //����Ʈ ù��° ĭ
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
	if (index < 1 || index >= static_cast<int>(itemlist.size()))  // �������� �ش� ��ȣ�� �ִ��� 0���� Ȯ��
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (!IsItemAvailable(index)) //�÷��̾� ������ ���� ����
	{
		cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�." << endl;
		return;
	}
	// �Ǹ��� ������ ���� ��� (60% ��ȯ)
	auto it = itemlist.begin(); //����Ʈ ù��° ĭ
	advance(it, index); //index��ŭ �ڷ� �̵�
	int totalPrice = static_cast<int>(it->second.GetPrice() * count * 0.6); //�ش� �� + ������ 60% 

	player->AddGold(totalPrice); //�Ǹ� ������ 60% ��� �߰�

	for (int i = 0; i < count; ++i) { player->UseItem(it->second.GetName()); } // ������ �°� �������� ����ϴ� ������� �Ǹ� ó��;
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
		return true; //������ true ��ȯ
	}
	catch (...)
	{
		return false; //���ܸ� false ��ȯ
	}
}

// ������ ��� �Լ� ��ȣ���� ����ؼ� �˸°� ���Ű���
void Shop::ShowItemList()
{
	int idx = 0;
	for (const auto& pair : itemlist)
	{
		cout << idx << ": " << pair.second.GetName() << ", ����: " << pair.second.GetPrice() << " ���" << endl;
		++idx;
	}
}
