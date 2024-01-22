#pragma once

#include <iostream>
#include <type_traits>
#include <algorithm>
#include <stdexcept>



#include "../Event/Event.h"
#include "../Event/Book_Event/Book_Event.h"
#include "../Event/Cancel_Event/Cancel_Event.h"
#include "../Event/Promote_Event/Promote_Event.h"
#include "../Area/Area.h"



class Scheduler
{
    int A, TD, LD, PBT, POT;
    int totalLN;
    int autoP;
    int numEvt;

    //Done after
    Area** AREAS = nullptr;
    Queue<Event*> EVENTS;
    Queue<Lane*> Lanes;



public:

    // Getters
    int getA() const;
    int getTD() const;
    int getLD() const;
    int getPBT() const;
    int getPOT() const;
    int getTotalLN()const;
    int getAutoP()const;
    int getNumEvt()const;

    // Setters
    void setA(int value);
    void setTD(int value);
    void setLD(int value);
    void setPBT(int value);
    void setPOT(int value);
    void setTotalLN(int value);
    void setAutoP(int value);
    void setNumEvt(int value);

    void addAreas(Area**);
    void addEvent(Event*);
    void addLane(Lane*);

    Area* getAreaByID(int);

    void start();
    void manage(int);
    void distribute();
    void printAreas();
    void printEvents();
    void printLanes();

};