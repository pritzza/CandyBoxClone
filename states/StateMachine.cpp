#include "../../src/states/StateMachine.h"

StateMachine::~StateMachine()
{
	for (auto it = states.begin(); it != states.end(); ++it)
		removeState(it->first);
}

void StateMachine::processStateChange()
{
	if (isRemoving)
	{
		if (states.find(removeID) != states.end())	// dont delete something that isnt in the unordered map
		{
			delete states.at(removeID);
			states.erase(removeID);
		}

		isRemoving = false;
		removeID = STATE::NULL_STATE;
	}

	if (isAdding)
	{
		// only insert if its not already there
		if (states.find(addID) == states.end())
			states.insert({ addID, tempState });

		isAdding = false;
		addID = STATE::NULL_STATE;

		tempState = nullptr;
	}

	if (tempID != STATE::NULL_STATE)
	{
		currentStateID = tempID;
		tempID = STATE::NULL_STATE;
	}
}

void StateMachine::setState(int id)
{
	if (states.find(id) != states.end())	// dont set the state to something that doesnt exist yet
		this->tempID = id;
}

State* StateMachine::currentState()
{
	if (states.at(currentStateID) != nullptr)
		return states.at(currentStateID);

	return nullptr;
}

int StateMachine::getCurrentStateID()
{
	return this->currentStateID;
}

void StateMachine::addState(State* s, int id)
{
	if (s != nullptr)
	{
		this->isAdding = true;
		this->addID = id;
		tempState = s;
	}
}

void StateMachine::removeState(int id)
{
	isRemoving = true;
	removeID = id;
}
