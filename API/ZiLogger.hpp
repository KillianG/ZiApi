//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_LOGGER_HPP
#define PROJECT_LOGGER_HPP

#include <cstddef>
#include <iostream>
#include <ios>
#include <fstream>

namespace ZiApi {
    struct ZiLogger {
        /**
         * Type of logs
         */
        enum class Type {
            INFO,
            DEBUG,
            WARNING,
            ERROR,
            ABORT_MISSION
        };

        enum Severity {
            USELESS = 0,
            NORMAL,
            IMPORTANT,
            VITAL
        };

        static inline void setMinSeverity(Severity s) { minSeverity = s; }

        static inline Severity minSeverity = Severity::USELESS;
        static inline Severity currentSeverity = Severity::USELESS;
        static inline Type currentType = Type::INFO;
    };
}

using LogType = ZiApi::ZiLogger::Type;
using LogSeverity = ZiApi::ZiLogger::Severity;

/**
 * << operator overloads
 */

std::ostream &operator<<(LogSeverity s, const std::string &m) {
    std::ostream &os = std::cout;
    if (ZiApi::ZiLogger::currentSeverity >= ZiApi::ZiLogger::minSeverity) {
        return os << m;
    }
    return os;
}

LogSeverity operator <<(const LogType &log, const LogSeverity severity) {
    ZiApi::ZiLogger::currentType = log;
    ZiApi::ZiLogger::currentSeverity = severity;

    std::ostream &os = std::cout;
    switch (ZiApi::ZiLogger::currentType) {
        case LogType::INFO:
            os << "[INFO] ";
            break;
        case LogType::WARNING:
            os << "[WARNING] ";
            break;
        case LogType::DEBUG:
            os << "[DEBUG] ";
            break;
        case LogType::ABORT_MISSION:
            os << "[RIP] " << std::endl;
            std::_Exit(84);
        case LogType::ERROR:
            os << "[ERROR] ";
            break;
    }
    return severity;
}

LogSeverity operator <<(std::ostream &os, const LogSeverity severity) {
    ZiApi::ZiLogger::currentSeverity = severity;
    return severity;
}

std::ostream &operator<<(LogType type, const std::string &m) {
    std::cout << m;
}

#endif //PROJECT_LOGGER_HPP
