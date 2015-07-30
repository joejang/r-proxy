#ifndef GLOBAL_H
#define GLOBAL_H 

#define APP_DESCRIPTION "description"
#define APP_NAME "appname"

#define ERR_FAILURE 1
#define ERR_SUCCESS 0

// _WIN32 START
#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <Windows.h>
#	pragma warning(disable:4005)
#	ifndef NDEBUG
#		pragma comment(lib, "../Libs/win/32/boost/libboost_filesystem-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_system-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_date_time-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_regex-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_thread-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_chrono-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_log-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_log_setup-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_program_options-vc140-mt-sgd-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/vld/vld.lib")
#		include "../Libs/win/32/vld/include/vld.h"
#	else
#		pragma comment(lib, "../Libs/win/32/boost/libboost_filesystem-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_system-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_date_time-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_regex-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_thread-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_chrono-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_log-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_log_setup-vc140-mt-s-1_58.lib")
#		pragma comment(lib, "../Libs/win/32/boost/libboost_program_options-vc140-mt-s-1_58.lib")
#	endif
#endif
// _WIN32 END

// DEFAULT
#include <iostream>
#include <string.h>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip::address;
using namespace std;
using namespace boost::property_tree;

#define SAFE_DELETE(p) if(p!=NULL){delete p; p=NULL;}
#define SAFE_FREE(p) if(p!=NULL){free(p); p=NULL;}
#define SAFE_DELETE_ARRAY(p) if(p!=NULL){delete[] p; p=NULL;}

typedef struct st_new_head
{
	char	szProtocolId[4];
	unsigned int	uiProtclVersion;
	unsigned int	uiTotalSize;
	unsigned int	uiVersion;
	unsigned int	session;
	unsigned int	uiHeadSize;
	unsigned int	uiExtendHead;
	unsigned int	uiRtnCode; // 1 - success, other - not success
	unsigned short	cmd;
	char	szSessionKey[18];
}tcp_file_trans_head_v1;

static string gs_str_executable_path = "";
#endif
