#include "moai-gwen/MOAIGwenSkin.h"

//----------------------------------------------------------------//
MOAIGwenSkin::MOAIGwenSkin () :
	mGwenSkin( 0 )
{
	RTTI_SINGLE ( MOAILuaObject )
}

//----------------------------------------------------------------//
MOAIGwenSkin::~MOAIGwenSkin () {
	if( this->mGwenSkin ) {
		delete this->mGwenSkin;
	}
}

//----------------------------------------------------------------//
void MOAIGwenSkin::RegisterLuaClass ( MOAILuaState& state ) {
	UNUSED( state );
}

//----------------------------------------------------------------//
void MOAIGwenSkin::RegisterLuaFuncs ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
