#include "ShopScene.h"
#include <iostream>

using namespace std;

ShopScene::ShopScene();

void ShopScene::sceneItem() const
{
	int intput;
	cout << "상점에 오신걸 환영합니다" << endl;
	cout << "[ 구매 ] [ 판매 ] 입력 : ";
	cin >> intput;

	switch (tolower(input)) 
	{
		case '구매':
			buyItem();
			break;
		case '판매':
			saleItem();
			break;
		default:
			cout << "[ 경고 ] 입력을 잘못하셨습니다!" << endl;
			break;
	}
}

void ShopScene::buyItem()
{
	int index;

	listMessage();
	cout << "구매할 아이템 번호를 입력해 주세요 : ";
	cin >> index;

	if (index < 1 || index > /* 이곳에 아이템 생성자 크기 코드 입력 ex) item.size() */)
	{
		cout << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}
	
	int buy_input;
	/*이곳에 아이템 인덱스 변수 코드 입력 ex) Item& item = item[index - 1]; */
	cout << "아이템 이름 : " << /*아이템 이름*/ << endl;
	cout << "아이템 가격 : " << /*아이템 가격*/ << endl;
	cout << "얼마나 구매 하시겠습니까?" << endl;
	cin >> buy_input;

	//여기서부터 구매로직 구현
	buyMessage();
}

void ShopScene::saleItem()
{
	int index;

	listMessage();
	cout << "판매할 아이템 번호를 입력해 주세요 : ";
	cin >> index;

	if (index < 1 || index > /* 이곳에 아이템 생성자 크기 코드 입력 ex) item.size() */)
	{
		cout << "해당 아이템 번호가 존재하지 않습니다." << endl;
		return;
	}

	int buy_input;
	/*이곳에 아이템 인덱스 변수 코드 입력 ex) Item& item = item[index - 1]; */
	cout << "아이템 이름 : " << /*아이템 이름*/ << endl;
	cout << "아이템 가격 : " << /*아이템 가격*/ << endl;
	cout << "얼마나 판매 하시겠습니까?" << endl;
	cin >> buy_input;

	//여기서부터 판매로직 구현
	saleMessage();
}

void ShopScene::buyMessage() const
{

}

void ShopScene::saleMessage() const
{
	
}

void ShopScene::listMessage() const
{
	//만들어진 아이템 목록 나열 
}