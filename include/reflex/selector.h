// -*- c++ -*-
#pragma once
#ifndef __REFLEX_SELECTOR_H__
#define __REFLEX_SELECTOR_H__


#include <set>
#include <xot/pimpl.h>
#include <xot/string.h>
#include <reflex/defs.h>


namespace Reflex
{


	class Selector
	{

		typedef Selector This;

		public:

			typedef std::set<String> TagSet;

			typedef TagSet::      iterator       iterator;

			typedef TagSet::const_iterator const_iterator;

			Selector (const char* name = NULL);

			void    set_name (const char* name);

			const char* name () const;

			void    add_tag (const char* tag);

			void remove_tag (const char* tag);

			      iterator begin ();

			const_iterator begin () const;

			      iterator end ();

			const_iterator end () const;

			bool match (const This& obj) const;

			friend bool operator == (const This& lhs, const This& rhs);

			friend bool operator != (const This& lhs, const This& rhs);

			struct Data;

			Xot::PImpl<Data, true> self;

	};// Selector


}// Reflex


#endif//EOH
