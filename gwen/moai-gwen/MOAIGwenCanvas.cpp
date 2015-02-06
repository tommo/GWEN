#include "moai-gwen/MOAIGwenCanvas.h"


//----------------------------------------------------------------//
MOAIGwenCanvas::MOAIGwenCanvas () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
	this->SetInternalControl( new Gwen::Controls::Canvas( NULL ) );

}

//----------------------------------------------------------------//
MOAIGwenCanvas::~MOAIGwenCanvas () {
}

//----------------------------------------------------------------//
void MOAIGwenCanvas::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenCanvas::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
