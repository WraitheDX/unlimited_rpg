
#ifndef _COMBATANT_HPP_
#define _COMBATANT_HPP_

// Local Includes
#include "actor.hpp"

class Combatant : public Actor {
public:
	explicit
	Combatant( const std::string & p_name, const Int64 p_health, const Int64 p_damage ) :
		Actor( p_name, p_health, p_damage )
	{
		
	}

	~Combatant() = default;

private:

};

#endif // _COMBATANT_HPP_
