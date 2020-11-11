#include "Tab.h"

#include "../events/EventHandler.h"
#include "SpriteTexture.h"

#include "../events/StateEvent.h"

//Tab::Tab(SpriteTexture* sprite, int stateID)
//{
//	this->sprite = sprite;
//	this->stateID = stateID;
//}

void Tab::click()
{
	eh->addEvent(new StateEvent(stateID, STATE_EVENT_TYPE::CHANGE));
}

void Tab::setVisibility(bool visible)
{
	this->visible = visible;
}
