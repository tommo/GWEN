#include "moai-gwen/MOAIGwenButton.h"

int MOAIGwenButton::_isPressed ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "U" )
	state.Push( self->GetInternalControl()->IsDepressed() );
	return 1;
}

int MOAIGwenButton::_setIsToggle ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "UB" )
	bool toggle    = state.GetValue < bool >( 2, false );
	self->GetInternalControl()->SetIsToggle( toggle );
	return 0;
}

int MOAIGwenButton::_isToggle ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "U" )
	state.Push( self->GetInternalControl()->IsToggle() );
	return 1;
}

int MOAIGwenButton::_getToggleState ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "U" )
	state.Push( self->GetInternalControl()->GetToggleState() );
	return 1;
}

int MOAIGwenButton::_setToggleState ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "UB" )
	bool toggled    = state.GetValue < bool >( 2, false );
	self->GetInternalControl()->SetToggleState( toggled );
	return 0;
}

int MOAIGwenButton::_setImage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "US" )
	cc8* imageName = state.GetValue < cc8* >( 2, "" );
	bool center    = state.GetValue < bool >( 3, false );
	self->GetInternalControl()->SetImage( imageName, center );
	return 0;
}

int MOAIGwenButton::_setImageAlpha ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "UN" )
	self->GetInternalControl()->SetImageAlpha( state.GetValue < float >( 2, 1.0f ) );
	return 0;
}

int MOAIGwenButton::_fitContent ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenButton, "U" )
	self->GetInternalControl()->SizeToContents();
	return 0;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenButton::CreateGwenControl() {
	return new Gwen::Controls::Button( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenButton::MOAIGwenButton () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenLabel )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenButton::~MOAIGwenButton () {
}


//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CLICK",   ( u32 )EVENT_CLICK  );
	state.SetField ( -1, "EVENT_UP",      ( u32 )EVENT_UP     );
	state.SetField ( -1, "EVENT_DOWN",    ( u32 )EVENT_DOWN   );
	state.SetField ( -1, "EVENT_TOGGLE",  ( u32 )EVENT_TOGGLE );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenButton::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "isPressed",       _isPressed      },
		{ "setIsToggle",     _setIsToggle    },
		{ "isToggle",        _isToggle       },
		{ "getToggleState",  _getToggleState },
		{ "setToggleState",  _setToggleState },
		{ "setImage",        _setImage       },
		{ "setImageAlpha",   _setImageAlpha  },
		{ "fitContent",      _fitContent     },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
