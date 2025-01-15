#pragma once
#include <Windows.h>
#include "IO/InputEvent.h"

void InputEvent::SafeInvoke(function<void()> Func)
{
	Sleep(100); // �ߺ� �������
	Func();
	Sleep(100); // �ߺ� �������
}

void InputEvent::AddEvent(const EKeyEvent& key, function<void()>&& Callback, function<void()>&& Complete)
{
	events.emplace_back(key, move(Callback), move(Complete));
	keyStates[key] = false; // �ʱ� ���´� �������� ����
}

void InputEvent::ClearEvent()
{
    events.clear();
    keyStates.clear();
}

void InputEvent::ProcessEvents()
{
    for (const auto& event : events) {
        EKeyEvent key = get<0>(event);
        function<void()> Callback = get<1>(event);
        function<void()> Complete = get<2>(event);

        bool isPressed = GetAsyncKeyState(keyDict[key]) & 0x8000;

        if (isPressed && !keyStates[key]) {
            // Ű�� ������ ��
            SafeInvoke(Callback);
            if (Complete) SafeInvoke(Complete);
            keyStates[key] = true;
            return;
        }
        else if (!isPressed && keyStates[key]) {
            // Ű�� ������ ��
            keyStates[key] = false;
        }
    }
}
