#pragma once
class Scene {
public:
	Scene();
	~Scene();
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};