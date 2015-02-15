#include "moai-gwen/MOAIGwenMenuItem.h"


int MOAIGwenMenuItem::_setCheckable ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenMenuItem, "U" )
	self->GetInternalControl()->SetCheckable( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenMenuItem::_toggle ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenMenuItem, "U" )
	self->GetInternalControl()->Toggle();
	return 0;
}

int MOAIGwenMenuItem::_openMenu ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenMenuItem, "U" )
	self->GetInternalControl()->OpenMenu();
	return 0;
}


int MOAIGwenMenuItem::_setChecked ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenMenuItem, "U" )
	self->GetInternalControl()->SetChecked( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenMenuItem::_isChecked ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenMenuItem, "U" )
	state.Push( self->GetInternalControl()->GetChecked() );
	return 1;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenMenuItem::CreateGwenControl() {
	return new Gwen::Controls::MenuItem( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenMenuItem::MOAIGwenMenuItem () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenButton )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenMenuItem::~MOAIGwenMenuItem () {
}


//----------------------------------------------------------------//
void MOAIGwenMenuItem::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_SELECT",     ( u32 )EVENT_CHANGE    );
	state.SetField ( -1, "EVENT_CHANGE",     ( u32 )EVENT_CHANGE    );
	state.SetField ( -1, "EVENT_CHECK",      ( u32 )EVENT_CHECK     );
	state.SetField ( -1, "EVENT_UNCHECK",    ( u32 )EVENT_UNCHECK   );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenMenuItem::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "openMenu",       _openMenu  },
		{ "setCheckable",   _setCheckable  },
		{ "setChecked",     _setChecked  },
		{ "toggle",         _toggle      },
		{ "isChecked",      _isChecked   },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
