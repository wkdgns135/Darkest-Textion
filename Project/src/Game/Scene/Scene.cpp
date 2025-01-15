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
		renderer->FillBuffer(deltaTime);
		renderer->Render();
		inputEvent->ProcessEvents();
		Update();
		Sleep(deltaTime); // Frame
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
