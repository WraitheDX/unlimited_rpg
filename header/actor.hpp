
#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

// Local Includes
#include "code_definitions.hpp"
#include "entity.hpp"
#include "logger.hpp"

class Actor : public Entity {
public:
	explicit
	Actor( const UInt64 p_id, const std::string & p_name, const Int64 p_health, const Int64 p_damage, const Int64 p_gold ) :
		Entity( p_id, p_name ),
		m_alive( true ),
		m_health_current( p_health ),
		m_health_max( p_health ),
		m_damage( p_damage ),
		m_gold( p_gold )
	{
		log_progress_detailed << "Creating Combatant - " << get_name() << ", HP: " << get_health_max() << ", Dam: " << get_damage();
	}

	virtual ~Actor() = default;

	const Bool is_alive() { return m_alive; }

	const Int64 get_health_current() { return m_health_current; }
	const Int64 get_health_max() { return m_health_max; }
	const Int64 get_damage() { return m_damage; }

	void adjust_health_current( const Int64 p_health )
	{
		m_health_current += p_health;

		health_check_range();
	}

	void set_health_current( const Int64 p_health )
	{
		m_health_current = p_health;

		health_check_range();
	}

private:
	void health_check_range()
	{
		if( m_health_current <= 0 ) {
			m_health_current = 0;

			m_alive = false;
		} else if( m_health_current > m_health_max ) {
			m_health_current = m_health_max;
		}
	}

	Bool m_alive;

	Int64 m_health_current;
	Int64 m_health_max;

	Int64 m_damage;
	Int64 m_gold;
};

#endif // _ACTOR_HPP_
