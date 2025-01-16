#pragma once
#include <memory>
#include "IO/InputEvent.h"
#include "IO/Image.h"
#include "IO/Renderer.h"

class Scene {
private:
	float deltaTime = 50;
	bool isActive = false;
	unique_ptr<InputEvent> inputEvent;

	void ShowEquipPannel(Vector2d initLoc);
protected:
	vector<Vector2d> cursorLoc;
	vector<Vector2d> equipCursorLoc;
	unique_ptr<Renderer> renderer;
	int cursor;
	int equipCursur;

public:
	Scene();
	~Scene();
	void RootEnter();
	void RootUpdate();
	void RootExit();

	void ShowInventory();
	void ShowGoldPannel();
	virtual void ShowCursor();
	virtual void MoveCursor(int direction);

	void ShowEquipCursor();
	void MoveEquipCursor(int direction);

	void SetInventoryMode();
	virtual void SetCustomMode();
	virtual void RedrawInventory();

	// Scene이 변경되고 1번 호출
	virtual void Enter() = 0;
	// Scene내에서 지속적으로 호출되는 함수
	virtual void Update() = 0;
	// 다른 Scene으로 전환되기 전에 호출되는 함수
	virtual void Exit() = 0;

	/*NOTE: 키 이벤트 함수 등록 방법
	* Scene 내부에서 AddInputEvent를 호출하여 AddInputEvent(EKeyEvent, Callback, Complete) 형태로 호출
	* 정적 함수를 콜백으로 등록시키려면 AddInputEvent(EKeyEvent, SomeStaticFunc1, SomeStaticFunc2);
	* 멤버 함수를 콜백으로 등록시키려면 AddInputEvent(EKeyEvent, [this](){SomeMemberFunc();}, [this](){SomeMemberFunc2();});
	*/
	template <typename Func>
	void AddInputEvent(const EKeyEvent& key, Func&& Callback, function<void()> Complete = nullptr) {
		inputEvent->AddEvent(key, function<void()>(forward<Func>(Callback)), move(Complete));
	}

	inline void ClearEvent() { inputEvent->ClearEvent(); };
};