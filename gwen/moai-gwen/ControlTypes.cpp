#include "ControlTypes.h"

MOAIGwenControl* MOAIGwenControl::_GwenToMoai( Gwen::Controls::Base* control0 ) {
	if( !control0 ) return NULL;

	MOAIGwenControl* control;
	if( control0->m_ExternalRef ){
		control = static_cast< MOAIGwenControl::ControlRef* >( control0->m_ExternalRef )->owner;
		if( control )	return control;
	}
	const char* typeName = control0->GetTypeName();
	
	// if( gwen_cast< Gwen::Controls::Button >( control0 ) )
	// 	return new MOAIGwenButton( control0 );

	if( gwen_cast< Gwen::Controls::Canvas >( control0 ) )
	{ control = new MOAIGwenCanvas(); }
	else
	{ return NULL; }

	control->SetInternalControl( control0 );
	return control;
}
