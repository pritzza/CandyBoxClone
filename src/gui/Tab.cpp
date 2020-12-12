#include "Tab.h"

#include "../events/EventHandler.h"
#include "../graphics/SpriteTexture.h"

#include "../events/StateEvent.h"

void Tab::click()
{
	eh->addEvent(new StateEvent(stateID, STATE_EVENT_TYPE::CHANGE));
}

void Tab::setVisibility(bool visible)
{
	this->visible = visible;
}
