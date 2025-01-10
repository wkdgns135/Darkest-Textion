#include "Shop.h"
#include <iostream>

using namespace std;

Shop::Shop();

Shop::purchaseItem(int index)
{
	if (index < 1 || index > /* 이곳에 아이템 생성자 크기 코드 입력 ex) item.size() */)
	{
		cout << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}
}

Shop::sellItem(int index)
{
	if (index < 1 || index > /* 이곳에 아이템 생성자 크기 코드 입력 ex) item.size() */)
	{
		cout << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}
}