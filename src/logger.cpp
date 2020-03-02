
#include "../header/logger.hpp"

LogLevel			Logger::m_log_level( LogLevel::LOG_LEVEL_ERROR );
std::string		Logger::m_file_name( LOGGER_FILE_NAME );              // The desired named of the log file
