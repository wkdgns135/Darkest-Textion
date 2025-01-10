#pragma once
class Scene {
public:
	Scene();
	~Scene();
	
	// Scene이 변경되고 1번 호출
	virtual void Enter() = 0;

	// Scene내에서 지속적으로 호출되는 함수
	virtual void Update() = 0;

	// 다른 Scene으로 전환되기 전에 호출되는 함수
	virtual void Exit() = 0;
};