#include "moai-gwen/MOAIGwenMenuBar.h"


Gwen::Controls::Base* MOAIGwenMenuBar::CreateGwenControl() {
	return new Gwen::Controls::MenuStrip( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenMenuBar::MOAIGwenMenuBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenMenu )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenMenuBar::~MOAIGwenMenuBar () {
}


//----------------------------------------------------------------//
void MOAIGwenMenuBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenMenu::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenMenuBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenMenu::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
