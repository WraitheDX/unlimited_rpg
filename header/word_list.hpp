
#ifndef _WORD_LIST_HPP_
#define _WORD_LIST_HPP_

// C++ Includes
#include <map>
#include <string>

namespace Vocab {
	enum class NounList	{
		null = 0,
		north, south,
		east, west
	};

	enum class VerbList {
		null = 0,
		exit,
		fight,
		go,
		heal,
		look,
		run
	};

	static
	std::map <std::string, NounList> g_noun_map = {
		{ "north", NounList::north }, { "south", NounList::south },
		{ "east", NounList::east }, { "west", NounList:: west }
	};

	static
	std::map <std::string, VerbList> g_verb_map = {
		{ "exit", VerbList::exit }, { "fight", VerbList::fight },
		{ "go", VerbList::go }, { "heal", VerbList::heal },
		{ "look", VerbList::look }, { "run", VerbList::run },
	};
}

#endif // _WORD_LIST_HPP_
