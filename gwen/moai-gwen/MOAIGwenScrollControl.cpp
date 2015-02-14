#include "moai-gwen/MOAIGwenScrollControl.h"

int MOAIGwenScrollControl::_setScrollEnabled ( lua_State *L ) {
 	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
 	bool h = state.GetValue < bool >( 2, true );
 	bool v = state.GetValue < bool >( 3, true );
 	self->GetInternalControl()->SetScroll( h, v );
 	return 0;
 } 

int MOAIGwenScrollControl::_isScrollEnabled ( lua_State *L ) {
 	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
 	bool h = self->GetInternalControl()->CanScrollH();
 	bool v = self->GetInternalControl()->CanScrollV();
 	state.Push( h );
 	state.Push( v );
 	return 2;
}

int MOAIGwenScrollControl::_setAutoHideScrollBars ( lua_State *L ) {
 	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
 	bool h = state.GetValue < bool >( 2, true );
 	self->GetInternalControl()->SetAutoHideBars( h );
 	return 0;
 }

int MOAIGwenScrollControl::_setAlwaysShowScrollBars ( lua_State *L ) {
 	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
 	bool h = state.GetValue < bool >( 2, true );
 	bool v = state.GetValue < bool >( 3, true );
 	self->GetInternalControl()->SetHScrollRequired( h );
 	self->GetInternalControl()->SetVScrollRequired( v );
 	return 0;
}

int MOAIGwenScrollControl::_setInnerSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenScrollControl, "UNN" )
	float w = state.GetValue < float >( 2, 100.0f );
	float h = state.GetValue < float >( 3, 100.0f );
	self->GetInternalControl()->SetInnerSize( w, h );
	return 0;
}

int MOAIGwenScrollControl::_scrollToTop ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
	self->GetInternalControl()->ScrollToTop();
	return 0;
}

int MOAIGwenScrollControl::_scrollToBottom ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
	self->GetInternalControl()->ScrollToBottom();
	return 0;
}

int MOAIGwenScrollControl::_scrollToLeft ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
	self->GetInternalControl()->ScrollToLeft();
	return 0;
}

int MOAIGwenScrollControl::_scrollToRight ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenScrollControl, "U" )
	self->GetInternalControl()->ScrollToRight();
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenScrollControl::CreateGwenControl() {
	return new Gwen::Controls::ScrollControl( NULL );
}

//----------------------------------------------------------------//
MOAIGwenScrollControl::MOAIGwenScrollControl () {
	this->mRootSystem = NULL;
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenScrollControl::~MOAIGwenScrollControl () {
}

//----------------------------------------------------------------//
void MOAIGwenScrollControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenScrollControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "setScrollEnabled",       _setScrollEnabled        },
		{ "isScrollEnabled",        _isScrollEnabled         },
		{ "setAutoHideScrollBars",  _setAutoHideScrollBars   },
		{ "setAlwaysShowScrollBars",_setAlwaysShowScrollBars },
		{ "setInnerSize",           _setInnerSize            },
		{ "scrollToTop",            _scrollToTop             },
		{ "scrollToBottom",         _scrollToBottom          },
		{ "scrollToLeft",           _scrollToLeft            },
		{ "scrollToRight",          _scrollToRight           },        		
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
