
#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

// C++ Includes
#include <string>

class Entity {
public:
	explicit
	Entity( const std::string & p_name ) :
		m_name( p_name )
	{
	
	}

	virtual ~Entity() = default;

	const std::string & get_name() { return m_name; }

private:
	std::string m_name;
};

#endif // _ENTITY_HPP_
