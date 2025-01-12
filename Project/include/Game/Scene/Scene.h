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

	// Scene�� ����ǰ� 1�� ȣ��
	virtual void Enter() = 0;
	// Scene������ ���������� ȣ��Ǵ� �Լ�
	virtual void Update() = 0;
	// �ٸ� Scene���� ��ȯ�Ǳ� ���� ȣ��Ǵ� �Լ�
	virtual void Exit() = 0;

	// �ݹ� �߰� �Լ�
	template <typename Func>
	void AddInputEvent(const EKeyEvent& key, Func&& callback, function<void()> complete = nullptr) {
		inputEvent->AddEvent(key, function<void()>(forward<Func>(callback)), move(complete));
	}

};