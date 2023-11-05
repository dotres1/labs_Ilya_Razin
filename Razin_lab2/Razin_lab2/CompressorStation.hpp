#pragma once
#include <string>

class CompressorStation {
public:
    CompressorStation(const std::string& name, int numWorkshops, int numWorkshopsInOperation, double efficiency);
    const std::string& getName() const;
    int generateUniqueID();
    int getNumWorkshops() const;
    int getNumWorkshopsInOperation() const;
    double getEfficiency() const;
    int getUniqueID() const;
    void startWorkshop();
    void stopWorkshop();

private:
    std::string name;
    int numWorkshops;
    int numWorkshopsInOperation;
    double efficiency;
    int uniqueID;
};


