#include "moai-gwen/MOAIGwenDockBase.h"
//----------------------------------------------------------------//
int MOAIGwenDockBase::_getTabControl ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenDockBase, "U" )
	Gwen::Controls::TabControl* tab = self->GetInternalControl()->GetTabControl();
	if( tab ) {
		_GwenToMoai( tab )->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 0;
	}
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenDockBase::CreateGwenControl() {
	return new Gwen::Controls::DockBase( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenDockBase::MOAIGwenDockBase () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenDockBase::~MOAIGwenDockBase () {
}


//----------------------------------------------------------------//
void MOAIGwenDockBase::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenDockBase::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getTabControl",    _getTabControl },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
