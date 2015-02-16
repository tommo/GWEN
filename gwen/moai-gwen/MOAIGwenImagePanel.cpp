#include "moai-gwen/MOAIGwenImagePanel.h"

int MOAIGwenImagePanel::_setImage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenImagePanel, "US" )
	cc8* imageName = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetImage( imageName );
	return 0;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenImagePanel::CreateGwenControl() {
	return new Gwen::Controls::ImagePanel( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenImagePanel::MOAIGwenImagePanel () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenImagePanel::~MOAIGwenImagePanel () {
}


//----------------------------------------------------------------//
void MOAIGwenImagePanel::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenImagePanel::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setImage",   _setImage  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
