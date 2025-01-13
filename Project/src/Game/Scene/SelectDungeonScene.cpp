#include "IO/OutputManager.h"
#include "Scene/SceneManager.h"

void SelectDungeonScene::SelectWeald()
{
	name = "�︲ ����";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectCove()
{
	name = "�ؾ� ��";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::SelectDarkestDungeon()
{
	name = "���� ��ο� ����";
	SceneManager::GetInstance().ChangeScene<DungeonInfoScene>();
}

void SelectDungeonScene::Enter()
{
	OutputManager::GetInstance().PrintAsciiArt(SelectDungeonAsciiArt);
	AddInputEvent(Key_1, [this]() {SelectWeald(); });
	AddInputEvent(Key_2, [this]() {SelectCove(); });
	AddInputEvent(Key_3, [this]() {SelectDarkestDungeon(); });
	AddInputEvent(Key_ESC, [this]() {SceneManager::GetInstance().ChangeScene<MainScene>(); });
}

void SelectDungeonScene::Update()
{

}

void SelectDungeonScene::Exit()
{
	OutputManager::GetInstance().SetConsoleFontForText();
	cout << name << "��(��) �����ϼ̽��ϴ�." << '\n';
	if (name == "���� ��ο� ����")cout << "�� ������ �ص��� �����մϴ�. ";
}