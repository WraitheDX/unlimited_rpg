
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

// Local Includes
#include "actor.hpp"

class Player final : public Actor {
public:
	explicit
	Player( const std::string & p_name, const Int64 p_health, const Int64 p_damage ) :
		Actor( p_name, p_health, p_damage )
	{
	
	}

	~Player() = default;

private:

};

#endif // _PLAYER_HPP_
