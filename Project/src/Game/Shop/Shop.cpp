#include "Shop/Shop.h"
#include "Global/Global.h"

//������ Ŭ����
#include "Item/Item.h"
#include "Item/Artifact/HealthStone.h"
#include "Item/Artifact/KnightsCrest.h"
#include "Item/Artifact/SnakeOil.h"
#include "Item/Artifact/ExpStone.h"
#include "Item/Artifact/RareArtifact.h"

#include "Item/Consumable/HealthPotion.h"
#include "Item/Consumable/DamageBoost.h"
#include "Item/Consumable/Laudanum.h"

#include <vector>
#include <iostream>
#include <map>
#include <memory>

using namespace std;

Shop::Shop() //������ �� ���� �ʱ�ȭ
{
	//Artifact
}

bool Shop::PurchaseItem(int index, int count) //������ ����
{
	// ������ �ݾ� ���
	auto it = itemlist.begin(); //����Ʈ ù��° ĭ
	advance(it, index); //index��ŭ �ڷ� �̵�
	int totalprice = it->second->GetPrice() * count; //�ش� ���� ���� + ����

	Player* player = GameManager::GetInstance().GetPlayer();

	if (player->GetGold() < totalprice) // ������ ���ݺ��� ���� �ݾ� �Է� ����
	{
		cout << prefix << "�ݾ��� �����մϴ�." << endl;
		return false;
	}
	player->AddGold(-totalprice); //��� ����
	player->AddItem(it->second, count); // ������ �߰� ������ŭ
	return true;
}

bool Shop::SellItem(int index, int count) //������ �Ǹ�
{
	if (!IsPlayerItemAvailable(index)) //�÷��̾� ������ ���� ����
	{
		cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�." << endl;
		return false;
	}
	//�Ǹ��� ������ ���� ��� (60% ��ȯ)
	auto it = itemlist.begin(); //����Ʈ ù��° ĭ
	advance(it, index); //index��ŭ �ڷ� �̵�
	int totalprice = static_cast<int>(it->second->GetPrice() * count * 0.6); //�ش� �� + ������ 60% 

	Player* player = GameManager::GetInstance().GetPlayer();

	player->AddGold(totalprice); //�Ǹ� ������ 60% ��� �߰�

	player->UseItem(it->second->GetName()); // �Ǹ� ó��;
	return true;
}

// ������ ���� ������ Ȯ���ϴ� ���� �Լ� (���÷��� ���� ������ ���) �̶�� ���ͳ� ã�ƺ�
int Shop::GetInventorySize()
{
	Player* player = GameManager::GetInstance().GetPlayer();

	int count = 0;
	try
	{
		// 10���� �ʰ��� ��� �˻� (�־��� ��Ȳ ����)
		for (int i = 0; i < 10; ++i)
		{
			player->UseItem("test");  // �ӽ÷� ������ ��� �޼��带 ȣ���� �˻�
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
	Player* player = GameManager::GetInstance().GetPlayer();
	try
	{
		player->UseItem("test");  // ��ȿ�� �ε������� �˻�
		return true; //������ true ��ȯ
	}
	catch (...)
	{
		return false; //���ܸ� false ��ȯ
	}
}

void Shop::InitalizeWithRandomItem()
{
	// TODO : random�ϱ� �����ϱ�
	//unique_ptr<Artifact> item = make_unique<HealthStone>();
	//Item* healthStone = new RareArtifact(move(item));
	//Item* knightsCrest = new KnightsCrest();
	//Item* snakeOil = new SnakeOil();
	//Item* expStone = new ExpStone();

	//Item test = HealthStone();

	//itemlist[healthStone->GetName()] = healthStone;
	//itemlist[knightsCrest->GetName()] = knightsCrest;
	//itemlist[snakeOil->GetName()] = snakeOil;
	//itemlist[expStone->GetName()] = expStone;
}

void Shop::InitializeOnlyConsumable()
{
	Item* healthPotion = new HealthPotion();
	Item* damageboost = new DamageBoost();
	Item* laudanum = new Laudanum();

	itemlist[1] = healthPotion;
	itemlist[2] = damageboost;
	itemlist[3] = laudanum;
}

// ������ ��� �Լ� ��ȣ���� ����ؼ� �˸°� ���Ű���
void Shop::ShowItemList()
{
	int idx = 0;
	for (const auto& pair : itemlist)
	{
		cout << idx << ": " << pair.second->GetName() << ", ����: " << pair.second->GetPrice() << " ���" << endl;
		++idx;
	}
}
