#include "Cancel_Event.h"

// Constructors
Cancel_Event::Cancel_Event(int newTimeStamp, std::string newID) : Event(newTimeStamp, newID) {}


// Member function to get time stamp
int Cancel_Event::getTimeStamp() const
{
    return time_stamp;
}

// Member function to get ID
std::string Cancel_Event::getID() const
{
    return ID;
}

// Member function to perform cancellation
void Cancel_Event::cancel(Flight* p_flight)
{
    p_flight->cancel();
}
