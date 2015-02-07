#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/Button.h"


Gwen::Controls::Base* MOAIGwenButton::CreateGwenControl() {
	return new Gwen::Controls::Button( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenButton::MOAIGwenButton () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenButton::~MOAIGwenButton () {
}

//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ "new", _new },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
