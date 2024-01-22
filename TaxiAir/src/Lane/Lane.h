#pragma once
#include "../Flight/Flight.h"

class Lane
{
private:
    Flight* current_flight;
    char type;
    int avt, MA, MT, AreaID;
    char state;
    int stepAvt = 0, countflight = 0, stepMaintain = 0;
    bool available = false;

public:
    // Constructor and Destructor (if needed)
    Lane();
    Lane(int newAreaID, char newType, int newAvt, int newMA, int newMT);
    ~Lane();

    // Getters
    char getType() const;
    int getAvt() const;
    int getMA() const;
    int getMT() const;
    int getAreaID() const;
    int getStepAvt() const;
    int getCountFlight() const;
    int getStepMaintain() const;
    char getState() const;
    Flight* get_current_flight()const;

    // Setters
    void setType(char newType);
    void setAvt(int newAvt);
    void setMA(int newMA);
    void setMT(int newMT);
    void setAreaID(int newAreaID);
    void setStepAvt(int newStepAvt);
    void setCountFlight(int newCountFlight);
    void setStepMaintain(int newStepMaintain);
    void setState(char newState);
    void set_current_flight(Flight*);
    void setAll(int newAreaID, char newType, int newAvt, int newMA, int newMT);

};
