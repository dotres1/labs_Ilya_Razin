#include <iostream>
#include <fstream>
#include <string>
#include "Pipe.hpp"
#include "CompressorStation.hpp"
#include "Functions.hpp"

using namespace std;

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
                if (pipe.getName().size() != 0){
                    pipe.printToConsole();
                    cout << endl;
                }
                else{
                    cout << "Добавьте трубу" << endl;
                }
                cout << "КС: " << endl;
                if (cs.getName().size() != 0){
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
                if (cs.getName().size() != 0) {
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
                saveData();
                break;
            }
            case 7: {
                loadData();
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
