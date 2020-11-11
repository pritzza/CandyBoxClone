#pragma once

#include <unordered_map>

#include "../../src/states/State.h"

class StateMachine
{
public:
	std::unordered_map<int, State*> states;
	State* tempState;

protected:
	unsigned int currentStateID{ STATE::MAIN };
	unsigned int tempID{ STATE::NULL_STATE };

	// for keeping track of which state to add, remove, and flags on when to do so
	unsigned int removeID{ STATE::NULL_STATE };
	unsigned int addID{ STATE::NULL_STATE };
	bool isAdding{ false };
	bool isRemoving{ false };

public:
	~StateMachine();

	void processStateChange();	// goes through queue of changes

	State* currentState();
	int getCurrentStateID();

	void setState(int id);				// queue up for a change in current state
	void addState(State* s, int id);	// queue up for the addition/allocation of a new state
	void removeState(int id);			// queue up the deletion/deallocation of an existing state

};