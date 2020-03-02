
#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

// C++ Includes
#include <string>

static
std::string get_filepath_separator() {
#ifdef _WIN32
	{
		return "//";
	}
#endif // _WIN32
}

#endif // _PLATFORM_HPP_
