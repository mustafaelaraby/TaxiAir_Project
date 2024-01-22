#include "Lane.h"

// Constructor
Lane::Lane() : type('\0'), avt(0), MA(0), MT(0), AreaID(0), state('\0')
{
}

Lane::Lane(int newAreaID,char newType, int newAvt, int newMA, int newMT)
    : type(newType), avt(newAvt), MA(newMA), MT(newMT), AreaID(newAreaID)
{
}

// Destructor (if needed)
Lane::~Lane()
{
    // Add necessary cleanup, if any
}

// Getters
char Lane::getType() const {
    return type;
}

int Lane::getAvt() const {
    return avt;
}

int Lane::getMA() const {
    return MA;
}

int Lane::getMT() const {
    return MT;
}

int Lane::getAreaID() const {
    return AreaID;
}

int Lane::getStepAvt() const {
    return stepAvt;
}

int Lane::getCountFlight() const {
    return countflight;
}

int Lane::getStepMaintain() const {
    return stepMaintain;
}

char Lane::getState() const {
    return state;
}



Flight* Lane::get_current_flight()const
{
    return current_flight;
}

// Setters
void Lane::setType(char newType) {
    type = newType;
}

void Lane::setAvt(int newAvt) {
    avt = newAvt;
}

void Lane::setMA(int newMA) {
    MA = newMA;
}

void Lane::setMT(int newMT) {
    MT = newMT;
}

void Lane::setAreaID(int newAreaID) {
    AreaID = newAreaID;
}

void Lane::setStepAvt(int newStepAvt) {
    stepAvt = newStepAvt;
}

void Lane::setCountFlight(int newCountFlight) {
    countflight = newCountFlight;
}

void Lane::setStepMaintain(int newStepMaintain) {
    stepMaintain = newStepMaintain;
}

void Lane::setState(char newState) {
    state = newState;
}


void Lane::setAll(int newAreaID, char newType, int newAvt, int newMA, int newMT)
{
    type = newType;
    avt = newAvt;
    MA = newMA;
    MT = newMT;
    AreaID = newAreaID;
}