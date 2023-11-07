#include "Functions.hpp"
#include "Pipe.hpp"
#include "CompressorStation.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

template <typename T>
T CorNumb(T min, T max) {
    T x;
    while (true) {
        if (!(cin >> x) || x < min || x > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n Неверный тип данных" << endl;
            cout << "Введите число от " << min << " до " << max << endl;
        } else {
            return x;
        }
    }
}

void saveData() {
    Pipe p;
    CompressorStation cs;
    ofstream file("data.txt");
    if (p.getName().size() != 0){
        if (file.is_open()){
            file << "Pipe" << endl;
            file << p.getName() << endl;
            file << p.getlenght() << endl;
            file << p.getdiameter() << endl;
            file << p.getinRepair() << endl;
            
        }
        else{
            cout << "Не удалось открыть файл" << endl;
        }
    }
    if (cs.getName().size() != 0){
        if (file.is_open()){
            file << "CS" << endl;
            file << cs.getName() << endl;
            file << cs.getnumWorkshops() << endl;
            file << cs.getnumWorkshopsInOperation() << endl;
            file << cs.getefficiency() << endl;
            
        }
        else{
            cout << "Не удалось открыть файл" << endl;
        }
    }
    file.close();
    if (cs.getName().size() == 0 && p.getName().size() == 0){
        cout << "Введите данные для сохранения" << endl;
    }
    else{
        cout << "Данные успешно сохранены" << endl;
    }
}

void loadData() {
    Pipe p;
    CompressorStation cs;
    string line;
    ifstream file("data.txt");
    if (file.is_open()){
        getline(file,line);
        if (line == "Pipe"){
            getline(file,line);
            p.setName(line);
            getline(file, line);
            p.setlenght(stod(line));
            
            getline(file, line);
            p.setdiameter(stod(line));
            
            getline(file, line);
            p.setinRepair(stoi(line));
            
            getline(file,line);
            if (line == "CS"){
                getline(file,line);
                cs.setName(line);
                
                getline(file, line);
                cs.setnumWorkshops(stoi(line));
                
                getline(file, line);
                cs.setnumWorkshopsInOperation(stoi(line));
                
                getline(file, line);
                cs.setefficiency(stoi(line));
            }
            cout << "Данные успешно загрузились" << endl;
        }
        else if (line == "CS"){
            getline(file,line);
            cs.setName(line);
            
            getline(file, line);
            cs.setnumWorkshops(stoi(line));
            
            getline(file, line);
            cs.setnumWorkshopsInOperation(stoi(line));
            
            getline(file, line);
            cs.setefficiency(stoi(line));
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

