#include "Area.h"

Queue<Lane*> Area::Maintainence_Lanes;

// Constructor
Area::Area() : ID(0), LN(0), distances(nullptr) {}

// Destructor (if needed)
Area::~Area()
{
    // Add necessary cleanup, e.g., deleting dynamic memory
    delete[] distances;
}

// Getters
int Area::getID() const
{
    return ID;
}

int Area::getLN() const
{
    return LN;
}

int* Area::getDistances() const
{
    return distances;
}

Array<Lane*> Area::getVIPLanes()
{
    return VIP_LANES;
}

Array<Lane*> Area::getNormalLanes()
{
    return NORMAL_LANES;
}

Queue<Flight*>& Area::getWaitingQueue()
{
    return WAITING_VIP_QUEUE;
}

Flight* Area::getFlightByNumber(int number)
{
    if (WAITING_NORMAL_QUEUE.empty())
    {
        std::cout << "Waiting Queue of Area No. " << ID << " is empty!\n";
        return nullptr;
    }
    else 
    {
        for (int i = 0; i < WAITING_NORMAL_QUEUE.size(); i++)
        {
            ////TODO
            if (WAITING_NORMAL_QUEUE.at(i)!= nullptr)
            {
                if (WAITING_NORMAL_QUEUE.at(i)->getNumber() == number)
                {
                    std::cout << WAITING_NORMAL_QUEUE.at(i)->getNumber() << std::endl;

                    return WAITING_NORMAL_QUEUE.at(i);
                    break;
                }
            }
            else
            {
                return nullptr;
            }
        }
    }

}

int Area::get_flight_index_by_id(int number,char type)
{
    if (type == 'N' && !WAITING_NORMAL_QUEUE.empty())
    {
        for (int i = 0; i < WAITING_NORMAL_QUEUE.size(); i++)
        {
            if (WAITING_NORMAL_QUEUE.at(i)->getNumber() == number)
            {
                return i;
            }
        }
    }
    else if(type == 'V' && !WAITING_VIP_QUEUE.empty())
    {
        for (int i = 0; i < WAITING_VIP_QUEUE.size(); i++)
        {
            if (WAITING_VIP_QUEUE.at(i)->getNumber() == number)
            {
                return i;
            }
        }
    }
    else
    {
        return NULL;
    }
}


// Setters
void Area::setID(int newID)
{
    ID = newID;
}

void Area::setLN(int newLN)
{
    LN = newLN;
}

void Area::setDistances(int* newDistances)
{
    // Assuming you want to manage memory for distances
    // You might want to add more checks and memory management as needed
    delete[] distances;
    distances = newDistances;
}

void Area::setNormalLanes(Array<Lane*> value)
{
    NORMAL_LANES = value;
}

void Area::setVIPLanes(Array<Lane*> value)
{
    VIP_LANES = value;
}

void Area::addNORMAL_LANE(Lane* p_lane)
{
    NORMAL_LANES.push_back(p_lane);
}

void Area::addVIP_LANE(Lane* p_lane)
{
    VIP_LANES.push_back(p_lane);
}

void Area::addFlight(Flight* p_flight,char type)
{
    if (type == 'N')
        WAITING_NORMAL_QUEUE.push(p_flight);
    else
        WAITING_VIP_QUEUE.push(p_flight);
}

void Area::trans_promoted(int index)
{
    Flight* p_flight = WAITING_NORMAL_QUEUE.at(index);
    WAITING_VIP_QUEUE.push(p_flight);
    WAITING_NORMAL_QUEUE.popAt(index);
}

void Area::pop_by_index(int index,char type )
{
    if (type == 'N')
    {
        WAITING_NORMAL_QUEUE.popAt(index);
    }
    else
    {
        WAITING_VIP_QUEUE.popAt(index);
    }
}

// Implementation of onboard method
void Area::onboard(int flightNumber) {
    // Implement the onboard logic here
    // You can access the necessary data members using getters and modify them accordingly
}

// Implementation of fly method
void Area::fly(int flightNumber) {
    // Implement the fly logic here
    // You can access the necessary data members using getters and modify them accordingly
}

// Implementation of offBboard method
void Area::offBboard(int flightNumber) {
    // Implement the offBboard logic here
    // You can access the necessary data members using getters and modify them accordingly
}

// Implementation of arrive method
void Area::arrive(int flightNumber) {
    // Implement the arrive logic here
    // You can access the necessary data members using getters and modify them accordingly
}

// Implementation of operate method
void Area::operate(int flightNumber) {
    std::cout << "Area No. " << this->getID() << " is operating.............\n";

    while (!WAITING_NORMAL_QUEUE.empty())
    {
        std::cout << "Area ID: " << ID << "FLihgt ID:" << WAITING_NORMAL_QUEUE.at(0)->getID() << std::endl;
        WAITING_NORMAL_QUEUE.popAt(0);
    }
}

void Area::printNL()
{
    std::cout << "Normal Lanes: of Area: " << ID << "\n";
    for (size_t i = 0; i < NORMAL_LANES.size(); i++)
    {
        std::cout << "Area ID: " << NORMAL_LANES[i]->getAreaID()
            << " Type: " << NORMAL_LANES[i]->getType() << "\n";
    }
}

void Area::printVL()
{
    std::cout << "VIP Lanes: of Area: " << ID << "\n";
    for (size_t i = 0; i < VIP_LANES.size(); i++)
    {
        std::cout << "Area ID: " << VIP_LANES[i]->getAreaID()
            << " Type: " << VIP_LANES[i]->getType() << "\n";
    }
}
