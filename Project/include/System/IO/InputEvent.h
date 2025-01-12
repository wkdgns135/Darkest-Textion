#pragma once
#include <functional>
#include <vector>
#include <unordered_map>
#include "Global/ProjectEnum.h"
using namespace std;

class InputEvent {
private:
	vector<tuple<EKeyEvent, function<void()> , function<void()>>> events;
	unordered_map<EKeyEvent, char> dict = { {Key_1, '1'}, {Key_2, '2'}, {Key_3, '3'} };
	void SafeInvoke(function<void()> Func);

public:
	void AddEvent(const EKeyEvent& key, function<void()>&& Callback, function<void()>&& Complete = nullptr);
	void ProcessEvents();
};