#pragma once
#include <string>
#include "Scene.h"
class SelectDungeonScene : public Scene{
private:
	void SelectWeald();
	void SelectCove();
	void SelectDarkestDungeon();

public:
	void Enter() override;
	void Update() override;
	void Exit() override;
};