#pragma once
#include <Windows.h>
#include "IO/InputEvent.h"

void InputEvent::SafeInvoke(function<void()> Func)
{
	Sleep(100); // 중복 실행방지
	Func();
	Sleep(100); // 중복 실행방지
}

void InputEvent::AddEvent(const EKeyEvent& key, function<void()>&& Callback, function<void()>&& Complete)
{
	events.emplace_back(key, move(Callback), move(Complete));
	keyStates[key] = false; // 초기 상태는 눌려있지 않음
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
            // 키가 눌렸을 때
            SafeInvoke(Callback);
            if (Complete) SafeInvoke(Complete);
            keyStates[key] = true;
            return;
        }
        else if (!isPressed && keyStates[key]) {
            // 키가 떼졌을 때
            keyStates[key] = false;
        }
    }
}
