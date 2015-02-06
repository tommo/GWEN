#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/Button.h"


//----------------------------------------------------------------//
MOAIGwenButton::MOAIGwenButton () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
	this->SetInternalControl( 
		new Gwen::Controls::Button( MOAIGwenMgr::Get().GetDefaultCanvas() ) 
		);
}

//----------------------------------------------------------------//
MOAIGwenButton::~MOAIGwenButton () {
}

//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
