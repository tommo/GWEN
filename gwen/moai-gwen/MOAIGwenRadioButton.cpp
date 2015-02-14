#include "moai-gwen/MOAIGwenRadioButton.h"


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenRadioButton::CreateGwenControl() {
	return new Gwen::Controls::RadioButton( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenRadioButton::MOAIGwenRadioButton () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenCheckBox )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenRadioButton::~MOAIGwenRadioButton () {
}


//----------------------------------------------------------------//
void MOAIGwenRadioButton::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenCheckBox::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenRadioButton::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenCheckBox::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
