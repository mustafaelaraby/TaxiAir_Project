// Scheduler.cpp

#include "Scheduler.h"



// Getters
int Scheduler::getA() const {
    return A;
}

int Scheduler::getTD() const {
    return TD;
}

int Scheduler::getLD() const {
    return LD;
}

int Scheduler::getPBT() const {
    return PBT;
}

int Scheduler::getPOT() const {
    return POT;
}

int Scheduler::getTotalLN()const
{
    return totalLN;
}

int Scheduler::getAutoP()const
{
    return autoP;
}

int Scheduler::getNumEvt()const
{
    return numEvt;
}

// Setters
void Scheduler::setA(int value) {
    A = value;
}

void Scheduler::setTD(int value) {
    TD = value;
}

void Scheduler::setLD(int value) {
    LD = value;
}

void Scheduler::setPBT(int value) {
    PBT = value;
}

void Scheduler::setPOT(int value) {
    POT = value;
}

void Scheduler::setTotalLN(int value)
{
    totalLN = value;
}

void Scheduler::setAutoP(int value)
{
    autoP = value;
}

void Scheduler::setNumEvt(int value)
{
    numEvt = value;
}

void Scheduler::addAreas(Area** p_areas)
{
    AREAS = p_areas;
}

void Scheduler::addEvent(Event* p_event)
{
    EVENTS.push(p_event);
}

void Scheduler::addLane(Lane* p_lane)
{
    Lanes.push(p_lane);
}

Area* Scheduler::getAreaByID(int id)
{
    auto it = std::find_if(AREAS, AREAS + A,
        [id](const Area* area) {
            return area->getID() == id;
        });

    if (it != AREAS + A) {
        return *it;
    }
    else {
        return nullptr;
    }
}
        
void Scheduler::start()
{
    for (size_t i = 0; i < A; i++)
    {
        while (!Lanes.empty())
        {
            if (AREAS[i]->getID() == Lanes.front()->getAreaID())
            {
                if (Lanes.front()->getType() == 'N')
                {
                    AREAS[i]->addNORMAL_LANE(Lanes.front());
                    Lanes.pop();
                }
                else
                {
                    AREAS[i]->addVIP_LANE(Lanes.front());
                    Lanes.pop();
                }
            }
            else 
            {
                break;
            }
        }

    }

    for (size_t i = 0; i < A; i++)
    {
        AREAS[i]->printNL();
        AREAS[i]->printVL();
    }
}


void Scheduler::manage(int step) {
    // Implementation for the manage function
    // Perform the management tasks

    while (!EVENTS.empty() && EVENTS.front()->getTimeStamp()==step)
    {
        if (typeid(*EVENTS.front()) == typeid(Book_Event))
        {
            Book_Event* pb = dynamic_cast<Book_Event*>(EVENTS.front());
            int area_id = pb->getDA();
            char type = pb->getFlightType();
            
            Area* p_area = getAreaByID(area_id);
            if (p_area == nullptr)
            {
                std::cout << "No area available with this id!";
            }
            else
            {
                switch (type)
                {
                case 'N': p_area->addFlight(pb->book(), 'N'); break;
                case 'V': p_area->addFlight(pb->book(), 'V'); break;
                default:
                    break;
                }
            }


            EVENTS.pop();
            delete pb;
        }
        else if(typeid(*EVENTS.front()) == typeid(Promote_Event))
        {
            Promote_Event* pp = dynamic_cast<Promote_Event*>(EVENTS.front());
            std::cout << "Promote event: " << pp->getID();
            //int da, number, aa;
            //char type;
            //pp->parse_flight_ID(da, number, aa, type);
            //Area* p_area = getAreaByID(da);
            //Flight* p_flight = p_area->getFlightByNumber(number);
            //int index = p_area->get_flight_index_by_id(number, 'N');
            //pp->promote(p_flight);
            //p_area->trans_promoted(index);               
            EVENTS.pop();
            delete pp;
        }
        else
        {
            Cancel_Event* pc = dynamic_cast<Cancel_Event*>(EVENTS.front());
            std::cout << "Cancel event: " << pc->getID();
            //int da, number, aa;
            //char type;
            //pc->parse_flight_ID(da, number, aa, type);
            //Area* p_area = getAreaByID(da);
            //Flight* p_flight = p_area->getFlightByNumber(number);
            //pc->cancel(p_flight);
            //std::cout << "\n LLLLL \n";
            //if (type == 'N')
            //{
            //    int index = p_area->get_flight_index_by_id(number, 'N');
            //    p_area->pop_by_index(index, 'N');
            //}
            //else
            //{
            //    int index = p_area->get_flight_index_by_id(number, 'V');
            //    p_area->pop_by_index(index, 'V');
            //}

            EVENTS.pop();
            delete pc;
        }

    }

    if (step == 9)
    {
        for (size_t i = 0; i < A; i++)
        {
            AREAS[i]->operate(step);
        }
    }


}

void Scheduler::distribute() {
    // Implementation for the distribute function
    // Perform the distribution tasks
}

void Scheduler::printAreas() {
    std::cout << "Areas: " << std::endl;
    for (size_t i = 0; i < A; ++i) {
        std::cout << "Area ID: " << AREAS[i]->getID() << ", LN: " << AREAS[i]->getLN() << ", Distances: ";

        const auto& distances = AREAS[i]->getDistances();
        for (size_t j = 0; j < A - 1; ++j) {
            std::cout << distances[j];
            if (j < A - 2) {
                std::cout << ", ";
            }
        }

        std::cout << std::endl;
    }
}

void Scheduler::printEvents()
{
    std::cout << "Events: " << std::endl;
    while (!EVENTS.empty())
    { 
        if (typeid(*(EVENTS.front())) == typeid(Book_Event))
        {
            Book_Event* pb = dynamic_cast<Book_Event*>(EVENTS.front());
            std::cout << " Evt ID: " << pb->getID()
                << " Evt timeStmp: " << pb->getTimeStamp() 
                << " DA: " << pb->getDA() << " AA: " << pb->getAA() << std::endl;
            EVENTS.pop();
            delete pb;
        }
        else
        {
            std::cout << " Evt ID: " << EVENTS.front()->getID()
                << " Evt timeStmp: " << EVENTS.front()->getTimeStamp() << std::endl;
            EVENTS.pop();

        }

    }
}

void Scheduler::printLanes()
{
    std::cout << "Lanes: " << std::endl;
    while (!Lanes.empty())
    {
        std::cout << " Lane Area ID: " << Lanes.front()->getAreaID()
            << " Type: " << Lanes.front()->getType() << std::endl;
        Lanes.pop();
    }
}

