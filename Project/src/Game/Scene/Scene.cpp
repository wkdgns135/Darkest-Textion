#include "Scene/Scene.h"
#include <Windows.h>

Scene::Scene()
{
	inputEvent = make_unique<InputEvent>();
	renderer = make_unique<Renderer>();
}

void Scene::RootUpdate()
{
	while (isActive) {
		renderer->ClearBuffer();
		renderer->FillBuffer();
		renderer->Render();
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
