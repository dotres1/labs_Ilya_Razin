#include <iostream>
#include <fstream> // для работы с файлами
#include <sstream> // для считывания строки с консоли
#include <string> // для проверки типа данных
#include <format>
#include <chrono> // для замера времени и вывода в нужном формате
#include <iomanip>
#include <unordered_map>  // структуры данных
#include <unordered_set>

#include "Functions.h"
#include "Pipe.hpp"
#include "CompressorStation.hpp"
#include "logging.h"


using namespace std;
using namespace chrono;

unordered_map<int, Pipe> data_P;
unordered_map<int, CS> data_KS;

int main() {
    
    logg();
    while (true) {
        menu();  // вызываем меню
        cout << "Введите ваш выбор: ";
        cin.clear();
        int choice = get_correct_value(0, 7);
        switch (choice) {
        case 1:
        {
            add_to_dict(data_P);
            break;
        }
        case 2:
        {
            add_to_dict(data_KS);
            break;
        }
        case 3:
        {
            thirth();
            break;
        }
        case 4:
        {
            fourth();
            break;
        }
        case 5:
        {
            fif();
            break;
        }
        case 6:
        {
            six();
            break;
        }
        case 7:
        {
            seven();
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            cout << "Введите числа от 0 до 7\n";
            break;
        }
        }
    }
    return 0;
}
