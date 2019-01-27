//
// Created by killian on 22/01/19.
// Epitech 3 years remaining
// See http://github.com/KillianG
//

#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>

namespace ZiApi {
    /**
     * @brief ZiApi logger
     *
     * Usage example:
     * @code
     * using LogType = ZiApi::ZiLogger::Type;
     * using LogSeverity = ZiApi::ZiLogger::Severity;
     *
     * ZiApi::ZiLogger::setMinSeverity(LogSeverity::NORMAL);                                                    //sets the severity at normal
     * ZiApi::ZiLogger::setCurrentStream(ZiApi::ZiLogger::OutputStream::COUT);                                  //sets the logger output on the standard output
     *
     * Log(LogType::INFO, LogSeverity::NORMAL) << "Program started" << ZiApi::ZiLogger::endl;                   //[INFO] ~/main.cpp:7 : Program started
     *
     * ...
     *
     * LogType::DEBUG << "init resources" << ZiApi::ZiLogger::endl;                                             //[DEBUG] init resources
     * ZiApi::ZiLogger::setMinSeverity(LogSeverity::IMPORTANT);                                                 //sets the severity at important
     *
     * ...
     *
     * LogType::INFO << LogSeverity::NORMAL << "Open assets folder" << ZiApi::ZiLogger::endl;                   //not showed because normal < important
     *
     * ...
     *
     * Log(LogType::ERROR, LogSeverity::VITAL) << "File: \"logo.png\" not found" << ZiApi::ZiLogger::endl;      //[ERROR] ~/main.cpp:30 : File: "logo.png" not found
     *
     * ...
     *
     * LogType::WARNING << LogSeverity::NORMAL << "Enter error handler "
     * << LogSeverity::IMPORTANT << ": " << 3  << " warnings generated"<< ZiApi::ZiLogger::endl;                //[WARNING] : 3 warnings generated
     * @endcode
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
         * @brief Set minimal severity
         *
         * Default is at Severity::USELESS
         * @param[in] sev New severity
         */
        static inline void setMinSeverity(Severity sev) noexcept { minSeverity = sev; }

        /**
         * @brief Set logFile's path
         *
         * Default is "./log.txt"
         * @param[in] filePath New logFile's path
         */
        static inline void setStreamFile(const std::string &filePath = "./log.txt") { fileStream.open(filePath); }

        /**
         * @brief Set logs outputs
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
#define Log(logType, sev) logType << sev << __FILE__ << ":" << __LINE__ << " : "
#else
#define Log(logType, sev) logType << sev
#endif