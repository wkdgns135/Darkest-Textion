#include "Scene/Scene.h"
#include <Windows.h>

Scene::Scene()
{
	inputEvent = make_unique<InputEvent>();
}

void Scene::RootUpdate()
{
	while (isActive) {
		inputEvent->ProcessEvents();
		Update();
		Sleep(50); // Frame
	}
}


void Scene::RootEnter()
{
	isActive = true;
}

void Scene::RootExit()
{
	isActive = false;
	system("cls");
}
