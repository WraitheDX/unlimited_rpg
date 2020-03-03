
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

// Local Includes
#include "actor.hpp"

class Player final : public Actor {
public:
	explicit
	Player( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold ) :
		Actor( p_id, p_name, p_health, p_damage, p_gold )
	{
	
	}

	~Player() = default;

private:

};

#endif // _PLAYER_HPP_
