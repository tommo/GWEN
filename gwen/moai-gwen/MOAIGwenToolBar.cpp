#include "moai-gwen/MOAIGwenToolBar.h"

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenToolBar::CreateGwenControl() {
	return new Gwen::Controls::ToolBarStrip( NULL );
}

//----------------------------------------------------------------//
MOAIGwenToolBar::MOAIGwenToolBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenToolBar::~MOAIGwenToolBar () {
}

//----------------------------------------------------------------//
void MOAIGwenToolBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenToolBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
