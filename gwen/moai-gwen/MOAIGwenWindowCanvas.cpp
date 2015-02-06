#include "moai-gwen/MOAIGwenWindowCanvas.h"


//----------------------------------------------------------------//
MOAIGwenWindowCanvas::MOAIGwenWindowCanvas () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenCanvas )
	RTTI_END
	// this->SetInternalControl( new Gwen::Controls::WindowCanvas( NULL ) );

}

//----------------------------------------------------------------//
MOAIGwenWindowCanvas::~MOAIGwenWindowCanvas () {
}

//----------------------------------------------------------------//
void MOAIGwenWindowCanvas::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenCanvas::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenWindowCanvas::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenCanvas::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
