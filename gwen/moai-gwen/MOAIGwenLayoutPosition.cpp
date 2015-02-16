#include "moai-gwen/MOAIGwenLayoutPosition.h"

//----------------------------------------------------------------//
int MOAIGwenLayoutPosition::_setPosition ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutPosition, "U" )
	self->GetInternalControl()->SetPosition(
		state.GetValue < u32 >( 2, Gwen::Pos::Center )
		);
	return 0;
}


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenLayoutPosition::CreateGwenControl() {
	return new Gwen::Controls::Layout::Position( NULL );
}

//----------------------------------------------------------------//
MOAIGwenLayoutPosition::MOAIGwenLayoutPosition () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenLayoutPosition::~MOAIGwenLayoutPosition () {
}


//----------------------------------------------------------------//
void MOAIGwenLayoutPosition::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenLayoutPosition::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setPosition",      _setPosition  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
