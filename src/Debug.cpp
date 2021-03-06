/*-------------------------------------------------------------------
 * Purpose:
 *         Debug class cpp
 * Time:
 *         2011��12��8�� 22:06:34
 * Author:
 *         ������
--------------------------------------------------------------------*/

#include "Debug.h"
#include "Util.h"
#include "Config.h"

#include <fstream>
#include <iostream>

EF_NAMESPACE_BEGIN

static const std::string log_file_name("log.txt");
static const std::string debug_file_name("debug.txt");

std::string log_file_path = LOG_PATH + log_file_name;
std::string debug_file_path = TEMP_PATH + debug_file_name;

//std::fstream D::log_file(log_file_path.c_str(),std::ios_base::app);

std::fstream log_stream(log_file_path.c_str(),std::ios_base::app);
std::fstream debug_stream(debug_file_path.c_str(),std::ios_base::out);

EfDebug d(debug_stream,std::cout);
EfDebug l(log_stream);
EfDebug e(log_stream,std::cout);
EfDebug i(std::cout);

EF_NAMESPACE_END
