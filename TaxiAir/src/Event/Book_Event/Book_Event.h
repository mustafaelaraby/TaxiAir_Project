#pragma once
#include "../Event.h"
#include "../../Flight/Flight.h"

class Book_Event : public Event
{
private:
    char Flight_Type;
    int passengers, DA, AA;

public:
    // Constructors
    Book_Event(char newFlightType, int newTimeStamp, std::string newID, int newPassengers,int newDA,int newAA);

    // Getters
    int getTimeStamp() const;
    std::string getID() const;
    char getFlightType() const;
    int getPassengers() const;
    int getDA() const;
    int getAA() const;

    // Setters
    void setFlightType(char newFlightType);
    void setPassengers(int newPassengers);
    void setDA(int newDA);
    void setAA(int newAA);

    Flight* book();

};
