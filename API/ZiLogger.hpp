//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#ifndef PROJECT_LOGGER_HPP
#define PROJECT_LOGGER_HPP

#include <ios>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

namespace ZiApi {
    class ZiLogger {
    public:

        /**
         * Delete constructor to avoid instantiation
         */
        ZiLogger() = delete;

        /**
         * Type of logs
         */
        enum class Type {
            INFO,
            DEBUG,
            WARNING,
            ERROR,
            FATAL,
            ABORT_MISSION
        };

        enum class Severity : int {
            USELESS = 0,
            NORMAL,
            IMPORTANT,
            VITAL
        };

        enum class OutputStream {
            COUT,
            CERR,
            FILE,
        };

        enum Endl {
            endl
        };

        static inline void setMinSeverity(Severity s) { minSeverity = s; }

        static inline void setStreamFile(const std::string &filePath = "./log.txt") { fileStream.open(filePath); }

        static inline void setCurrentStream(OutputStream stream) { currentStream = stream; }



        template <typename T>
        friend Severity operator<<(Severity s, const T &m) {
            if (s >= ZiApi::ZiLogger::minSeverity)
                ZiApi::ZiLogger::getOstream() << m;
            return s;
        }

        friend Severity operator<<(Severity s, const Endl &m) {
            if (s >= ZiApi::ZiLogger::minSeverity)
                ZiApi::ZiLogger::getOstream() << std::endl;
            return s;
        }

        friend Severity operator<<(Type type, Severity severity) {
            ZiApi::ZiLogger::currentType = type;
            ZiApi::ZiLogger::currentSeverity = severity;
            if (ZiApi::ZiLogger::currentSeverity >= ZiApi::ZiLogger::minSeverity) {
                printPrefix(getOstream());
            }
            return severity;
        }

        template<typename T>
        friend Severity operator<<(Type type, const T &m) {
            ZiApi::ZiLogger::currentType = type;
            if (ZiApi::ZiLogger::currentSeverity >= ZiApi::ZiLogger::minSeverity) {
                std::ostream &os = ZiApi::ZiLogger::getOstream();
                printPrefix(os);
                os << m;
            }
            return ZiApi::ZiLogger::currentSeverity;
        }

        friend Severity operator<<(Severity actualSeverity, Severity newSeverity) {
            ZiApi::ZiLogger::currentSeverity = newSeverity;
            return newSeverity;
        }

    private:
        static inline std::ofstream fileStream;
        static inline Type currentType = Type::INFO;
        static inline Severity minSeverity = Severity::USELESS;
        static inline Severity currentSeverity = Severity::USELESS;
        static inline OutputStream currentStream = OutputStream::COUT;

        static std::ostream &getOstream() {
            switch (currentStream) {
                case OutputStream::COUT:
                    return std::cout;
                case OutputStream::CERR:
                    return std::cerr;
                case OutputStream::FILE:
                    if (!fileStream.is_open())
                        ZiApi::ZiLogger::setStreamFile();
                    return fileStream;
            }
            return std::cout;
        }

        static void printPrefix(std::ostream &os) {
            switch (ZiApi::ZiLogger::currentType) {
                case Type::INFO:
                    os << "[INFO] ";
                    break;
                case Type::WARNING:
                    os << "[WARNING] ";
                    break;
                case Type::DEBUG:
                    os << "[DEBUG] ";
                    break;
                case Type::ABORT_MISSION:
                    os << "[RIP] " << std::endl;
                    std::_Exit(84);
                case Type::ERROR:
                    os << "[ERROR] ";
                    break;
                case Type::FATAL:
                    os << "[FATAL] ";
                    break;
            }
        }
    };

#ifdef __unix__
#define Log(logType) logType << __FILE__ << ":" << __LINE__ << " : "
#else
#define Log(logType) logType
#endif
}

using LogType = ZiApi::ZiLogger::Type;
using LogSeverity = ZiApi::ZiLogger::Severity;
using LogStream = ZiApi::ZiLogger::OutputStream;

#endif //PROJECT_LOGGER_HPP