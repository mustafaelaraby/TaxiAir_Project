#include "App.h"



App::App()
{
	p_scheduler = new Scheduler();
	p_gui = new GUI();
}

App::~App()
{
	delete p_scheduler;
	delete p_gui;
}

void App::run() {
	fetch(p_gui->getFile());
	p_scheduler->start();
	for (size_t step = 0; step < 10; step++)
	{
		std::cout << "=============== === " << step << " === ===============\n";
		p_scheduler->manage(step);
	}
}

void App::fetch(std::string filename)
{
	std::filesystem::path currentDir = std::filesystem::current_path();
	std::string currentDirStr = currentDir.string();
	std::string file = currentDirStr + "\\docs\\input\\" + filename + ".txt";
	input.open(file.c_str());

	if (input.fail())
	{
		std::cout << "File does not exist" << std::endl;
		std::cout << "Exit program" << std::endl;
	}

	int A, TD, LD, PBT, POT;
	input >> A >> TD >> LD >> PBT >> POT;

	p_scheduler->setA(A);
	p_scheduler->setTD(TD);
	p_scheduler->setLD(LD);
	p_scheduler->setPBT(PBT);
	p_scheduler->setPOT(POT);


	std::cout << "A: " << A << ", TD: " << TD << ", LD: " << LD 
			  << ", PBT: " << PBT << ", POT: " << POT << std::endl;

	
	Area** Areas = new Area * [A];
	
	int tempLN;
	int tempID = 1;
	for (int i = 0; i < A; i++)
	{
		int* tempDist = new int[A - 1];
		input >> tempLN;
		LN_count += tempLN;
		Areas[i] = new Area;
		for (int j = 0; j < A - 1; j++)
		{
			input >> tempDist[j];
		}
		Areas[i]->setDistances(tempDist);
		Areas[i]->setID(tempID++);
		Areas[i]->setLN(tempLN);
	}
	p_scheduler->addAreas(Areas);
	p_scheduler->setTotalLN(LN_count);
	p_scheduler->printAreas();

	int tempAreaID, tempAvt, tempMA, tempMT;
	char tempType;

	for (int i = 0; i < LN_count; i++)
	{
		Lane* p_lane = new Lane();
		input >> tempAreaID >> tempType >> tempAvt >> tempMA >> tempMT;
		p_lane->setAll(tempAreaID, tempType, tempAvt, tempMA, tempMT);
		p_scheduler->addLane(p_lane);
	}

	//p_scheduler->printLanes();


	int autoP, numEvt;

	input >> autoP;	p_scheduler->setAutoP(autoP);
	input >> numEvt; p_scheduler->setNumEvt(numEvt);

	std::cout << " autoP: " << autoP << " numEvt: " << numEvt << std::endl;

	char EvtType;
	char tempTypeFlight;
	int tempTS, tempPass,tempDA,tempAA;
	std::string tempIDFlight;

	for (size_t i = 0; i < numEvt; i++)
	{
		input >> EvtType;
		if (EvtType == 'B')
		{
			input >> tempTypeFlight >> tempTS >> tempIDFlight >> tempPass >> tempDA >> tempAA;
			Event* p_b_event = new Book_Event(tempTypeFlight, tempTS, tempIDFlight, tempPass,tempDA,tempAA);
			p_scheduler->addEvent(p_b_event);
		}
		else if (EvtType == 'X')
		{
			input >> tempTS >> tempIDFlight;
			Event* p_c_event = new Cancel_Event(tempTS, tempIDFlight);
			p_scheduler->addEvent(p_c_event);
		}
		else
		{
			input >> tempTS >> tempIDFlight;
			Event* p_p_event = new Promote_Event(tempTS, tempIDFlight);
			p_scheduler->addEvent(p_p_event);
		}

	}
	//p_scheduler->printEvents();
}