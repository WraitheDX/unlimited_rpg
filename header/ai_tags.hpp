
#ifndef _AI_TAGS_HPP_
#define _AI_TAGS_HPP_

namespace AITags {
	enum class TagList {
		null = 0,
		aggro,
		idle
	};

	static
	std::map <std::string, TagList> g_tag_map = {
		{ "aggro", TagList::aggro }, { "idle", TagList::idle }
	};

	struct Tag {
		Tag( const TagList p_tag_type, Int64 p_value ) :
			m_tag_type( p_tag_type ),
			m_value( p_value )
		{
		
		}

		TagList m_tag_type;
		Int64 m_value;
	};
}

#endif // _AI_TAGS_HPP_
