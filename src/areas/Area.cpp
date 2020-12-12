#include "Area.h"

#include "../states/State.h"

void Area::loadArea(int id)
{

	switch (id)
	{
	case STATE::BATTLE_TEST_STATE:
		this->tileSet.loadTest();


		break;
	}
}