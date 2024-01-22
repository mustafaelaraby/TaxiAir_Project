#include <iostream>
#include "src/App/App.h"
#include "lib/Priority_Queue/Priority_Queue.h"
#include "src/Flight/Flight.h"

//struct TT_less {
//	bool operator()(const Flight* process1, const Flight* process2) const {
//		return process1->getNumber() < process2->getNumber();
//	}
//};

int main()
{
	//Flight* flight1 = new Flight("hjb",2,2,5,3,'N','B');
	//flight1->setNumber(15);

	//Flight* flight2 = new Flight("hjb", 2, 2, 5, 3, 'N', 'B');
	//flight2->setNumber(12);

	//Flight* flight3 = new Flight("hjb", 2, 2, 5, 3, 'N', 'B');
	//flight3->setNumber(13);

	//Flight* flight4 = new Flight("hjb", 2, 2, 5, 3, 'N', 'B');
	//flight4->setNumber(24);

	//Priority_Queue<Flight*, TT_less> flights;
	//flights.push(flight1);
	//flights.push(flight2);
	//flights.push(flight3);
	//flights.push(flight4);

	//flights.show();
	//int i = 0;
	//while (!flights.empty())
	//{

	//	std::cout << flights.at(0)->getNumber() << " ";
	//	flights.popAt(0);
	//	i++;
	//}

	App app;
	app.run();
}