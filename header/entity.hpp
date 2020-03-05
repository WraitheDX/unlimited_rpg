
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

// C++ Includes
#include <string>
// Local Includes
#include "code_definitions.hpp"

class Entity {
public:
	explicit
	Entity( const UInt64 p_id, const std::string & p_name ) :
		m_id( p_id ),
		m_name( p_name )
	{
	
	}

	virtual ~Entity() = default;

	UInt64 get_id() { return m_id; }

	const std::string & get_name() { return m_name; }

private:
	const UInt64 m_id;

	std::string m_name;
};

#endif // _ENTITY_HPP_
