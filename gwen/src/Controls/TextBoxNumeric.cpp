/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "Gwen/Gwen.h"
#include "Gwen/Controls/TextBox.h"
#include "Gwen/Skin.h"
#include "Gwen/Utility.h"
#include "Gwen/Platform.h"


using namespace Gwen;
using namespace Gwen::Controls;

GWEN_CONTROL_CONSTRUCTOR( TextBoxNumeric )
{
	SetText( GWEN_T("0") );
}

bool TextBoxNumeric::IsTextAllowed( const Gwen::UnicodeString & str, int iPos )
{
	const UnicodeString & strString = GetText().GetUnicode();

	if ( str.length() == 0 )
	{ return true; }

	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( str[i] == GWEN_T('-') )
		{
			// Has to be at the start
			if ( i != 0 || iPos != 0 )
			{ return false; }

			// Can only be one
			if ( std::count( strString.begin(), strString.end(), L'-' ) > 0 )
			{ return false; }

			continue;
		}

		if ( str[i] == GWEN_T('0') ) { continue; }

		if ( str[i] == GWEN_T('1') ) { continue; }

		if ( str[i] == GWEN_T('2') ) { continue; }

		if ( str[i] == GWEN_T('3') ) { continue; }

		if ( str[i] == GWEN_T('4') ) { continue; }

		if ( str[i] == GWEN_T('5') ) { continue; }

		if ( str[i] == GWEN_T('6') ) { continue; }

		if ( str[i] == GWEN_T('7') ) { continue; }

		if ( str[i] == GWEN_T('8') ) { continue; }

		if ( str[i] == GWEN_T('9') ) { continue; }

		if ( str[i] == GWEN_T('.') )
		{
			// Already a fullstop
			if ( std::count( strString.begin(), strString.end(), L'.' ) > 0 )
			{ return false; }

			continue;
		}

		return false;
	}

	return true;
}

float TextBoxNumeric::GetFloatFromText()
{
	double temp = Gwen::Utility::Strings::To::Float( GetText().GetUnicode() );
	return temp;
}
