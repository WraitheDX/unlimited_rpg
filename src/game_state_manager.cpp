
#include "../header/game_state_manager.hpp"
// C++ Includes
#include <vector>
// Local Includes
#include "../header/game_state.hpp"
#include "../header/game_state_main_menu.hpp"
#include "../header/game_state_play.hpp"

namespace GameStateManager {
	std::vector <GameState *> g_game_states;

	GameStateList g_next_state( GameStateList::GAME_STATE_NULL );

	GameStateList game_state_get_next() {
		GameStateList l_next_state = g_next_state;
		g_next_state = GameStateList::GAME_STATE_NULL;

		return l_next_state;
	}

	void game_state_change() {
		switch( game_state_get_next() ) {
		case GameStateList::GAME_STATE_NULL: break;
		case GameStateList::MAIN_MENU: {
			game_state_clear();
			game_state_create( GameStateList::MAIN_MENU );
		} break;
		case GameStateList::PLAY: {
			game_state_clear();
			game_state_create( GameStateList::PLAY );
		} break;
		}
	}

	void game_state_clear() {
		size_t l_game_state_count( g_game_states.size() );
		for( size_t l_game_state_iter( 0 ); l_game_state_iter < l_game_state_count; ++ l_game_state_iter ) {
			g_game_states[ l_game_state_iter ]->clean_up();
			delete g_game_states[ l_game_state_iter ];
		}

		g_game_states.clear();
	}

	void game_state_create( const GameStateList p_game_state ) {
		switch( p_game_state ) {
		case GameStateList::GAME_STATE_NULL: {
		
		} break;
		case GameStateList::MAIN_MENU: {
			g_game_states.push_back( new GameStateMainMenu() );
		} break;
		case GameStateList::PLAY: {
			g_game_states.push_back( new GameStatePlay() );
		} break;
		}
	}

	void game_state_pop() {
		g_game_states.back()->clean_up();

		delete g_game_states.back();
		g_game_states.pop_back();
	}

	void game_state_set_next( const GameStateList p_next_state ) {
		g_next_state = p_next_state;
	}

	void game_state_update() {
		g_game_states.back()->update();
	}
}
