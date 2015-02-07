#include "moai-gwen/MOAIGwenCanvas.h"

Gwen::Controls::Base* MOAIGwenCanvas::CreateGwenControl() {
	return new Gwen::Controls::Canvas( NULL );
}

//----------------------------------------------------------------//
MOAIGwenCanvas::MOAIGwenCanvas () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenCanvas::~MOAIGwenCanvas () {
}

//----------------------------------------------------------------//
void MOAIGwenCanvas::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenCanvas::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
