#include "Book_Event.h"


// Parameterized Constructor
Book_Event::Book_Event(char newFlightType, int newTimeStamp, std::string newID,  int newPassengers, int newDA, int newAA)
    : Event(newTimeStamp, newID), Flight_Type(newFlightType), passengers(newPassengers),DA(newDA),AA(newAA){}


// Getters

int Book_Event::getTimeStamp() const
{
    return time_stamp;
}


std::string Book_Event::getID()const
{
    return ID;
}

char Book_Event::getFlightType() const
{
    return Flight_Type;
}

int Book_Event::getPassengers() const
{
    return passengers;
}

int Book_Event::getDA() const {
    return DA;
}


int Book_Event::getAA() const {
    return AA;
}


// Setters

void Book_Event::setFlightType(char newFlightType)
{
    Flight_Type = newFlightType;
}


void Book_Event::setPassengers(int newPassengers)
{
    passengers = newPassengers;
}


void Book_Event::setDA(int newDA) {
    DA = newDA;
}


void Book_Event::setAA(int newAA) {
    AA = newAA;
}


Flight* Book_Event::book()
{
    Flight* p_flight = new Flight(this->getID(), this->getTimeStamp(),
        this->getDA(), this->getAA(), this->getPassengers(), this->getFlightType(), 'B');
    return p_flight;
}
