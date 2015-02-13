#include "moai-gwen/MOAIGwenButton.h"


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
	
	state.SetField ( -1, "EVENT_CLICK",					( u32 )EVENT_CLICK );
	state.SetField ( -1, "EVENT_UP",					( u32 )EVENT_UP );
	state.SetField ( -1, "EVENT_DOWN",					( u32 )EVENT_DOWN );
	state.SetField ( -1, "EVENT_TOGGLE",					( u32 )EVENT_TOGGLE );

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
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
