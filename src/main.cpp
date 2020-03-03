
// Local Includes
#include "../header/game_data.hpp"
#include "../header/game_state_main_menu.hpp"
#include "../header/game_state_manager.hpp"
#include "../header/logger.hpp"

int main()
{
	Logger::newLog( LogLevel::LOG_LEVEL_PROGRESS_DETAILED );

	game_state_create( GameStateManager::GameStateList::MAIN_MENU );

	while( GameData::m_game_running ) {
		GameStateManager::game_state_update();
		GameStateManager::game_state_change();
	}

	return 0;
}
