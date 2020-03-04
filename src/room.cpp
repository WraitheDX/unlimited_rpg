
#include "../header/room.hpp"
// Local Includes
#include "../header/npc.hpp"
#include "../header/command_parser.hpp"
#include "../header/command_set.hpp"
#include "../header/factory.hpp"
#include "../header/game_data.hpp"
#include "../header/game_state_manager.hpp"

std::map <std::string, RoomList> Room::g_roomlist_map = {
	{ "MAIN_MENU", RoomList::main_menu },
	{ "GAMEPLAY", RoomList::gameplay } 
};

void display_stats( Actor & p_actor );

void Room::clean_up() {
	size_t l_actor_count( m_actor_ids.size() );
	for( size_t l_actor_iter( 0 ); l_actor_iter < l_actor_count; ++l_actor_iter ) {
		Factory::npc_destroy( m_actor_ids[ l_actor_iter ] );
	}

	m_actor_ids.clear();
}

void Room::game_loop() {
	spp << "\t\t" << m_name << "\n\n";

	for( size_t l_iter( 0 ); l_iter < actors.size(); ++l_iter ) {
		if( !dynamic_cast<Player *>( actors[ l_iter ] ) ) {
			actors[ l_iter ]->update();
		}
	}

	CommandSet l_command_set( CommandParser::get_input() );

	switch( l_command_set.m_verb ) {
	case Vocab::VerbList::exit: {
		GameStateManager::game_state_set_next( GameStateManager::GameStateList::MAIN_MENU );
	} break;
	case Vocab::VerbList::fight: {
		
	} break;
	case Vocab::VerbList::go: {
		switch( l_command_set.m_noun ) {
		case Vocab::NounList::north: case Vocab::NounList::south:
		case Vocab::NounList::east: case Vocab::NounList::west: {
			size_t l_exit_count( m_exits.size() );
			for( size_t l_exit_iter( 0 ); l_exit_iter < l_exit_count; ++l_exit_iter ) {
				if( m_exits[ l_exit_iter ].m_exit_flag == l_command_set.m_noun ) {
					room_next = Factory::room_create( m_exits[ l_exit_iter ].m_file_name );
				}
			}
		} break;
		}
	} break;
	case Vocab::VerbList::heal: {
		spp << "You heal " << l_command_set.m_value << " health!\n";
	} break;
	case Vocab::VerbList::look: {
		size_t l_exit_count( m_exits.size() );
		for( size_t l_exit_iter( 0 ); l_exit_iter < l_exit_count; ++l_exit_iter ) {
			spp << m_exits[ l_exit_iter ].m_exit_name;

			if( l_exit_iter < l_exit_count - 1 ) {
				spp << ", ";
			} else {
				spp << "\n";
			}
		}

		spr;
	} break;
	case Vocab::VerbList::run: {
		spp << "You run for it!\n";
	} break;
	case Vocab::VerbList::spawn: {
		switch( l_command_set.m_noun ) {
		case Vocab::NounList::orc: {
			spp << "You spawn an orc!\n";
			Factory::npc_create( "orc.txt" );
		} break;
		default: {
			spp << "What is it you wish to spawn?\n";
		} break;
		}
	} break;
	default: {
		spp << "Unknown command\n";
	} break;
	}

	spr;
}

void display_stats( Actor & p_actor )
{
	spp << p_actor.get_name() << "\nHP: " << p_actor.get_health_current()
			<< "/" << p_actor.get_health_max() << "\n";
}
