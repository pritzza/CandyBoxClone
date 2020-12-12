#pragma once

#include "Text.h"

class Resources;

class ResourcesTab
{
public:
	Resources& r;
	//Text t;

public:
	ResourcesTab(Resources& r) : r(r) {}
};