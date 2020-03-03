
#ifndef _NPC_HPP_
#define _NPC_HPP_

// C++ Includes
#include <map>
#include <string>
#include <vector>
// Local Includes
#include "actor.hpp"
#include "ai_tags.hpp"
#include "code_definitions.hpp"

class NPC : public Actor {
public:
	explicit
	NPC( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold,
			 std::vector <std::string> & p_tags );

	~NPC() = default;

	void update();

private:	
	std::vector <AITags::Tag> m_tags;

	AITags::TagList m_state;
};

#endif // _NPC_HPP_
