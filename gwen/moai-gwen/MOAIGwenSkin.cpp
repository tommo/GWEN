#include "moai-gwen/MOAIGwenSkin.h"

//----------------------------------------------------------------//
int MOAIGwenSkin::_setDefaultFont ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenSkin, "USN" )
	cc8*  faceName = state.GetValue < cc8* >( 2, "" );
	float size     = state.GetValue < float >( 3, 10.0f );
	self->GetGwenSkin()->SetDefaultFont( Gwen::Utility::StringToUnicode( faceName ), size );
	return 0;
}

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
		{ "setDefaultFont",		_setDefaultFont },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
