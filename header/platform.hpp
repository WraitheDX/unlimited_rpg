
#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

// C++ Includes
#include <string>
#include <filesystem>

static
std::string get_filepath_separator() {
	return std::string{std::filesystem::path::preferred_separator};
}

#endif // _PLATFORM_HPP_
