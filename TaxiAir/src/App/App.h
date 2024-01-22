#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>

#include "../../lib/Queue/Queue.h"


#include "../Event/Event.h"
#include "../Event/Book_Event/Book_Event.h"
#include "../Event/Cancel_Event/Cancel_Event.h"
#include "../Event/Promote_Event/Promote_Event.h"
#include "../Scheduler/Scheduler.h"
#include "../GUI/GUI.h"
#include "../Area/Area.h"
#include "../Lane/Lane.h"

class App {

	Scheduler* p_scheduler;
	GUI* p_gui;
	std::ifstream input;
	int LN_count = 0;

public:
	App();
	~App();

	void fetch(std::string);
	void run();

};