#include "Global.h"
#include "CLog.h"

using namespace boost::program_options;

int main(int argc, char* argv[])
{
	try
	{
		boost::filesystem::path full_path(boost::filesystem::initial_path<boost::filesystem::path>());
		full_path = boost::filesystem::system_complete(boost::filesystem::path(argv[0]));
		full_path = full_path.branch_path();
		gs_str_executable_path = full_path.string();
		//string str_config_file_full_path = full_path.string() + "/" + filename;
	}
	catch (...)
	{
		return ERR_FAILURE;
	}

	CLog::Init(gs_str_executable_path, 1, 1, "debug", "trace");

	options_description opts(APP_DESCRIPTION);

	opts.add_options()
		("help,h", "help message")
		("localport", value<unsigned int>()->default_value(0), "Local port of application to be mapped.")
		//("filename,f", value<string>(&filename)->default_value("text"), "to find a file")
		//("dir,D", value<vector<string> >()->multitoken(), "search dir")
		("depth,d", value<int>()->implicit_value(5), "search depth");

	variables_map vm;
	store(parse_command_line(argc, argv, opts), vm);
	notify(vm);
	
	try
	{
		if (vm.count("depth"))
		{
			//...vm['depth'].as<int>()
		}
	}
	catch (std::exception& e)
	{
		LOG_ERROR << e.what();
		return ERR_FAILURE;
	}

	return ERR_SUCCESS;
}