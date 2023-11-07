#ifndef CompressorStation_hpp
#define CompressorStation_hpp


#pragma once
#include <string>
using namespace std;

class CompressorStation {
public:
    CompressorStation(); // Конструктор
    void readFromConsole();
    void printToConsole();
    void startWorkshop();
    void stopWorkshop();
    
    // Геттер и сеттер для name
    const std::string& getName() const;
    void setName(const std::string& newName);
    
    int getnumWorkshops();
    void setnumWorkshops(int newnumWorkshops);
    
    int getnumWorkshopsInOperation();
    void setnumWorkshopsInOperation(double newnumWorkshopsInOperation);
    
    double getefficiency();
    void setefficiency(double newefficiency);
    
private:
    string name;
    int numWorkshops;
    int numWorkshopsInOperation;
    double efficiency;
};

#endif /* CompressorStation_hpp */
