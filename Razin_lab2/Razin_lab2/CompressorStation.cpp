#include "CompressorStation.hpp"
#include "Functions.hpp"
#include <iostream>
using namespace std;

void CompressorStation::readFromConsole() {
    cout << "Введите название КС: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);
    cout << "Введите колличество цехов: ";
    numWorkshops = CorNumb(0, INT_MAX);
    cout << "Введите колличество цехов в работе: ";
    numWorkshopsInOperation = CorNumb(0, numWorkshops);
    cout << "Введите эффективность: ";
    efficiency = CorNumb(0, 10);
}

void CompressorStation::printToConsole() {
    cout << "Название: " << name << endl;
    cout << "Колличество цехов: " << numWorkshops << endl;
    cout << "Колличество цехов в работе: " << numWorkshopsInOperation << endl;
    cout << "Эффективность: " << efficiency << endl;
}

void CompressorStation::startWorkshop() {
    if (numWorkshopsInOperation < numWorkshops) {
        numWorkshopsInOperation++;
        cout << "Цех успешно начал рабоать." << endl;
    } else {
        cout << "Все цехи уже в работе." << endl;
    }
}

void CompressorStation::stopWorkshop() {
    if (numWorkshopsInOperation > 0) {
        numWorkshopsInOperation--;
        cout << "Цех успешно остановлен." << endl;
    } else {
        cout << "Нет цехов в работе." << endl;
    }
}

const std::string& CompressorStation::getName() const {
    return name;
}

void CompressorStation::setName(const std::string& newName) {
    name = newName;
}

int CompressorStation::getnumWorkshops(){
    return numWorkshops;
}
void CompressorStation::setnumWorkshops(int newnumWorkshops){
    numWorkshops = newnumWorkshops;
}

int CompressorStation::getnumWorkshopsInOperation(){
    return numWorkshopsInOperation;
}
void CompressorStation::setnumWorkshopsInOperation(double newnumWorkshopsInOperation){
    numWorkshopsInOperation = newnumWorkshopsInOperation;
}

double CompressorStation::getefficiency(){
    return efficiency;
}
void CompressorStation::setefficiency(double newefficiency){
    efficiency = newefficiency;
}
