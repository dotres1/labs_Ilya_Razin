//
//  main.cpp
//  Razin_Ilya_AS5
//
//  Created by Илья on 29.09.2023.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int CorNumb(int min, int max){
    int x;
    while ((cin >> x).fail() || cin.peek()!='\n' || x < min || x > max){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n Неверный тип данных" << endl;
        cout << "Введите число от " << min << " до " << max << endl;
    }
    return x;
}

double CorNumb(double min, double max){
    double x;
    while ((cin >> x).fail() || cin.peek()!='\n' || x < min || x > max){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n Неверный тип данных" << endl;
        cout << "Введите число от " << min << " до " << max << endl;
    }
    return x;
}

struct Pipe {
    string name;
    double length;
    double diameter;
    bool inRepair;
    
    void readFromConsole() {
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
    
    void printToConsole(){
        cout << "Название: " << name << endl;
        cout << "Длина: " << length << " км" << endl;
        cout << "Диаметр: " << diameter << endl;
        cout << "В ремонте: " << (inRepair ? "Да" : "Нет") << endl;
    }
    
    void editpipe(){
        if (name.size() != 0) {
            bool inrep = false;
            cout << "Труба в ремонте? (0 - Нет, 1 - Да): ";
            cin >> inrep;
            inRepair = inrep;
            }
        else {
            cout << "Трубы не найдены." << endl;
        }
    }
};

struct CompressorStation {
    string name;
    int numWorkshops;
    int numWorkshopsInOperation;
    double efficiency;

    void readFromConsole() {
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

    void printToConsole() {
        cout << "Название: " << name << endl;
        cout << "Колличество цехов: " << numWorkshops << endl;
        cout << "Колличество цехов в работе: " << numWorkshopsInOperation << endl;
        cout << "Эффективность: " << efficiency << endl;
    }

    void startWorkshop() {
        if (numWorkshopsInOperation < numWorkshops) {
            numWorkshopsInOperation++;
            cout << "Цех успешно начал рабоать." << endl;
        } else {
            cout << "Все цехи уже в работе." << endl;
        }
    }

    void stopWorkshop() {
        if (numWorkshopsInOperation > 0) {
            numWorkshopsInOperation--;
            cout << "Цех успешно остановлен." << endl;
        } else {
            cout << "Нет цехов в работе." << endl;
        }
    }
};

void saveData(Pipe& p, CompressorStation& cs) {
    ofstream out;
    out.open("pipe_data.txt");
    if (out.is_open()) {
        if (p.name.size() != 0){
            out << p.name;
            out << "\n" << p.length;
            out << "\n" << p.diameter;
            out << "\n" << p.inRepair;
        }
        out.close();
    }
    else{
        cout << "Ошибка сохранения" << endl;
    }
    out.open(" cs_data.txt");
    if (out.is_open()){
        if (cs.name.size() != 0){
            out << cs.name;
            out << "\n" << cs.numWorkshops;
            out << "\n" << cs.numWorkshopsInOperation;
            out << "\n" << cs.efficiency;
        }
        out.close();
    }
    else{
        cout << "Ошибка сохранения" << endl;
    }
}

void loadData(Pipe& p, CompressorStation& cs) {
            ifstream file("pipe_data.txt");
            if (file.is_open()){
                file >> p.name;
                file >> p.length;
                file >> p.diameter;
                file >> p.inRepair;
                cout << "Данные успешно обновлены" << endl;
            }
            file.close();
            ifstream data("cs_data.txt");
            if (data.is_open()){
                data >> cs.name;
                data >> cs.numWorkshops;
                data >> cs.numWorkshopsInOperation;
                data >> cs.efficiency;
                cout << "Данные успешно обновлены" << endl;
            }
            data.close();
}

int main() {
    Pipe pipe;
    CompressorStation cs;
    int choice;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Добавить трубу" << endl;
        cout << "2. Добавить КС" << endl;
        cout << "3. Просмотр всех объектов " << endl;
        cout << "4. Редактировать трубу" << endl;
        cout << "5. Редактировать КС" << endl;
        cout << "6. Сохранить" << endl;
        cout << "7. Загрузить" << endl;
        cout << "0. Выход" << endl;

        cout << "Введите ваш выбор: ";
        choice = CorNumb(0, 7);
        switch (choice) {
            case 1: {
                pipe.readFromConsole();
                break;
            }
            case 2: {
                cs.readFromConsole();
                break;
            }
            case 3: {
                cout << "Труба: " << endl;
                if (pipe.name.size() != 0){
                    pipe.printToConsole();
                    cout << endl;
                }
                else{
                    cout << "Добавьте трубу" << endl;
                }
                cout << "КС: " << endl;
                if (cs.name.size() != 0){
                    cs.printToConsole();
                    cout << endl;
                }
                else{
                    cout << "Добавьте КС" << endl;
                }
                break;
            }
            case 4: {
                pipe.editpipe();
                break;
            }
            case 5: {
                if (cs.name.size() != 0) {
                    int choice;
                    cout << "1. Запустить цех" << endl;
                    cout << "2. Остановить цех" << endl;
                    cout << "Выберите действие: ";
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            cs.startWorkshop();
                            break;
                        }
                        case 2: {
                            cs.stopWorkshop();
                            break;
                        }
                        default: {
                            cout << "Ошибка выбора." << endl;
                        }
                    }
                }
                else {
                    cout << "КС не найдены." << endl;
                }
                break;
            }
            case 6: {
                saveData(pipe, cs);
                break;
            }
            case 7: {
                loadData(pipe, cs);
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Ошибка выбора." << endl;
            }
        }
    }
}
