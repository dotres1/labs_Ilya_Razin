#include "CompressorStation.hpp"
#include <ctime> // Для генерации уникального идентификатора

CompressorStation::CompressorStation(const std::string& name, int numWorkshops, int numWorkshopsInOperation, double efficiency)
    : name(name), numWorkshops(numWorkshops), numWorkshopsInOperation(numWorkshopsInOperation), efficiency(efficiency) {
    // Генерация уникального идентификатора (псевдокод)
    uniqueID = generateUniqueID();
}


// Вспомогательная функция для генерации уникального идентификатора
int CompressorStation::generateUniqueID() {
    static int nextID = 1; // Статическая переменная для хранения следующего доступного ID
    return nextID++;
}

const std::string& CompressorStation::getName() const {
    return name;
}

int CompressorStation::getNumWorkshops() const {
    return numWorkshops;
}

int CompressorStation::getNumWorkshopsInOperation() const {
    return numWorkshopsInOperation;
}

double CompressorStation::getEfficiency() const {
    return efficiency;
}

int CompressorStation::getUniqueID() const {
    return uniqueID;
}

void CompressorStation::startWorkshop() {
    if (numWorkshopsInOperation < numWorkshops) {
        numWorkshopsInOperation++;
    }
}

void CompressorStation::stopWorkshop() {
    if (numWorkshopsInOperation > 0) {
        numWorkshopsInOperation--;
    }
}

