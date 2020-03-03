
#include "../header/npc.hpp"
// Local Includes
#include "../header/screen_print.hpp"

NPC::NPC( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold,
					std::vector <std::string> & p_tags ) :
	Actor( p_id, p_name, p_health, p_damage, p_gold ),
	m_tags(),
	m_state( AITags::TagList::null )
{
	while( !p_tags.empty() ) {
		if( p_tags.front() == "AGGRO" ) {
			m_tags.push_back( AITags::Tag( AITags::TagList::aggro, 0 ) );
			m_state = AITags::TagList::aggro;
		}
		else if( p_tags.front() == "IDLE" ) {
			m_tags.push_back( AITags::Tag( AITags::TagList::idle, 0 ) );
			m_state = AITags::TagList::idle;
		}

		p_tags.erase( p_tags.begin() );
	}
}

void NPC::update() {
	switch( m_state ) {
	case AITags::TagList::aggro: {
		spp << get_name() << " is aggro!\n";
	} break;
	case AITags::TagList::idle: {
		spp << get_name() << " is idle...\n";
	} break;
	default: {
		spp << get_name() << " has no updatable state!\n";
	} break;
	}
}
