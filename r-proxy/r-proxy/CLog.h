#ifndef CLOG_H
#define CLOG_H

#include "Global.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>

#define LOG_TRACE BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::trace)))
#define LOG_DEBUG BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::debug)))
#define LOG_INFO BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::info)))
#define LOG_WARNING BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::warning)))
#define LOG_ERROR BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::error)))
#define LOG_FATAL BOOST_LOG_WITH_PARAMS((CLog::GetLogger()), (boost::log::keywords::severity = (boost::log::trivial::fatal)))

class CLog
{
public:
	static void Init(std::string str_executable_path,
		int i_file_log_on_ = 1, int i_console_log_on_ = 1, 
		const char* pcsz_file_log_filter = "debug", const char* pcsz_console_log_filter = "trace");

	static boost::log::sources::severity_logger<boost::log::trivial::severity_level>& GetLogger();

	static boost::log::sources::severity_logger<boost::log::trivial::severity_level> ms_log;
};

#endif
