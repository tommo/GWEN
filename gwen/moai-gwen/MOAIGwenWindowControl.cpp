#include "moai-gwen/MOAIGwenWindowControl.h"


//----------------------------------------------------------------//
MOAIGwenWindowControl::MOAIGwenWindowControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
	this->SetInternalControl( 
		new Gwen::Controls::WindowControl( MOAIGwenMgr::Get().GetDefaultCanvas() )
	);

}

//----------------------------------------------------------------//
MOAIGwenWindowControl::~MOAIGwenWindowControl () {
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
