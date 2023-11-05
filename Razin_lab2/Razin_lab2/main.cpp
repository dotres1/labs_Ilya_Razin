#include "DataManagement.hpp"
#include <iostream>

int main() {
    DataManagement dataManager;

    while (true) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить трубу" << std::endl;
        std::cout << "2. Редактировать трубу" << std::endl;
        std::cout << "3. Удалить трубу" << std::endl;
        std::cout << "4. Добавить КС" << std::endl;
        std::cout << "5. Редактировать КС" << std::endl;
        std::cout << "6. Удалить КС" << std::endl;
        std::cout << "7. Вывести информацию" << std::endl;
        std::cout << "8. Вывести журнал действий" << std::endl;
        std::cout << "0. Выход" << std::endl;

        int choice;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Добавление трубы
                std::string name;
                double length, diameter;
                std::cout << "Введите название трубы: ";
                std::cin >> name;
                std::cout << "Введите длину трубы: ";
                std::cin >> length;
                std::cout << "Введите диаметр трубы: ";
                std::cin >> diameter;
                Pipe pipe(name, length, diameter);
                dataManager.addPipe(pipe);
                dataManager.logAction("Добавлена новая труба: " + name);
                break;
            }
            case 2: {
                // Редактирование трубы
                int uniqueID;
                std::cout << "Введите уникальный ID трубы для редактирования: ";
                std::cin >> uniqueID;
                // Здесь вводите новые значения и вызываете dataManager.editPipe(uniqueID, updatedPipe)
                break;
            }
            case 3: {
                // Удаление трубы
                int uniqueID;
                std::cout << "Введите уникальный ID трубы для удаления: ";
                std::cin >> uniqueID;
                dataManager.deletePipe(uniqueID);
                dataManager.logAction("Удалена труба с уникальным ID: " + std::to_string(uniqueID));
                break;
            }
            case 4: {
                // Добавление КС
                std::string name;
                int numWorkshops, numWorkshopsInOperation;
                double efficiency;
                std::cout << "Введите название КС: ";
                std::cin >> name;
                std::cout << "Введите количество цехов: ";
                std::cin >> numWorkshops;
                std::cout << "Введите количество цехов в работе: ";
                std::cin >> numWorkshopsInOperation;
                std::cout << "Введите эффективность: ";
                std::cin >> efficiency;
                CompressorStation cs(name, numWorkshops, numWorkshopsInOperation, efficiency);
                dataManager.addCompressorStation(cs);
                dataManager.logAction("Добавлена новая КС: " + name);
                break;
            }
            case 5: {
                // Редактирование КС
                int uniqueID;
                std::cout << "Введите уникальный ID КС для редактирования: ";
                std::cin >> uniqueID;
                // Здесь вводите новые значения и вызываете dataManager.editCompressorStation(uniqueID, updatedCS)
                break;
            }
            case 6: {
                // Удаление КС
                int uniqueID;
                std::cout << "Введите уникальный ID КС для удаления: ";
                std::cin >> uniqueID;
                dataManager.deleteCompressorStation(uniqueID);
                dataManager.logAction("Удалена КС с уникальным ID: " + std::to_string(uniqueID));
                break;
            }
            case 7: {
                // Вывод информации о трубах и КС
                // Здесь выводите данные из dataManager.getPipes() и dataManager.getCompressorStations()
                break;
            }
            case 8: {
                // Вывод журнала действий
                const std::vector<LogEntry>& log = dataManager.getLog();
                std::cout << "Журнал действий:" << std::endl;
                for (const LogEntry& entry : log) {
                    std::cout << entry.timestamp << " - " << entry.action << std::endl;
                }
                break;
            }
            case 0: {
                // Выход из программы
                return 0;
            }
            default: {
                std::cout << "Ошибка выбора." << std::endl;
            }
        }
    }

    return 0;
}
