#include <iostream>

#include <ZiLogger.hpp>
#include "IHttpResponse.hpp"

int main() {
    ZiApi::ZiLogger::setMinSeverity(ZiApi::ZiLogger::Severity::IMPORTANT);

    LogType::INFO << LogSeverity::IMPORTANT << "Salut " << LogSeverity::USELESS << "Killian" << LogSeverity::IMPORTANT << "Renaud" << ZiApi::ZiLogger::endl;
    Log(LogType::WARNING) << LogSeverity::IMPORTANT << "Salut " << LogSeverity::USELESS << "Killian" << LogSeverity::IMPORTANT << "Renaud" << ZiApi::ZiLogger::endl;
}