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
    ofstream file("data.txt");
    if (p.name.size() != 0){
        if (file.is_open()){
            file << "Pipe" << endl;
            file << p.name << endl;
            file << p.length << endl;
            file << p.diameter << endl;
            file << p.inRepair << endl;
            
        }
        else{
            cout << "Не удалось открыть файл" << endl;
        }
    }
    if (cs.name.size() != 0){
        if (file.is_open()){
            file << "CS" << endl;
            file << cs.name << endl;
            file << cs.numWorkshops << endl;
            file << cs.numWorkshopsInOperation << endl;
            file << cs.efficiency << endl;
            
        }
        else{
            cout << "Не удалось открыть файл" << endl;
        }
    }
    file.close();
    if (cs.name.size() == 0 && p.name.size() == 0){
        cout << "Введите данные для сохранения" << endl;
    }
    else{
        cout << "Данные успешно сохранены" << endl;
    }
}

void loadData(Pipe& p, CompressorStation& cs) {
    string line;
    ifstream file("data.txt");
    if (file.is_open()){
        getline(file,line);
        if (line == "Pipe"){
            getline(file,p.name);
            
            getline(file, line);
            p.length = stod(line);
            
            getline(file, line);
            p.diameter = stod(line);
            
            getline(file, line);
            p.inRepair = stoi(line);
            
            getline(file,line);
            if (line == "CS"){
                getline(file,cs.name);
                
                getline(file, line);
                cs.numWorkshops = stoi(line);
                
                getline(file, line);
                cs.numWorkshopsInOperation = stoi(line);
                
                getline(file, line);
                cs.efficiency = stoi(line);
            }
            cout << "Данные успешно загрузились" << endl;
        }
        else if (line == "CS"){
            getline(file,cs.name);
            
            getline(file, line);
            cs.numWorkshops = stoi(line);
            
            getline(file, line);
            cs.numWorkshopsInOperation = stoi(line);
            
            getline(file, line);
            cs.efficiency = stoi(line);
            cout << "Данные успешно загрузились" << endl;
        }
        else{
            cout << "Файл пуст" << endl;
        }
    }
    else{
        cout << "Не удалось открыть файл" << endl;
    }
    file.close();
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
