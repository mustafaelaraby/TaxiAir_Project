#pragma once

#include "../Event.h"
#include "../../Flight/Flight.h"


class Promote_Event :public Event
{


public:
	Promote_Event(int newTimeStamp, std::string newID);
	int getTimeStamp()const;
	std::string getID()const;

	void promote(Flight*);
};