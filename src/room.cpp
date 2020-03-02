
#include "../header/room.hpp"
// Local Includes
#include "../header/combatant.hpp"
#include "../header/command_parser.hpp"
#include "../header/command_set.hpp"
#include "../header/factory.hpp"
#include "../header/game_data.hpp"

std::map <std::string, RoomList> Room::g_roomlist_map = {
	{ "MAIN_MENU", RoomList::main_menu },
	{ "GAMEPLAY", RoomList::gameplay } 
};

void combat();
void display_stats( Actor & p_actor );
void exit_game();

void Room::game_loop()
{
	spp << "\t\t" << m_name << "\n\n";

	CommandSet l_command_set( CommandParser::get_input() );

	switch( l_command_set.m_verb ) {
	case Vocab::VerbList::exit: {
		exit_game();
	} break;
	case Vocab::VerbList::fight: {
		combat();
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
	default: {
		spp << "Unknown command\n";
	} break;
	}

	spr;
}

void combat()
{
	Combatant l_combatant( "Orc", 15, 3 );

	bool battle_running( true );
	while( battle_running ) {
		spp << "Player attacks " << l_combatant.get_name() << "!\n";
		l_combatant.adjust_health_current( -player->get_damage() );
		spp << "Orc attacks " << player->get_name() << "!\n";
		player->adjust_health_current( -l_combatant.get_damage() );

		display_stats( *player );
		display_stats( l_combatant );

		spr;

		if( !player->is_alive() ) {
			battle_running = false;
			spp << "You have been defeated by " << l_combatant.get_name() << "\n";
		} else if( !l_combatant.is_alive() ) {
			battle_running = false;
			spp << "You have bested " << l_combatant.get_name() << "\n";
		}

		spr;
	}
}

void display_stats( Actor & p_actor )
{
	spp << p_actor.get_name() << "\nHP: " << p_actor.get_health_current()
			<< "/" << p_actor.get_health_max() << "\n";
}

void exit_game() {
	GameData::m_game_running = false;

	spp << "Thank you so much for playing!\n\n";
	spr;
}
