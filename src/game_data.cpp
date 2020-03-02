
#include "../header/game_data.hpp"

std::vector <Actor *> GameData::m_actors;

Bool GameData::m_game_running( true );

Player * GameData::m_player( nullptr );

Room * GameData::m_room( nullptr );
Room * GameData::m_room_next( nullptr );
