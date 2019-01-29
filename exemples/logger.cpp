#include "ZiLogger.hpp"

using LogType = ZiApi::ZiLogger::Type;
using LogSeverity = ZiApi::ZiLogger::Severity;

int main()
{
	ZiApi::ZiLogger::setMinSeverity(LogSeverity::NORMAL);
	ZiApi::ZiLogger::setCurrentStream(ZiApi::ZiLogger::OutputStream::COUT);

	Log(LogType::INFO, LogSeverity::NORMAL) << "Program started" << ZiApi::ZiLogger::endl;

	LogType::DEBUG << "init resources" << ZiApi::ZiLogger::endl;
	ZiApi::ZiLogger::setMinSeverity(LogSeverity::IMPORTANT);

	LogType::INFO << LogSeverity::NORMAL << "Open assets folder" << ZiApi::ZiLogger::endl;

	Log(LogType::ERROR, LogSeverity::VITAL) << "File: \"logo.png\" not found" << ZiApi::ZiLogger::endl;

	LogType::WARNING << LogSeverity::NORMAL << "Enter error handler " << LogSeverity::IMPORTANT << ": " << 3  << " warnings generated"<< ZiApi::ZiLogger::endl;
}
