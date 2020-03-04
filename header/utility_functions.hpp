
#ifndef _UTILITY_FUNCTIONS_HPP_
#define _UTILITY_FUNCTIONS_HPP_

// C++ Includes
#include <string>
// Local Includes
#include "code_definitions.hpp"

Bool is_number( const std::string & p_string ) {
	size_t l_string_size( p_string.size() );
	for( size_t l_string_iter( 0 ); l_string_iter < l_string_size; ++l_string_iter ) {
		if( !isdigit( p_string[ l_string_iter ] ) ) {
			return false;
		}
	}

	return true;
}

#endif // _UTILITY_FUNCTIONS_HPP_
