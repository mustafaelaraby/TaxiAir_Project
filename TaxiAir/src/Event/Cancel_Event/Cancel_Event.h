#pragma once
#include "../Event.h"
#include "../../Flight/Flight.h"


class Cancel_Event :public Event
{


public:
	Cancel_Event(int newTimeStamp, std::string newID);
	int getTimeStamp()const;
	std::string getID()const;

	void cancel(Flight*);
};