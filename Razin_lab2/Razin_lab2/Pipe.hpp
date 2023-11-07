#ifndef Pipe_hpp
#define Pipe_hpp

#pragma once
#include <string>
using namespace std;

class Pipe {
public:
    Pipe(); // Конструктор
    void readFromConsole();
    void printToConsole();
    void editpipe();
    
    // Геттер и сеттер
    const std::string& getName() const;
    void setName(const std::string& newName);
    
    double getlenght();
    void setlenght(double newlenght);
    
    double getdiameter();
    void setdiameter(double newdiameter);
    
    bool getinRepair();
    void setinRepair(bool newinRepair);

private:
    string name;
    double length;
    double diameter;
    bool inRepair;
};

#endif /* Pipe_hpp */
