#include "TabEvent.h"

#include "../graphics/TabSet.h"

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
	Tab mainTab	(Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadMainTabSprite()),	 TABS::MAIN_TAB_ID);
	Tab otherTab(Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadOtherTabSprite()),	 TABS::OTHER_TAB_ID);
	Tab lastTab	(Drawable::spriteSheet->getSprite(Drawable::spriteSheet->loadLastTabSprite()),	 TABS::LAST_TAB_ID);

	mainTab. setVisibility(true);
	otherTab.setVisibility(true);
	lastTab. setVisibility(true);

	ts->addTab(mainTab);
	ts->addTab(otherTab);
	ts->addTab(lastTab);
}
