#include "Promote_Event.h"

// Constructors
Promote_Event::Promote_Event(int newTimeStamp, std::string newID) : Event(newTimeStamp, newID) {}


// Member function to get time stamp
int Promote_Event::getTimeStamp() const
{
    return time_stamp;
}

// Member function to get ID
std::string Promote_Event::getID() const
{
    return ID;
}

// Member function to perform cancellation
void Promote_Event::promote(Flight* p_flight)
{
    if (p_flight == nullptr)
        std::cout << "Flight may not arrive or may left.\n";
    else
        p_flight->promote();
}
