#include "moai-gwen/MOAIGwenSkinTexturedBase.h"

int MOAIGwenSkinTexturedBase::_init ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenSkinTexturedBase, "US" )
	cc8* texName = state.GetValue < cc8* >( 2, "" );
	self->GetGwenSkin()->Init( texName );
	return 0;
}

//----------------------------------------------------------------//
MOAIGwenSkinTexturedBase::MOAIGwenSkinTexturedBase () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenSkin )
	RTTI_END
	this->mGwenSkin = new Gwen::Skin::TexturedBase ( MOAIGwenMgr::Get().GetRenderer() );
}

//----------------------------------------------------------------//
MOAIGwenSkinTexturedBase::~MOAIGwenSkinTexturedBase () {
}

//----------------------------------------------------------------//
void MOAIGwenSkinTexturedBase::RegisterLuaClass ( MOAILuaState& state ) {
	UNUSED( state );
}

//----------------------------------------------------------------//
void MOAIGwenSkinTexturedBase::RegisterLuaFuncs ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		{ "init",		_init },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
