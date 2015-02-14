#include "moai-gwen/MOAIGwenSkinSimple.h"

//----------------------------------------------------------------//
MOAIGwenSkinSimple::MOAIGwenSkinSimple () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenSkin )
	RTTI_END
	this->mGwenSkin = new Gwen::Skin::Simple ( MOAIGwenMgr::Get().GetRenderer() );
}

//----------------------------------------------------------------//
MOAIGwenSkinSimple::~MOAIGwenSkinSimple () {
}

//----------------------------------------------------------------//
void MOAIGwenSkinSimple::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenSkin::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenSkinSimple::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenSkin::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
