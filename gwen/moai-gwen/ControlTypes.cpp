#include "ControlTypes.h"

#define TRY_GWEN_TO_MOAI( controlType, moaiType, control0 ) \
	if( gwen_cast< Gwen::Controls::controlType >( control0 ) ) { \
		MOAIGwenControl* control = new MOAIGwen##moaiType();\
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
	
	TRY_GWEN_TO_MOAI( Button,                 Button,               control0 )
	TRY_GWEN_TO_MOAI( Label,                  Label,                control0 )
	TRY_GWEN_TO_MOAI( LabelClickable,         LabelClickable,       control0 )
	TRY_GWEN_TO_MOAI( Rectangle,              Rectangle,            control0 )
	TRY_GWEN_TO_MOAI( CheckBox,               CheckBox,             control0 )
	TRY_GWEN_TO_MOAI( RadioButton,            RadioButton,          control0 )
	TRY_GWEN_TO_MOAI( ComboBox,               ComboBox,             control0 )
	TRY_GWEN_TO_MOAI( Menu,                   Menu,                 control0 )
	TRY_GWEN_TO_MOAI( MenuStrip,              MenuBar,              control0 ) //Renamed
	TRY_GWEN_TO_MOAI( MenuItem,               MenuItem,             control0 )
	TRY_GWEN_TO_MOAI( ToolBarStrip,           ToolBar,              control0 ) //Renamed
	TRY_GWEN_TO_MOAI( ToolBarButton,          ToolButton,           control0 ) //Renamed
	TRY_GWEN_TO_MOAI( RadioButtonController,  RadioButtonGroup,     control0 ) //Renamed
	TRY_GWEN_TO_MOAI( ScrollControl,          ScrollControl,        control0 )
	TRY_GWEN_TO_MOAI( ProgressBar,            ProgressBar,          control0 )
	TRY_GWEN_TO_MOAI( WindowControl,          WindowControl,        control0 )
	TRY_GWEN_TO_MOAI( Canvas,                 Canvas,               control0 )
	TRY_GWEN_TO_MOAI( ColorPicker,            ColorPicker,          control0 )
	//TODO:wrap other control with common class?

	return NULL;
}
