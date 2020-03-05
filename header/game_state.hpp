
#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

// Local Includes
#include "game_state_manager.hpp"

class GameState {
public:
	explicit
	GameState()
	{
	
	}

	virtual ~GameState() = default;

	virtual
	void clean_up() {}

	virtual
	void update() = 0;
};

#endif // _GAME_STATE_HPP_
