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

        enum Severity {
            USELESS = 0,
            NORMAL,
            IMPORTANT,
            VITAL
        };

        enum class OutputStream {
            COUT,
            CERR,
            FILE
        };

        static inline void setMinSeverity(Severity s) { minSeverity = s; }

        static inline void setStreamFile(const std::string &filePath = "./log.txt") { fileStream.open(filePath); }

        static inline void setCurrentStream(OutputStream stream) { currentStream = stream; }

        template<typename T>
        friend std::ostream &operator<<(Severity s, const T &m) {
            std::ostream &os = ZiApi::ZiLogger::getOstream();
            if (ZiApi::ZiLogger::currentSeverity >= ZiApi::ZiLogger::minSeverity) {
                return os << m;
            }
            return os;
        }

        template<typename T>
        friend std::ostream &operator<<(Type type, const T &m) {
            ZiApi::ZiLogger::currentType = type;
            std::ostream &os = ZiApi::ZiLogger::getOstream();
            if (ZiApi::ZiLogger::currentSeverity >= ZiApi::ZiLogger::minSeverity) {
                printPrefix(os);
                return os << m;
            }
            return os;
        }

        friend Severity operator<<(const Type &type, const Severity severity) {
            ZiApi::ZiLogger::currentType = type;
            ZiApi::ZiLogger::currentSeverity = severity;
            printPrefix(getOstream());
            return severity;
        }

        friend Severity operator<<(std::ostream &os, const Severity severity) {
            ZiApi::ZiLogger::currentSeverity = severity;
            return severity;
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
#ifdef __unix__
            os << "[" << getTime() << "] ";
#endif

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

#ifdef __unix__

        static std::_Put_time<char> getTime() {
            std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
            auto currentTime = std::put_time(std::localtime(&now_c), "%T");
            return (currentTime);
        }

#endif
    };
}

using LogType = ZiApi::ZiLogger::Type;
using LogSeverity = ZiApi::ZiLogger::Severity;
using LogStream = ZiApi::ZiLogger::OutputStream;

#endif //PROJECT_LOGGER_HPP