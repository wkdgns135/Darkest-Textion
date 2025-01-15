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
	vector<Image*> drawTarget;

protected:
	unique_ptr<Renderer> renderer;

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

	/*NOTE: Ű �̺�Ʈ �Լ� ��� ���
	* Scene ���ο��� AddInputEvent�� ȣ���Ͽ� AddInputEvent(EKeyEvent, Callback, Complete) ���·� ȣ��
	* ���� �Լ��� �ݹ����� ��Ͻ�Ű���� AddInputEvent(EKeyEvent, SomeStaticFunc1, SomeStaticFunc2);
	* ��� �Լ��� �ݹ����� ��Ͻ�Ű���� AddInputEvent(EKeyEvent, [this](){SomeMemberFunc();}, [this](){SomeMemberFunc2();});
	*/
	template <typename Func>
	void AddInputEvent(const EKeyEvent& key, Func&& Callback, function<void()> Complete = nullptr) {
		inputEvent->AddEvent(key, function<void()>(forward<Func>(Callback)), move(Complete));
	}
	inline void ClearInputEvent() { inputEvent->ClearEvent(); };
};