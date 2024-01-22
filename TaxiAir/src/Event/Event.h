#pragma once
#include <iostream>
#include <string>
#include <stdexcept>


class Event
{
protected:
    int time_stamp;
    std::string ID;

public:
    // Constructors
    Event();
    Event(int newTimeStamp, std::string newID) 
    {
        time_stamp = newTimeStamp;
        ID = newID;
    }
    virtual ~Event() {}; // Declare the destructor as virtual for an abstract class

    // Getters
    virtual int getTimeStamp() const =0;
    virtual std::string getID() const =0;
    virtual void parse_flight_ID(int& da, int& id, int& aa, char& type) const
    {
        std::string sub1 = this->getID().substr(1, 2);
        std::string sub2 = this->getID().substr(3, 3);
        std::string sub3 = this->getID().substr(7, 2);
        type = this->getID().back();

        da = std::stoi(sub1);
        id = std::stoi(sub2);
        aa = std::stoi(sub3);
    }

};
