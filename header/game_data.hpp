
#ifndef _GAME_DATA_HPP_
#define _GAME_DATA_HPP_

// C++ Includes
#include <vector>
// Local Includes
#include "actor.hpp"
#include "code_definitions.hpp"
#include "player.hpp"
#include "room.hpp"

struct GameData {
	static Bool m_game_running;

	static Player * m_player;

	static Room * m_room;
	static Room * m_room_next;

	static std::vector <Actor *> m_actors;
};

#define actors				GameData::m_actors
#define game_running	GameData::m_game_running;
#define player				GameData::m_player
#define room					GameData::m_room
#define room_next			GameData::m_room_next

#endif // _GAME_DATA_HPP_
