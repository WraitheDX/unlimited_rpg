
#ifndef _ROOM_HPP_
#define _ROOM_HPP_

// C++ Includes
#include <map>
#include <string>
#include <vector>
// Local Includes
#include "logger.hpp"
#include "screen_print.hpp"
#include "word_list.hpp"

struct GameData;

enum class RoomList {
	null = 0,
	main_menu,
	gameplay
};

struct ExitList {
	explicit
	ExitList( const Vocab::NounList p_exit_flag, const std::string & p_exit_name, const std::string & p_file_name ) :
		m_exit_flag( p_exit_flag ),
		m_exit_name( p_exit_name ),
		m_file_name( p_file_name )
	{
		
	}

	Vocab::NounList m_exit_flag;
	std::string			m_exit_name;
	std::string			m_file_name;
};

class Room {
public:
	explicit
	Room( const std::string & p_file_name, const RoomList p_room_type, const std::string & p_name, const std::vector <ExitList> & p_exit_list ) :
		m_room_type( p_room_type ),
		m_name( p_name ),
		m_exits( p_exit_list )
	{
		log_progress_core << "Room created, file name: " << p_file_name;
	}

	~Room() = default;

	void game_loop();

	static std::map <std::string, RoomList> g_roomlist_map;

private:
	RoomList m_room_type;

	std::string m_name;

	std::vector <ExitList> m_exits;
};

#endif // _ROOM_HPP_
