//
// Created by nhyarlathotep on 01/02/19.
//

#include "ZiLogger.hpp"

using LogType = ZiApi::ZiLogger::Type;
using LogSeverity = ZiApi::ZiLogger::Severity;

int main() {
    ZiApi::ZiLogger::setMinSeverity(LogSeverity::NORMAL);                                                    //sets the severity at normal
    ZiApi::ZiLogger::setCurrentStream(ZiApi::ZiLogger::OutputStream::COUT);                                  //sets the logger output on the standard output
    LOG(LogType::INFO, LogSeverity::NORMAL) << "Program started" << ZiApi::ZiLogger::endl;                   //[INFO] LoggerTest.cpp:13 : Program started
    LogType::DEBUG << "init resources" << ZiApi::ZiLogger::endl;                                             //[DEBUG] init resources
    ZiApi::ZiLogger::setMinSeverity(LogSeverity::IMPORTANT);                                                 //sets the severity at important
    LogType::INFO << LogSeverity::NORMAL << "Open assets folder" << ZiApi::ZiLogger::endl;                   //not showed because normal < important
    LOG(LogType::ERROR, LogSeverity::VITAL) << "File: \"logo.png\" not found" << ZiApi::ZiLogger::endl;      //[ERROR] LoggerTest.cpp:17 : File: "logo.png" not found
    LogType::WARNING << LogSeverity::NORMAL << "Enter error handler "
    << LogSeverity::IMPORTANT << ": " << 3  << " warnings generated"<< ZiApi::ZiLogger::endl;                //[WARNING] : 3 warnings generated
}