
#ifndef _GAME_STATE_PLAY_HPP_
#define _GAME_STATE_PLAY_HPP_

// Local Includes
#include "factory.hpp"
#include "game_data.hpp"
#include "game_state.hpp"
#include "logger.hpp"
#include "screen_print.hpp"

class GameStatePlay final : public GameState {
public:
	GameStatePlay() {
		Factory::player_create( "Player" );
		room = Factory::room_create( "room_healer_hut.txt" );
	}

	~GameStatePlay() = default;

	void clean_up() override {
		Factory::player_destroy();
		Factory::room_destroy( room );
	}

	void update() override {
		room->game_loop();

		Factory::room_change();
	}
};

#endif // _GAME_STATE_PLAY_HPP_
