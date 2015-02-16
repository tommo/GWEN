#include "moai-gwen/MOAIGwenStatusBar.h"

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenStatusBar::CreateGwenControl() {
	return new Gwen::Controls::StatusBar( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenStatusBar::MOAIGwenStatusBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenLabel )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenStatusBar::~MOAIGwenStatusBar () {
}


//----------------------------------------------------------------//
void MOAIGwenStatusBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenStatusBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
