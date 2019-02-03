/**
 * @file   Zilogger.hpp
 * @author nhyarlathotep
 * @date   25/01/19.
 *
 * @brief  FieldVValue declaration.
 */

#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>

namespace ZiApi {
    /**
     * @brief ZiApi's logger
     *
     * You can use the macro `LOG(logType, sev)` to display in which file and line the log was printed.
     * You can use it the same way as `std::cout` but you must put our own `ZiApi::ZiLogger::end` at the end
     */
    class ZiLogger {
    public:
        ZiLogger() = delete;

        /**
         * Types of logs
         */
        enum class Type {
            INFO,         ///< Useful information
            DEBUG,        ///< Debug information mainly for developers
            WARNING,      ///< Warning
            ERROR,        ///< Error
            FATAL,        ///< An Fatal error that cause the program to stop
            ABORT_MISSION ///< Exit the program
        };

        /**
         * Types of severity
         */
        enum class Severity {
            USELESS,      ///< useless
            NORMAL,       ///< normal
            IMPORTANT,    ///< important
            VITAL         ///< vital
        };

        /**
         * Types of outputs
         */
        enum class OutputStream {
            COUT,         ///< standard output
            CERR,         ///< error output
            FILE          ///< file output
        };

        enum Endl {
            endl
        };

        /**
         * @brief Sets the minimal severity
         *
         * Default is at Severity::USELESS
         * @param[in] sev New severity
         */
        static inline void setMinSeverity(Severity sev) noexcept { minSeverity = sev; }

        /**
         * @brief Sets logFile's path
         *
         * Default is `./log.txt`
         * @param[in] filePath New logFile's path
         */
        static inline void setStreamFile(const std::string &filePath = "./log.txt") { fileStream.open(filePath); }

        /**
         * @brief Sets logs outputs
         *
         * Default is OutputStream::COUT
         * @param[in] stream New output stream
         */
        static inline void setCurrentStream(OutputStream stream) noexcept { currentStream = stream; }

        template<typename T>
        friend Severity operator<<(Severity sev, const T &m) {
            if (sev >= ZiApi::ZiLogger::minSeverity)
                ZiApi::ZiLogger::getOstream() << m;
            return sev;
        }

        friend Severity operator<<(Severity sev, const Endl &) {
            if (sev >= ZiApi::ZiLogger::minSeverity)
                ZiApi::ZiLogger::getOstream() << std::endl;
            return sev;
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

        friend Severity operator<<(Severity, Severity newSeverity) {
            if (ZiApi::ZiLogger::currentSeverity < ZiApi::ZiLogger::minSeverity && newSeverity >= ZiApi::ZiLogger::minSeverity) {
                printPrefix(ZiApi::ZiLogger::getOstream());
            }
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
                case Type::INFO: os << "[INFO] ";
                    break;
                case Type::DEBUG: os << "[DEBUG] ";
                    break;
                case Type::WARNING: os << "[WARNING] ";
                    break;
                case Type::ERROR: os << "[ERROR] ";
                    break;
                case Type::FATAL: os << "[FATAL] ";
                    break;
                case Type::ABORT_MISSION: os << "[RIP] " << std::endl;
                    std::_Exit(84);
                    break;
            }
        }
    };
}

#ifdef __unix__
#define LOG(logType, sev) logType << sev << __FILE__ << ":" << __LINE__ << " : "
#else
#define LOG(logType, sev) logType << sev
#endif

/**
* Output : @include LoggerTest.output
* LoggerTest.cpp : @example LoggerTest.cpp
*/