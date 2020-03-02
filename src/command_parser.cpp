
#include "../header/command_parser.hpp"
// C++ Includes
#include <iostream>
#include <map>
#include <vector>
// Local Includes
#include "../header/code_definitions.hpp"
#include "../header/command_set.hpp"
#include "../header/logger.hpp"
#include "../header/utility_functions.hpp"
#include "../header/word_list.hpp"

namespace CommandParser {
	CommandSet tokenize_commands( std::string & p_player_input ) {
		std::vector <std::string> l_commands;
		while( !p_player_input.empty() ) {
			while( p_player_input.front() == ' ' ) {
				p_player_input.erase( 0, 1 );
			}

			size_t l_command_iter( p_player_input.find( " " ) );
			l_commands.push_back( p_player_input.substr( 0, l_command_iter ) );
			p_player_input.erase( 0, l_command_iter );
		}
		
		CommandSet l_command_set;

		size_t l_command_count( l_commands.size() );
		for( UInt8 l_command_iter( 0 ); l_command_iter < l_command_count; ++l_command_iter ) {
			std::map <std::string, Vocab::VerbList>::iterator l_verb_iterator( Vocab::g_verb_map.find( l_commands[ l_command_iter ] ) );
			if( l_verb_iterator != Vocab::g_verb_map.end() ) {
				if( l_command_set.m_verb == Vocab::VerbList::null ) {
					l_command_set.m_verb = l_verb_iterator->second;
				}

				continue;
			}
		
			std::map <std::string, Vocab::NounList>::iterator l_noun_iterator( Vocab::g_noun_map.find( l_commands[ l_command_iter ] ) );
			if( l_noun_iterator != Vocab::g_noun_map.end() ) {
				if( l_command_set.m_noun == Vocab::NounList::null ) {
					l_command_set.m_noun = l_noun_iterator->second;
				}

				continue;
			}

			if( ( is_number( l_commands[ l_command_iter ] ) ) &&
					( l_command_set.m_value == 0 ) ) {
				l_command_set.m_value = stoi( l_commands[ l_command_iter ] );
			}
		}

		return l_command_set;
	}

	CommandSet get_input() {
		std::string l_player_input;
		std::getline( std::cin, l_player_input );
		
		log_info << "Player command: " << l_player_input;
		return tokenize_commands( l_player_input );
	}

}
