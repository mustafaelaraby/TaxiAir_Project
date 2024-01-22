#pragma once
#include "../../lib/Array/Array.h"
#include "../../lib/Priority_Queue/Priority_Queue.h"
#include "../Flight/Flight.h"
#include "../../lib/Queue/Queue.h"
#include "../Lane/Lane.h"


struct _priority_ {
	bool operator()(const Flight* flight1, const Flight* flight2) const {
        return flight1->getPriority() > flight2->getPriority();
	}
};

//pass,ts;
//priority = 0.6(Ts) + 0.4(pass);

class Area
{
private:
    int ID, LN;
    int* distances;
    //-->  -->  -->  --> --> done after.
    Array<Lane*> VIP_LANES;
    Array<Lane*> NORMAL_LANES;
    Queue<Flight*> WAITING_VIP_QUEUE;
    Priority_Queue<Flight*, _priority_> WAITING_NORMAL_QUEUE;
    static Queue<Lane*> Maintainence_Lanes;

public:
    // Constructor and Destructor (if needed)
    Area();
    ~Area();

    // Getters
    int getID() const;
    int getLN() const;
    int* getDistances() const;
    int get_flight_index_by_id(int,char);

    Array<Lane*> getVIPLanes();
    Array<Lane*> getNormalLanes();
    Queue<Flight*>& getWaitingQueue();
    Flight* getFlightByNumber(int);
    

    // Setters
    void setID(int newID);
    void setLN(int newLN);
    void setDistances(int* newDistances);
    void setVIPLanes(Array<Lane*>);
    void setNormalLanes(Array<Lane*>);


    void addNORMAL_LANE(Lane*);
    void addVIP_LANE(Lane*);
    void addFlight(Flight*,char type);
    void trans_promoted(int);
    void pop_by_index(int,char);

    void onboard(int);
    void fly(int);
    void offBboard(int);
    void arrive(int);
    void operate(int);

    void printNL();
    void printVL();
};
