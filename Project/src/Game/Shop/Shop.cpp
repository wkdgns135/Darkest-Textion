#include "Shop/Shop.h"
#include <iostream>

using namespace std;

Shop::Shop() {
}

void Shop::purchaseItem(int index)
{
	if (index < 1)// || index > /* �̰��� ������ ������ ũ�� �ڵ� �Է� ex) item.size() */)
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
}

void Shop::sellItem(int index)
{
	if (index < 1) // || index > /* �̰��� ������ ������ ũ�� �ڵ� �Է� ex) item.size() */)
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
}