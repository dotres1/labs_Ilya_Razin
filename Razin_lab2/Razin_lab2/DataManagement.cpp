#include "DataManagement.hpp"

// Реализация метода addPipe
void DataManagement::addPipe(const Pipe& pipe) {
    pipes.push_back(pipe);
}

// Реализация метода editPipe
void DataManagement::editPipe(int uniqueID, const Pipe& updatedPipe) {
    for (Pipe& pipe : pipes) {
        if (pipe.getUniqueID() == uniqueID) {
            pipe = updatedPipe;
            break;
        }
    }
}

// Реализация метода deletePipe
void DataManagement::deletePipe(int uniqueID) {
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [uniqueID](const Pipe& pipe) {
        return pipe.getUniqueID() == uniqueID;
    }), pipes.end());
}

// Реализация метода getPipes
const std::vector<Pipe>& DataManagement::getPipes() const {
    return pipes;
}

// Реализация метода addCompressorStation
void DataManagement::addCompressorStation(const CompressorStation& cs) {
    compressorStations.push_back(cs);
}

// Реализация метода editCompressorStation
void DataManagement::editCompressorStation(int uniqueID, const CompressorStation& updatedCS) {
    for (CompressorStation& cs : compressorStations) {
        if (cs.getUniqueID() == uniqueID) {
            cs = updatedCS;
            break;
        }
    }
}

// Реализация метода deleteCompressorStation
void DataManagement::deleteCompressorStation(int uniqueID) {
    compressorStations.erase(std::remove_if(compressorStations.begin(), compressorStations.end(), [uniqueID](const CompressorStation& cs) {
        return cs.getUniqueID() == uniqueID;
    }), compressorStations.end());
}

// Реализация метода getCompressorStations
const std::vector<CompressorStation>& DataManagement::getCompressorStations() const {
    return compressorStations;
}

// Реализация метода logAction
void DataManagement::logAction(const std::string& action) {
    LogEntry entry;
    entry.timestamp = getCurrentTimestamp();
    entry.action = action;
    log.push_back(entry);
}

// Реализация метода getLog
const std::vector<LogEntry>& DataManagement::getLog() const {
    return log;
}

// Вспомогательная функция для получения текущей метки времени
std::string DataManagement::getCurrentTimestamp() const {
    // Реализация получения текущей метки времени
    return "2023-11-06 12:00:00"; // Замените этот код на реальную реализацию
}

