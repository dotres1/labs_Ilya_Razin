#pragma once
#include <string>

class Pipe {
public:
    Pipe(const std::string& name, double length, double diameter);
    const std::string& getName() const;
    int generateUniqueID();
    double getLength() const;
    double getDiameter() const;
    bool isInRepair() const;
    void setInRepair(bool inRepair);
    int getUniqueID() const;

private:
    std::string name;
    double length;
    double diameter;
    bool inRepair;
    int uniqueID;
};


