#pragma once

#include <memory>
#include "IO/InputEvent.h"

class Scene {
private:
	bool isActive = false;
	unique_ptr<InputEvent> inputEvent;

public:
	Scene();
	void RootEnter();
	void RootUpdate();
	void RootExit();

	// Scene이 변경되고 1번 호출
	virtual void Enter() = 0;
	// Scene내에서 지속적으로 호출되는 함수
	virtual void Update() = 0;
	// 다른 Scene으로 전환되기 전에 호출되는 함수
	virtual void Exit() = 0;

	// 콜백 추가 함수
	template <typename Func>
	void AddInputEvent(const EKeyEvent& key, Func&& callback, function<void()> complete = nullptr) {
		inputEvent->AddEvent(key, function<void()>(forward<Func>(callback)), move(complete));
	}

};