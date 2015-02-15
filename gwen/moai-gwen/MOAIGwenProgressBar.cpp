#include "moai-gwen/MOAIGwenProgressBar.h"

int MOAIGwenProgressBar::_setHorizontal ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	self->GetInternalControl()->SetHorizontal();
	return 0;
}

int MOAIGwenProgressBar::_setVertical ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	self->GetInternalControl()->SetVertical();
	return 0;
}

int MOAIGwenProgressBar::_setValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "UN" )
	self->GetInternalControl()->SetValue( state.GetValue < float >( 2, 0.0f ) );
	return 0;
}

int MOAIGwenProgressBar::_getValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	state.Push( self->GetInternalControl()->GetValue() );
	return 1;
}

int MOAIGwenProgressBar::_setAutoLabel ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	self->GetInternalControl()->SetAutoLabel( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenProgressBar::_setCycleSpeed ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "UN" )
	self->GetInternalControl()->SetCycleSpeed( state.GetValue < float >( 2, 0.0f ) );
	return 0;
}

int MOAIGwenProgressBar::_getCycleSpeed ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	state.Push( self->GetInternalControl()->GetCycleSpeed() );
	return 1;
}

int MOAIGwenProgressBar::_updateCycle ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProgressBar, "U" )
	self->GetInternalControl()->CycleThink( state.GetValue < float >( 2, 0.016f ) );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenProgressBar::CreateGwenControl() {
	return new Gwen::Controls::ProgressBar( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenProgressBar::MOAIGwenProgressBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenLabel )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenProgressBar::~MOAIGwenProgressBar () {
}


//----------------------------------------------------------------//
void MOAIGwenProgressBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenProgressBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setHorizontal",  _setHorizontal  },
		{ "setVertical",    _setVertical    },
		{ "setValue",       _setValue       },
		{ "getValue",       _getValue       },
		{ "setAutoLabel",   _setAutoLabel   },
		{ "setCycleSpeed",  _setCycleSpeed  },
		{ "getCycleSpeed",  _getCycleSpeed  },
		{ "updateCycle",    _updateCycle    },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
