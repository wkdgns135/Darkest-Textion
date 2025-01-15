#pragma once
#include "Scene.h"

class DungeonScene : public Scene{
private:
	void InitBackground();
public:
	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};