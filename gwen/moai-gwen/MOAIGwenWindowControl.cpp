#include "moai-gwen/MOAIGwenWindowControl.h"


int MOAIGwenWindowControl::_setTitle ( lua_State* L ) {
	MOAI_LUA_SETUP( MOAIGwenWindowControl, "US" )
	cc8* title = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetTitle( title );
	return 0;
}

int MOAIGwenWindowControl::_setClosable ( lua_State* L ) {
	MOAI_LUA_SETUP( MOAIGwenWindowControl, "UB" )
	bool closable = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetClosable( closable );
	return 0;
}

int MOAIGwenWindowControl::_makeModal ( lua_State* L ) {
	MOAI_LUA_SETUP( MOAIGwenWindowControl, "U" )
	bool shouldDrawBackground = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->MakeModal( shouldDrawBackground );
	return 0;
}

int MOAIGwenWindowControl::_destroyModal ( lua_State* L ) {
	MOAI_LUA_SETUP( MOAIGwenWindowControl, "U" )
	self->GetInternalControl()->DestroyModal();
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenWindowControl::CreateGwenControl() {
	return new Gwen::Controls::WindowControl( MOAIGwenMgr::Get().GetDefaultCanvas() );
}

//----------------------------------------------------------------//
MOAIGwenWindowControl::MOAIGwenWindowControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenWindowControl::~MOAIGwenWindowControl () {
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_CLOSE",					( u32 )EVENT_CLOSE );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenWindowControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "setTitle",          _setTitle     },
		{ "setClosable",       _setClosable  },
		{ "makeModal",         _makeModal    },
		{ "destroyModal",      _destroyModal },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
