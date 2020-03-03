
#ifndef _NPC_HPP_
#define _NPC_HPP_

// Local Includes
#include "actor.hpp"

class NPC : public Actor {
public:
	explicit
	NPC( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold ) :
		Actor( p_id, p_name, p_health, p_damage, p_gold )
	{
		
	}

	~NPC() = default;

private:

};

#endif // _NPC_HPP_
