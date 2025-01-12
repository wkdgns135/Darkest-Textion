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
}

void InputEvent::ProcessEvents()
{
	for (const auto& event : events) {
		if (GetAsyncKeyState(dict[get<0>(event)]) & 0x8000) {
			function<void()> Callback = get<1>(event);
			function<void()> Complete = get<2>(event);
			SafeInvoke(Callback);
			if (Complete)SafeInvoke(Complete);
		}
	}
}
