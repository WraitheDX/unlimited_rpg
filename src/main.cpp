
// Local Includes
#include "../header/game_data.hpp"
#include "../header/game_state_main_menu.hpp"
#include "../header/game_state_manager.hpp"
#include "../header/logger.hpp"
#include "../header/screen_print.hpp"

int main( int p_argument_count, char ** p_argument_list )
{
	/*
	for( int l( 0 ); l < argc; ++l ) {
		if( arguments[ l ] == "min" );
	}*/

	Logger::newLog( LogLevel::LOG_LEVEL_PROGRESS_DETAILED );

	game_state_create( GameStateManager::GameStateList::MAIN_MENU );

	try {
	while( GameData::m_game_running ) {
		GameStateManager::game_state_update();
		GameStateManager::game_state_change();
	}
	} catch( std::exception const & e ) { spp << e.what() << "\n"; spr; }

	return 0;
}
