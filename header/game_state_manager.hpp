
#ifndef _GAME_STATE_MANAGER_HPP_
#define _GAME_STATE_MANAGER_HPP_

// Forward Declarations
class GameState;

namespace GameStateManager {
	enum class GameStateList {
		GAME_STATE_NULL,
		MAIN_MENU,
		PLAY
	};

	void game_state_change();
	void game_state_clear();
	void game_state_create( const GameStateList p_game_state );
	void game_state_pop();
	void game_state_set_next( const GameStateManager::GameStateList p_next_state );
	void game_state_update();
}

#endif // _GAME_STATE_MANAGER_HPP_
