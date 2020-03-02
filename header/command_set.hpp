
#ifndef _COMMAND_SET_HPP_
#define _COMMAND_SET_HPP_

// Local Includes
#include "code_definitions.hpp"
#include "word_list.hpp"

struct CommandSet {
	CommandSet() :
		m_verb( Vocab::VerbList::null ),
		m_noun( Vocab::NounList::null ),
		m_value( 0 )
	{
	
	}

	Vocab::VerbList m_verb;
	Vocab::NounList m_noun;

	Int64 m_value;
};

#endif // _COMMAND_SET_HPP_
