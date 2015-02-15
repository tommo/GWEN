#include "moai-gwen/MOAIGwenMenu.h"


Gwen::Controls::Base* MOAIGwenMenu::CreateGwenControl() {
	return new Gwen::Controls::Menu( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenMenu::MOAIGwenMenu () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenScrollControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenMenu::~MOAIGwenMenu () {
}


//----------------------------------------------------------------//
void MOAIGwenMenu::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenMenu::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
