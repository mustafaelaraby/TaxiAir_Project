#include "Flight.h"

// Default Constructor
Flight::Flight() 
    : ID(0), TS(0), DA(0), AA(0), passengers(0), WT(0), ST(0),FT(0), stepOnboard(0), 
      stepFly(0), stepOffboard(0), type('\0'), state('\0'){}

// Parameterized Constructor
Flight::Flight(std::string newID, int newTS, int newDA, int newAA, int newPassengers, char newType, char newState)
    : ID(newID), TS(newTS), DA(newDA), AA(newAA), passengers(newPassengers),
      WT(0), ST(0), FT(0), type(newType), state(newState)
{
    priority = 0.3 * (TS)+ 0.7 * (passengers);
    std::cout<< std:: endl;
    std::cout << "--> --> " << priority << std::endl;
}

// Getters
std::string Flight::getID() const
{
    return ID;
}

int Flight::getNumber()const
{
    return number;
}

int Flight::getTS() const
{
    return TS;
}

int Flight::getDA() const
{
    return DA;
}

int Flight::getAA() const
{
    return AA;
}

int Flight::getPassengers() const
{
    return passengers;
}

int Flight::getWT() const
{
    return WT;
}

int Flight::getST() const
{
    return ST;
}

int Flight::getFT() const
{
    return FT;
}

int Flight::getStepOnboard() const
{
    return stepOnboard;
}

int Flight::getStepFly() const
{
    return stepFly;
}

int Flight::getStepOffboard() const
{
    return stepOffboard;
}

char Flight::getType() const
{
    return type;
}

char Flight::getState() const
{
    return state;
}

bool Flight::isPromoted()const
{
    return prometed;
}

bool Flight::isCancelled()const
{
    return cancelled;
}

int Flight:: getPriority()const
{
    return priority;
}



// Setters
void Flight::setID(std::string newID)
{
    ID = newID;
}

void Flight::setNumber(int newNumber)
{
    number = newNumber;
}

void Flight::setTS(int newTS)
{
    TS = newTS;
}

void Flight::setDA(int newDA)
{
    DA = newDA;
}

void Flight::setAA(int newAA)
{
    AA = newAA;
}

void Flight::setPassengers(int newPassengers)
{
    passengers = newPassengers;
}

void Flight::setWT(int newWT)
{
    WT = newWT;
}

void Flight::setST(int newST)
{
    ST = newST;
}

void Flight::setFT(int newFT)
{
    FT = newFT;
}

void Flight::setStepOnboard(int newStepOnboard)
{
    stepOnboard = newStepOnboard;
}

void Flight::setStepFly(int newStepFly)
{
    stepFly = newStepFly;
}

void Flight::setStepOffboard(int newStepOffboard)
{
    stepOffboard = newStepOffboard;
}


void Flight::setType(char newType)
{
    type = newType;
}

void Flight::setState(char newState)
{
    state = newState;
}

void Flight::setPriority(int pr)
{
    priority = pr;
}

void Flight::promote()
{
    prometed = true;
}

void Flight::cancel()
{
    cancelled = true;
}

void Flight::parse_flight_ID(int& da, int& id, int& aa, char& type)
{
    std::string sub1 = this->getID().substr(1, 2);
    std::string sub2 = this->getID().substr(3, 3);
    std::string sub3 = this->getID().substr(7, 2);
    type = this->getID().back();

    da = std::stoi(sub1);
    id = std::stoi(sub2);
    aa = std::stoi(sub3);
}
