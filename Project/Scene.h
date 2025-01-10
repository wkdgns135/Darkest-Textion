#pragma once
class Scene {
public:
	Scene();
	~Scene();
	
	// Scene�� ����ǰ� 1�� ȣ��
	virtual void Enter() = 0;

	// Scene������ ���������� ȣ��Ǵ� �Լ�
	virtual void Update() = 0;

	// �ٸ� Scene���� ��ȯ�Ǳ� ���� ȣ��Ǵ� �Լ�
	virtual void Exit() = 0;
};