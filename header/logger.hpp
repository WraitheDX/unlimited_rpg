
#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

/// C++ Includes
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

#define LOGGER_FILE_NAME "log.txt"

// The hierarchy of message levels
// Errors should always be reported
enum class
  LogLevel {
  LOG_LEVEL_ERROR = 0,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_INFO,
  LOG_LEVEL_PROGRESS_CORE,
  LOG_LEVEL_PROGRESS_DETAILED
};

// Logging class that uses instantly destructed instances to write messages to a log file
class Logger final {
public:
  explicit
  Logger( const LogLevel p_message_level ) :
    m_message_level( p_message_level ),
    m_output_stream()
  {

  }

  ~Logger()
  {
    // Append newline to the end of the message
    m_output_stream << std::endl;

    // Record message only if the current log level is set at or above the log level of the message
    if( m_message_level <= m_log_level )
    {
      // Record the message in the log
      writeToFile( LOGGER_FILE_NAME, m_output_stream.str() );
    }
  }

  // Create log entry, beginning with date & timestamp, followed by message level,
  // ending with message and a newline
  std::ostringstream&
  log()
  {
    // Obtain the current time
    std::time_t l_time( std::time( 0 ) );
    // Convert the current time into something more easily handled
    std::tm l_current_time;
    localtime_s( &l_current_time, &l_time );

    // Append the month, adding 0 if needed to keep uniform alignment
    if( ( l_current_time.tm_mon + 1 ) < 10 )
    {
      m_output_stream << 0;
    }
    m_output_stream << ( l_current_time.tm_mon + 1 ) << "/";

    // Append day, adding 0 if needed to keep uniform alignment
    if( l_current_time.tm_mday < 10 )
    {
      m_output_stream << 0;
    }
    m_output_stream << l_current_time.tm_mday << " ";

    // Append hour, adding 0 if needed to keep uniform alignment
    if( l_current_time.tm_hour < 10 )
    {
      m_output_stream << 0;
    }
    m_output_stream << l_current_time.tm_hour << ":";

    // Append minutes, adding 0 if needed to keep uniform alignment
    if( l_current_time.tm_min < 10 )
    {
      m_output_stream << 0;
    }
    m_output_stream << l_current_time.tm_min << ":";

    // Append seconds, adding 0 if needed to keep uniform alignment
    if( l_current_time.tm_sec < 10 )
    {
      m_output_stream << 0;
    }
    m_output_stream << l_current_time.tm_sec << " ";

    // Append message log level
    switch( m_message_level )
    {
      case LogLevel::LOG_LEVEL_ERROR:
      {
        m_output_stream << "**ERROR**: ";
      } break;
      case LogLevel::LOG_LEVEL_WARNING:
      {
        m_output_stream << "!WARNING!: ";
      } break;
      case LogLevel::LOG_LEVEL_INFO:
      {
        m_output_stream << "--INFO---: ";
      } break;
      case LogLevel::LOG_LEVEL_PROGRESS_CORE:
      {
        m_output_stream << "~PROGRESS: ";
      } break;
      case LogLevel::LOG_LEVEL_PROGRESS_DETAILED:
      {
        m_output_stream << "~PROGRESS: ";
      } break;
    }

    return m_output_stream;
  }

  // Truncate the existing error log and set the level of messages to be recorded
  static void
  newLog( const LogLevel p_log_level )
  {
    // Write a new log file, truncating the old one if one exists
    writeToFile( LOGGER_FILE_NAME, "\n", true );
    setLogLevel( p_log_level );
  }

  // Set a new log level for future messages
  static void
  setLogLevel( const LogLevel p_log_level )
  {
    m_log_level = p_log_level;
  }

private:
  static  LogLevel      m_log_level;              // The level of messages the logger should report
  const   LogLevel      m_message_level;          // The message level of this instance
  static  std::string   m_file_name;              // The desired named of the log file
  std::ostringstream    m_output_stream;          // The stream used for concatenating the message

  // Write a string to the specified file name, with the option to truncate the file
  static void
  writeToFile( const std::string& p_relative_file_name,
               const std::string& p_file_contents,
               const bool p_truncate_file = false )
  {
    // Variable to store the write flag for file_open() operation
    std::ios_base::openmode l_write_flag;
    // Set flag to truncate if 'p_truncate' is true, else set it to append
    if( p_truncate_file )
    {
      l_write_flag = std::ios::trunc;
    }
    else
    {
      l_write_flag = std::ios::app;
    }

    // Open file 'p_relative_file_name'
    std::ofstream l_file( p_relative_file_name, l_write_flag );

    // Return false if file is unable to be opened
    if( !l_file.is_open() )
    {
      return;
    }

    // Write 'p_file_line' to back of file
    l_file << p_file_contents;

    // Close the file
    l_file.close();

    return;
  }
};

#define log_error             Logger( LogLevel::LOG_LEVEL_ERROR ).log()
#define log_warning           Logger( LogLevel::LOG_LEVEL_WARNING ).log()
#define log_info              Logger( LogLevel::LOG_LEVEL_INFO ).log()
#define log_progress_core     Logger( LogLevel::LOG_LEVEL_PROGRESS_CORE ).log()
#define log_progress_detailed Logger( LogLevel::LOG_LEVEL_PROGRESS_DETAILED ).log()

#endif // _LOGGER_HPP_
