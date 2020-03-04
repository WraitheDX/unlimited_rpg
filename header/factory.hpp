
#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

// C++ Includes
#include <fstream>
#include <string>
#include <vector>
// Local Includes
#include "code_definitions.hpp"
#include "word_list.hpp"
// Forward Declarations
class Room;

namespace Factory {
	const Int64 npc_create( const std::string & p_file_name, std::vector <std::string> p_tag_list = std::vector <std::string>() );
	void		npc_destroy( UInt64 p_npc_id );

	void		player_create( const std::string & p_name );
	void		player_destroy();

	void		room_change();
	Room *	room_create( const std::string & p_file_name );
	void		room_destroy( Room * p_room );
}

#endif // _FACTORY_HPP_
