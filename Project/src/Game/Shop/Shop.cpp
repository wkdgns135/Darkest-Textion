#include "Shop/Shop.h"
#include "Character/Player/Player.h"

//아이템 클래스
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

Shop::Shop(Player* player) : player(player) //아이템 맵 선언 초기화
{
	itemlist["SpeedStone"] = Item(speedstone.GetName(), speedstone.GetPrice());
	itemlist["SnakeOil"] = Item(snake0il.GetName(), snake0il.GetPrice());
	itemlist["knightscrest"] = Item(knightscrest.GetName(), knightscrest.GetPrice());
	itemlist["healthstone"] = Item(healthstone.GetName(), healthstone.GetPrice());
	itemlist["expstone"] = Item(expstone.GetName(), expstone.GetPrice());
}

void Shop::PurchaseItem(int index, int gold, int count) //아이템 구매
{
	if (index < 1 || index >= static_cast<int>(itemlist.size())) // 아이템의 해당 번호가 있는지 0부터 확인
	{
		cout << prefix << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}
	if (GetInventorySize() + count > 10) //인벤토리 아이템 + 구매할 아이템 10개 이상이면 추가안됨
	{
		cout << prefix << "인벤토리가 가득 찼습니다." << endl;
		return;
	}

	// 구매할 금액 계산
	auto it = itemlist.begin(); //리스트 첫번째 칸
	advance(it, index); //index만큼 뒤로 이동
	int totalprice = it->second.GetPrice() * count; //해당 값의 가격 + 수량

	if (gold < totalprice) // 아이템 가격보다 적은 금액 입력 방지
	{
		cout << prefix << "금액이 부족합니다." << endl;
		return;
	}
	player->AddGold(-totalprice); //골드 제거
	player->AddItem(make_unique<Item>(it->second), count); // 아이템 추가 수량만큼
}

void Shop::SellItem(int index, int count) //아이템 판매
{
	if (index < 1 || index >= static_cast<int>(itemlist.size()))  // 아이템의 해당 번호가 있는지 0부터 확인
	{
		cout << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}
	if (!IsItemAvailable(index)) //플레이어 아이템 존재 여부
	{
		cout << "해당 아이템을 소지하고 있지 않습니다." << endl;
		return;
	}
	// 판매할 아이템 가격 계산 (60% 반환)
	auto it = itemlist.begin(); //리스트 첫번째 칸
	advance(it, index); //index만큼 뒤로 이동
	int totalPrice = static_cast<int>(it->second.GetPrice() * count * 0.6); //해당 값 + 수량의 60% 

	player->AddGold(totalPrice); //판매 수량의 60% 골드 추가

	for (int i = 0; i < count; ++i) { player->UseItem(it->second.GetName()); } // 수량에 맞게 아이템을 사용하는 방식으로 판매 처리;
}

// 아이템 보유 개수를 확인하는 헬퍼 함수 (리플렉션 없이 안전한 방식) 이라고 인터넷 찾아봄
int Shop::GetInventorySize()
{
	int count = 0;
	try
	{
		// 10개를 초과할 경우 검사 (최악의 상황 방지)
		for (int i = 0; i < 10; ++i)
		{
			player->UseItem(i);  // 임시로 아이템 사용 메서드를 호출해 검사
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
	try
	{
		player->UseItem(index);  // 유효한 인덱스인지 검사
		return true; //맞으면 true 반환
	}
	catch (...)
	{
		return false; //예외면 false 반환
	}
}

// 아이템 목록 함수 번호까지 출력해서 알맞게 구매가능
void Shop::ShowItemList()
{
	int idx = 0;
	for (const auto& pair : itemlist)
	{
		cout << idx << ": " << pair.second.GetName() << ", 가격: " << pair.second.GetPrice() << " 골드" << endl;
		++idx;
	}
}
