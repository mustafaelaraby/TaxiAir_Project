#pragma once
#include <string>
#include <iostream>

class Flight
{
private:
    int number, TS, DA, AA, passengers, WT, ST, FT, priority;
    std::string ID;
    char type, state;
    int stepOnboard = 0, stepFly = 0, stepOffboard = 0;
    bool prometed = false;
    bool cancelled = false;
public:
    // Constructors
    Flight();
    Flight(std::string ID, int TS, int DA, int AA, int passengers, char type, char state);

    // Getters
    std::string getID() const;
    int getNumber()const;
    int getTS() const;
    int getDA() const;
    int getAA() const;
    int getPassengers() const;
    int getWT() const;
    int getST() const;
    int getFT() const;
    int getStepOnboard() const;
    int getStepFly() const;
    int getStepOffboard() const;
    bool isPromoted()const;
    bool isCancelled()const;
    int getPriority()const;

    char getType() const;
    char getState() const;

    // Setters
    void setID(std::string newID);
    void setNumber(int newNumber);
    void setTS(int newTS);
    void setDA(int newDA);
    void setAA(int newAA);
    void setPassengers(int newPassengers);
    void setWT(int newWT);
    void setST(int newST);
    void setFT(int newFT);
    void setStepOnboard(int);
    void setStepFly(int);
    void setStepOffboard(int);
    void setType(char newType);
    void setState(char newState);
    void setPriority(int);
    void promote();
    void cancel();

    void parse_flight_ID(int&, int&, int&, char&);
};
