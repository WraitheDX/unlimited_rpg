
#include "../header/npc.hpp"
// Local Includes
#include "../header/screen_print.hpp"
#include "../header/ai_tags.hpp"

NPC::NPC( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold,
					std::vector <std::string> & p_tags ) :
	Actor( p_id, p_name, p_health, p_damage, p_gold ),
	m_tags(),
	m_state( AITags::TagList::null )
{
	size_t l_tag_count( p_tags.size() );
	for( size_t l_tag_iter( 0 ); l_tag_iter < l_tag_count; ++l_tag_iter ) {
		std::map <std::string, AITags::TagList>::iterator l_map_iter( AITags::g_tag_map.find( p_tags[ l_tag_iter ] ) );
		if( l_map_iter != AITags::g_tag_map.end() ) {
			Bool l_tag_exists( false );

			size_t l_current_tags_count( m_tags.size() );
			for( size_t l_current_tags_iter( 0 ); l_current_tags_iter < l_current_tags_count; ++l_current_tags_iter ) {
				if( m_tags[ l_current_tags_iter ].m_tag_type == l_map_iter->second ) {
					l_tag_exists = true;
					break;
				}
			}

			if( !l_tag_exists ) {
				m_tags.push_back( AITags::Tag( l_map_iter->second, 0 ) );
			}
		}
	}

	if( !m_tags.empty() ) {
		m_state = m_tags[ 0 ].m_tag_type;
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
