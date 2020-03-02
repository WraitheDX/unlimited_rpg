
#ifndef _COMMAND_PARSER_HPP_
#define _COMMAND_PARSER_HPP_

// C++ Includes
#include <string>
// Local Includes
#include "command_set.hpp"

namespace CommandParser {
	CommandSet get_input();
	CommandSet tokenize_commands( std::string & p_player_input );
}

#endif // _COMMAND_PARSER_HPP_
