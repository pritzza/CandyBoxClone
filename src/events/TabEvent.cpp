#include "TabEvent.h"

#include "../gui/TabSet.h"

#include "../graphics/SpriteSheet.h"

void TabEvent::handleEvent()
{
	switch (actionType)
	{
	case TAB_EVENT_TYPE::ADD_STARTING_TABS:
		addStartingTabs();
		break;
	}
}

void TabEvent::addStartingTabs()
{
	Tab mainTab ( Drawable::spriteSheet->getSprite( Drawable::spriteSheet->loadSprite(SPRITE::MAIN_TAB_SPRITE )),	TABS::MAIN_TAB_ID);
	Tab otherTab( Drawable::spriteSheet->getSprite( Drawable::spriteSheet->loadSprite(SPRITE::OTHER_TAB_SPRITE)),	TABS::OTHER_TAB_ID);
	Tab lastTab ( Drawable::spriteSheet->getSprite( Drawable::spriteSheet->loadSprite(SPRITE::LAST_TAB_SPRITE)),	TABS::LAST_TAB_ID);
	
	mainTab. setVisibility(true);
	otherTab.setVisibility(true);
	lastTab. setVisibility(true);
	
	ts->addTab(mainTab);
	ts->addTab(otherTab);
	ts->addTab(lastTab);
}
