#include "ShopScene.h"
#include <iostream>

using namespace std;

ShopScene::ShopScene();

void ShopScene::sceneItem() const
{
	int intput;
	cout << "������ ���Ű� ȯ���մϴ�" << endl;
	cout << "[ ���� ] [ �Ǹ� ] �Է� : ";
	cin >> intput;

	switch (tolower(input)) 
	{
		case '����':
			buyItem();
			break;
		case '�Ǹ�':
			saleItem();
			break;
		default:
			cout << "[ ��� ] �Է��� �߸��ϼ̽��ϴ�!" << endl;
			break;
	}
}

void ShopScene::buyItem()
{
	int index;

	listMessage();
	cout << "������ ������ ��ȣ�� �Է��� �ּ��� : ";
	cin >> index;

	if (index < 1 || index > /* �̰��� ������ ������ ũ�� �ڵ� �Է� ex) item.size() */)
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	
	int buy_input;
	/*�̰��� ������ �ε��� ���� �ڵ� �Է� ex) Item& item = item[index - 1]; */
	cout << "������ �̸� : " << /*������ �̸�*/ << endl;
	cout << "������ ���� : " << /*������ ����*/ << endl;
	cout << "�󸶳� ���� �Ͻðڽ��ϱ�?" << endl;
	cin >> buy_input;

	//���⼭���� ���ŷ��� ����
	buyMessage();
}

void ShopScene::saleItem()
{
	int index;

	listMessage();
	cout << "�Ǹ��� ������ ��ȣ�� �Է��� �ּ��� : ";
	cin >> index;

	if (index < 1 || index > /* �̰��� ������ ������ ũ�� �ڵ� �Է� ex) item.size() */)
	{
		cout << "�ش� ������ ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}

	int buy_input;
	/*�̰��� ������ �ε��� ���� �ڵ� �Է� ex) Item& item = item[index - 1]; */
	cout << "������ �̸� : " << /*������ �̸�*/ << endl;
	cout << "������ ���� : " << /*������ ����*/ << endl;
	cout << "�󸶳� �Ǹ� �Ͻðڽ��ϱ�?" << endl;
	cin >> buy_input;

	//���⼭���� �Ǹŷ��� ����
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
	//������� ������ ��� ���� 
}