#include "Pipe.hpp"

Pipe::Pipe(const std::string& name, double length, double diameter) : name(name), length(length), diameter(diameter), inRepair(false) {
    // Генерация уникального идентификатора (псевдокод)
    uniqueID = generateUniqueID();
}

// Вспомогательная функция для генерации уникального идентификатора
int Pipe::generateUniqueID() {
    static int nextID = 1; // Статическая переменная для хранения следующего доступного ID
    return nextID++;
}

const std::string& Pipe::getName() const {
    return name;
}

double Pipe::getLength() const {
    return length;
}

double Pipe::getDiameter() const {
    return diameter;
}

bool Pipe::isInRepair() const {
    return inRepair;
}

void Pipe::setInRepair(bool inRepair) {
    this->inRepair = inRepair;
}

int Pipe::getUniqueID() const {
    return uniqueID;
}

