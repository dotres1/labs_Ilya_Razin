#include "Pipe.hpp"
#include "CompressorStation.hpp"
#include <vector>
#include <string>

struct LogEntry {
    std::string timestamp;
    std::string action;
};

class DataManagement {
public:
    // Конструктор по умолчанию
    DataManagement() = default;

    // Методы для работы с трубами
    void addPipe(const Pipe& pipe);
    void editPipe(int uniqueID, const Pipe& updatedPipe);
    void deletePipe(int uniqueID);
    const std::vector<Pipe>& getPipes() const;

    // Методы для работы с компрессорными станциями
    void addCompressorStation(const CompressorStation& cs);
    void editCompressorStation(int uniqueID, const CompressorStation& updatedCS);
    void deleteCompressorStation(int uniqueID);
    const std::vector<CompressorStation>& getCompressorStations() const;

    // Методы для логирования действий
    void logAction(const std::string& action);
    const std::vector<LogEntry>& getLog() const;

private:
    std::vector<Pipe> pipes;
    std::vector<CompressorStation> compressorStations;
    std::vector<LogEntry> log;

    // Вспомогательная функция для получения текущей метки времени
    std::string getCurrentTimestamp() const;
};

