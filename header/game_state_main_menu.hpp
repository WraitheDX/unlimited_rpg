
#ifndef _GAME_STATE_MAIN_MENU_HPP_
#define _GAME_STATE_MAIN_MENU_HPP_

// Local Includes
#include "command_parser.hpp"
#include "game_data.hpp"
#include "game_state.hpp"
#include "logger.hpp"
#include "screen_print.hpp"

class GameStateMainMenu final : public GameState {
public:
	explicit
	GameStateMainMenu() :
		GameState()
	{
	
	}

	~GameStateMainMenu() = default;

	void update() {
		spp << "\t\tWelcome to the RPG!\n\n"
				<< "Type 'play' to start a new game, or 'exit' to exit the game.\n";

		CommandSet l_command_set( CommandParser::get_input() );
		switch( l_command_set.m_verb ) {
		case Vocab::VerbList::exit: {
			GameData::m_game_running = false;
		} break;
		case Vocab::VerbList::play: {
			GameStateManager::game_state_set_next( GameStateManager::GameStateList::PLAY );
		} break;
		}

		spr;
	}

private:

};

#endif // _GAME_STATE_MAIN_MENU_HPP_
