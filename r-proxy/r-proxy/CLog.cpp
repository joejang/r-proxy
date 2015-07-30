#include "Global.h"
#include "CLog.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
using namespace logging::trivial;

src::severity_logger<severity_level> CLog::ms_log = src::severity_logger<severity_level>();

void CLog::Init(std::string str_executable_path, int i_file_log_on_, int i_console_log_on_, const char* pcsz_file_log_filter, const char* pcsz_console_log_filter)
{
	int i_file_log_on = i_file_log_on_;
	int i_console_log_on = i_console_log_on_;
	std::string str_file_log_filter = pcsz_file_log_filter;
	std::string str_console_log_filter = pcsz_console_log_filter;

	severity_level file_log_filter_level = trace;
	severity_level console_log_filter_level = trace;

	if (i_file_log_on)
	{

		if ((int)str_file_log_filter.find("debug") >= 0)
		{
			file_log_filter_level = debug;
		}
		else if ((int)str_file_log_filter.find("info") >= 0)
		{
			file_log_filter_level = info;
		}
		else if ((int)str_file_log_filter.find("warning") >= 0)
		{
			file_log_filter_level = warning;
		}
		else if ((int)str_file_log_filter.find("error") >= 0)
		{
			file_log_filter_level = error;
		}
		else if ((int)str_file_log_filter.find("fatal") >= 0)
		{
			file_log_filter_level = fatal;
		}
		else if ((int)str_file_log_filter.find("trace") >= 0)
		{
			file_log_filter_level = trace;
		}
	}
	else
	{
		file_log_filter_level = fatal;
	}

	if (i_console_log_on)
	{
		if ((int)str_console_log_filter.find("debug") >= 0)
		{
			console_log_filter_level = debug;
		}
		else if ((int)str_console_log_filter.find("info") >= 0)
		{
			console_log_filter_level = info;
		}
		else if ((int)str_console_log_filter.find("warning") >= 0)
		{
			console_log_filter_level = warning;
		}
		else if ((int)str_console_log_filter.find("error") >= 0)
		{
			console_log_filter_level = error;
		}
		else if ((int)str_console_log_filter.find("fatal") >= 0)
		{
			console_log_filter_level = fatal;
		}
		else if ((int)str_console_log_filter.find("trace") >= 0)
		{
			console_log_filter_level = trace;
		}
	}
	else
	{
		console_log_filter_level = fatal;
	}

	{
		typedef sinks::synchronous_sink<sinks::text_file_backend> file_sink;
		boost::shared_ptr<file_sink> sp_file_sink(logging::add_file_log
			(
				keywords::file_name = str_executable_path + string(APP_NAME) + string("/_%Y-%m-%d_%N.log"),
				keywords::rotation_size = 10 * 1024 * 1024,
				keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
				//keywords::format = "[%TimeStamp%]: %Message%",
				keywords::filter = severity >= file_log_filter_level,
				keywords::open_mode = std::ios::app
				));
		logging::formatter formatter =
			(
				expr::stream
				<< "[" << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S") << "]"
				<< ": <" << logging::trivial::severity
				<< "> " << expr::smessage
				);
		sp_file_sink->set_formatter(formatter);
		sp_file_sink->locked_backend()->auto_flush(true);
		logging::core::get()->add_sink(sp_file_sink);
	}

	{
		typedef sinks::synchronous_sink<sinks::text_ostream_backend> console_sink;
		boost::shared_ptr<console_sink> sp_console_sink(
			logging::add_console_log()
			);

		logging::formatter formatter =
			(
				expr::stream
				<< expr::attr<unsigned int>("LineID")
				<< ": <" << logging::trivial::severity
				<< "> " << expr::smessage
				);

		sp_console_sink->set_filter(severity >= console_log_filter_level);
		sp_console_sink->set_formatter(formatter);
		logging::core::get()->add_sink(sp_console_sink);
	}

	logging::add_common_attributes();
}

src::severity_logger<severity_level>& CLog::GetLogger()
{
	return ms_log;
}
