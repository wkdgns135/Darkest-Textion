#include <Windows.h>
#include "IO/InputEvent.h"

void InputEvent::SafeInvoke(function<void()> func)
{
	Sleep(100); // 중복 실행방지
	func();
	Sleep(100); // 중복 실행방지
}

void InputEvent::AddEvent(const EKeyEvent& key, function<void()>&& callback, function<void()>&& complete)
{
	events.emplace_back(key, move(callback), move(complete));
}

void InputEvent::ProcessEvents()
{
	for (const auto& event : events) {
		if (GetAsyncKeyState(dict[get<0>(event)]) & 0x8000) {
			function<void()> callback = get<1>(event);
			function<void()> complete = get<2>(event);
			SafeInvoke(callback);
			if (complete)SafeInvoke(complete);
		}
	}
}
