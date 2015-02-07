#include "moai-gwen/MOAIGwenWindowControl.h"


Gwen::Controls::Base* MOAIGwenWindowControl::CreateGwenControl() {
	return new Gwen::Controls::WindowControl( MOAIGwenMgr::Get().GetDefaultCanvas() );
}

//----------------------------------------------------------------//
MOAIGwenWindowControl::MOAIGwenWindowControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenWindowControl::~MOAIGwenWindowControl () {
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "new",		_new },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
