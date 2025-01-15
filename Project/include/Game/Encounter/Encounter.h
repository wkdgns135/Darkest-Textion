#pragma once

enum EncountState {
	BattleRoom,
	TrapRoom,
	ItemRoom,
};

class Encounter {
private:
	EncountState currentState;

public:
	inline EncountState GetState() { return currentState; }
};