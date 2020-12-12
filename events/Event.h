#pragma once

class Event
{
public:
	void virtual handleEvent() = 0;
};