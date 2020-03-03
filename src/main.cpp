
// Local Includes
#include "../header/command_parser.hpp"
#include "../header/factory.hpp"
#include "../header/game_data.hpp"
#include "../header/logger.hpp"
#include "../header/room.hpp"

int main()
{
	Logger::newLog( LogLevel::LOG_LEVEL_PROGRESS_DETAILED );

	Factory::player_create( "Player" );
	room = Factory::room_create( "room_main_menu.txt" );
	if( room == nullptr ) {
		return 0;
	}

	while( GameData::m_game_running ) {
		room->game_loop();

		Factory::room_change();
	}

	Factory::room_destroy( room );
	Factory::player_destroy();

	return 0;
}
