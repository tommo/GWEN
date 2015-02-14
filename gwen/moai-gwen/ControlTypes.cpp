#include "ControlTypes.h"

#define GWEN_TO_MOAI( controlType, control0 ) \
	if( gwen_cast< Gwen::Controls::controlType >( control0 ) ) { \
		MOAIGwenControl* control = new MOAIGwen##controlType();\
		control->SetInternalControl( control0 );\
		return control;\
	}

MOAIGwenControl* MOAIGwenControl::_GwenToMoai( Gwen::Controls::Base* control0 ) {
	if( !control0 ) return NULL;

	if( control0->m_ExternalRef ){
		MOAIGwenControl* control = static_cast< MOAIGwenControl::ControlRef* >( control0->m_ExternalRef )->owner;
		if( control )	return control;
	}
	const char* typeName = control0->GetTypeName();
	
	GWEN_TO_MOAI( Button,        control0 )
	GWEN_TO_MOAI( Label,         control0 )
	GWEN_TO_MOAI( CheckBox,      control0 )
	GWEN_TO_MOAI( WindowControl, control0 )
	GWEN_TO_MOAI( Canvas,        control0 )

	return NULL;
}
