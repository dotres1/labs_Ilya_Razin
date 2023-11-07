#include "Pipe.hpp"
#include "Functions.hpp"
#include <iostream>
using namespace std;

void Pipe::readFromConsole() {
    cout << "Введите название трубы: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);
    cout << "Введите длину трубы (в км): ";
    length = CorNumb(0.0, __DBL_MAX__);
    cout << "Введите диаметр трубы: ";
    diameter = CorNumb(0.0, __DBL_MAX__);
    cout << "Данные введены успешно" << endl;
    inRepair = false;
}

void Pipe::printToConsole() {
    cout << "Название: " << name << endl;
    cout << "Длина: " << length << " км" << endl;
    cout << "Диаметр: " << diameter << endl;
    cout << "В ремонте: " << (inRepair ? "Да" : "Нет") << endl;
}

void Pipe::editpipe() {
    if (name.size() != 0) {
        bool inrep = false;
        cout << "Труба в ремонте? (0 - Нет, 1 - Да): ";
        cin >> inrep;
        inRepair = inrep;
    }
    else{
        cout << "Трубы не найдены." << endl;
    }
}

const std::string& Pipe::getName() const {
    return name;
}

void Pipe::setName(const std::string& newName) {
    name = newName;
}

double Pipe::getlenght(){
    return length;
}
void Pipe::setlenght(double newlenght){
    length = newlenght;
}

double Pipe::getdiameter(){
    return diameter;
}
void Pipe::setdiameter(double newdiameter){
    diameter = newdiameter;
}

bool Pipe::getinRepair(){
    return inRepair;
}
void Pipe::setinRepair(bool newinRepair){
    inRepair = newinRepair;
}
