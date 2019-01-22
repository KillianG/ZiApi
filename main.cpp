#include <iostream>

#include "ZiLogger.hpp"

int main() {
ZiApi::ZiLogger::setMinSeverity(LogSeverity::NORMAL);
    LogType::INFO << LogSeverity::USELESS << "ptite pute" << LogSeverity::NORMAL << "Bonjour" << LogSeverity::USELESS
                  << "renaud C++ MASTER RACE" << LogSeverity::IMPORTANT << "Renaud bg" << std::endl;

    ZiApi::ZiLogger::setMinSeverity(LogSeverity::IMPORTANT);
    LogType::ERROR << LogSeverity::USELESS << "ptite pute" << LogSeverity::NORMAL << "Bonjour" << LogSeverity::USELESS
                  << "renaud C++ MASTER RACE" << LogSeverity::IMPORTANT << "Renaud bg" << std::endl;

    ZiApi::ZiLogger::setMinSeverity(LogSeverity::USELESS);
    LogType::WARNING << LogSeverity::USELESS << "ptite pute" << LogSeverity::NORMAL << "Bonjour" << LogSeverity::USELESS
                  << "renaud C++ MASTER RACE" << LogSeverity::IMPORTANT << "Renaud bg" << std::endl;
}