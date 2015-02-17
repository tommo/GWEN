#include "moai-gwen/MOAIGwenTabControl.h"
#include "moai-gwen/MOAIGwenTabButton.h"

int MOAIGwenTabButton::_setPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabButton, "UU" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	if( control ) {
		self->GetInternalControl()->SetPage( control->GetInternalControl() );
		control->PushLuaUserdata( state );
		return 1;
	}
}

int MOAIGwenTabButton::_getPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabButton, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetPage() );
	return 1;
}

int MOAIGwenTabButton::_getTabControl ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabButton, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetTabControl() );
	return 1;
}

int MOAIGwenTabButton::_isActive ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabButton, "U" )
	state.Push( self->GetInternalControl()->IsActive() );
	return 1;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenTabButton::CreateGwenControl() {
	return new Gwen::Controls::TabButton( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenTabButton::MOAIGwenTabButton () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenButton )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenTabButton::~MOAIGwenTabButton () {
}


//----------------------------------------------------------------//
void MOAIGwenTabButton::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenTabButton::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setPage",           _setPage       },
		{ "getPage",           _getPage       },
		{ "getTabControl",     _getTabControl },
		{ "isActive",          _isActive      },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
