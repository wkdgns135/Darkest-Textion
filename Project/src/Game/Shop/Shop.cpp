#include "Shop/Shop.h"
#include "Global/Global.h"

//아이템 클래스
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

Shop::Shop() //아이템 맵 선언 초기화
{
	//Artifact
}

bool Shop::PurchaseItem(int index, int count) //아이템 구매
{
	// 구매할 금액 계산
	auto it = itemlist.begin(); //리스트 첫번째 칸
	advance(it, index); //index만큼 뒤로 이동
	int totalprice = it->second->GetPrice() * count; //해당 값의 가격 + 수량

	Player* player = GameManager::GetInstance().GetPlayer();

	if (player->GetGold() < totalprice) // 아이템 가격보다 적은 금액 입력 방지
	{
		cout << prefix << "금액이 부족합니다." << endl;
		return false;
	}
	player->AddGold(-totalprice); //골드 제거
	player->AddItem(it->second, count); // 아이템 추가 수량만큼
	return true;
}

bool Shop::SellItem(int index, int count) //아이템 판매
{
	if (!IsPlayerItemAvailable(index)) //플레이어 아이템 존재 여부
	{
		cout << "해당 아이템을 소지하고 있지 않습니다." << endl;
		return false;
	}
	//판매할 아이템 가격 계산 (60% 반환)
	auto it = itemlist.begin(); //리스트 첫번째 칸
	advance(it, index); //index만큼 뒤로 이동
	int totalprice = static_cast<int>(it->second->GetPrice() * count * 0.6); //해당 값 + 수량의 60% 

	Player* player = GameManager::GetInstance().GetPlayer();

	player->AddGold(totalprice); //판매 수량의 60% 골드 추가

	player->UseItem(it->second->GetName()); // 판매 처리;
	return true;
}

// 아이템 보유 개수를 확인하는 헬퍼 함수 (리플렉션 없이 안전한 방식) 이라고 인터넷 찾아봄
int Shop::GetInventorySize()
{
	Player* player = GameManager::GetInstance().GetPlayer();

	int count = 0;
	try
	{
		// 10개를 초과할 경우 검사 (최악의 상황 방지)
		for (int i = 0; i < 10; ++i)
		{
			player->UseItem("test");  // 임시로 아이템 사용 메서드를 호출해 검사
			++count;
		}
	}
	catch (...)
	{
		// 예외가 발생하면 인벤토리 끝에 도달했다고 간주
	}
	return count;
}

//플레이어 아이템 존재 여부 검사 함수
bool Shop::IsPlayerItemAvailable(int index)
{
	Player* player = GameManager::GetInstance().GetPlayer();
	try
	{
		player->UseItem("test");  // 유효한 인덱스인지 검사
		return true; //맞으면 true 반환
	}
	catch (...)
	{
		return false; //예외면 false 반환
	}
}

void Shop::InitalizeWithRandomItem()
{
	// TODO : random하기 생성하기
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

// 아이템 목록 함수 번호까지 출력해서 알맞게 구매가능
void Shop::ShowItemList()
{
	int idx = 0;
	for (const auto& pair : itemlist)
	{
		cout << idx << ": " << pair.second->GetName() << ", 가격: " << pair.second->GetPrice() << " 골드" << endl;
		++idx;
	}
}
