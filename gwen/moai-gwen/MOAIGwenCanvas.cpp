#include "moai-gwen/MOAIGwenCanvas.h"

int MOAIGwenCanvas::_setScale ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCanvas, "U" )
	self->GetInternalControl()->SetScale( state.GetValue< float >( 2, 1.0f ) );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenCanvas::CreateGwenControl() {
	return new Gwen::Controls::Canvas( NULL );
}

//----------------------------------------------------------------//
MOAIGwenCanvas::MOAIGwenCanvas () {
	this->mRootSystem = NULL;
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
		{ "setScale",  _setScale  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
