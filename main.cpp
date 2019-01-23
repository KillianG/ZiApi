#include <iostream>

#include "ZiLogger.hpp"

int main() {
    ZiApi::ZiLogger::setMinSeverity(LogSeverity::NORMAL);
    ZiApi::ZiLogger::setCurrentStream(LogStream::FILE);

    LogType::INFO <<
    LogSeverity::USELESS << "ptite pute " <<
    LogSeverity::NORMAL << "Bonjour " <<
    LogSeverity::USELESS << "renaud C++ MASTER RACE " <<
    LogSeverity::IMPORTANT << "Renaud le bg" << std::endl;

    LogType::WARNING << "Test" << std::endl;
    LogType::WARNING << 3 << std::endl;

    LogType::ERROR << "Salut" << "Quentin" << std::endl;
}