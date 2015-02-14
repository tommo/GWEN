/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/

#pragma once
#ifndef GWEN_TEXTOBJECT_H
#define GWEN_TEXTOBJECT_H

#include "Gwen/Utility.h"
#include <stdlib.h>
#include <string.h>

namespace Gwen
{
	/*

		TextObjects can be either a UnicodeString or a String

		Just makes things easier instead of having a function taking both.

	*/
	class TextObject
	{
		public:

			TextObject() {}

			TextObject( const UnicodeChar *text)
			{
				m_Unicode = text;
			}

			TextObject( const Gwen::UnicodeString & unicode )
			{
				*this = unicode;
			}

			operator const Gwen::UnicodeString&() const
			{
				return m_Unicode;
			}

			void operator = ( const Gwen::UnicodeString & unicodeStr )
			{
				m_Unicode = unicodeStr;
			}

			bool operator == ( const TextObject & to ) const
			{
				return m_Unicode == to.m_Unicode;
			}

			const Gwen::String & Get() const
			{
				return m_Unicode;
			}

			const Gwen::UnicodeString & GetUnicode() const
			{
				return m_Unicode;
			}

			const char* c_str(){
				return m_Unicode.c_str();
			}

			int length() const { return m_Unicode.length(); }

		private:
			Gwen::UnicodeString		m_Unicode;
	};
}
#endif
