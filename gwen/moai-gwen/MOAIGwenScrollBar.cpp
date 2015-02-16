#include "moai-gwen/MOAIGwenScrollBar.h"

int MOAIGwenBaseScrollBar::_setScrollSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "UN" )
	self->GetInternalControl()->SetContentSize( state.GetValue < float >( 2, 10.0f ));
	return 0;
}

int MOAIGwenBaseScrollBar::_setPageSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "UN" )
	self->GetInternalControl()->SetViewableContentSize( state.GetValue < float >( 2, 10.0f ));
	return 0;
}

int MOAIGwenBaseScrollBar::_setValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "UN" )
	float value = state.GetValue < float >( 2, 0.0f );
	bool forceUpdate = state.GetValue < bool >( 3, true );
	self->GetInternalControl()->SetScrolledAmount( value, forceUpdate );
	return 0;
}

int MOAIGwenBaseScrollBar::_getValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "U" )
	state.Push( self->GetInternalControl()->GetScrolledAmount() );
	return 1;
}

int MOAIGwenBaseScrollBar::_setStepSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "UN" )
	self->GetInternalControl()->SetNudgeAmount( state.GetValue < float >( 2, 0.0f ));
	return 0;
}

int MOAIGwenBaseScrollBar::_getStepSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseScrollBar, "U" )
	state.Push( self->GetInternalControl()->GetNudgeAmount() );
	return 1;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenBaseScrollBar::CreateGwenControl() {
	//TODO:abstract control...
	return NULL;
}

//----------------------------------------------------------------//
MOAIGwenBaseScrollBar::MOAIGwenBaseScrollBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenBaseScrollBar::~MOAIGwenBaseScrollBar () {
}


//----------------------------------------------------------------//
void MOAIGwenBaseScrollBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_SCROLL",   ( u32 )EVENT_SCROLL  );
	luaL_Reg regTable [] = {
		{ "new", MOAILogMessages::_alertNewIsUnsupported },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenBaseScrollBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setScrollSize",    _setScrollSize  },
		{ "setPageSize",      _setPageSize    },
		{ "setStepSize",      _setStepSize    },
		{ "getStepSize",      _getStepSize    },
		{ "setValue",         _setValue       },
		{ "getValue",         _getValue       },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}


//----------------------------------------------------------------//
//VERTICAL
//----------------------------------------------------------------//
int MOAIGwenVerticalScrollBar::_scrollToTop ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenVerticalScrollBar, "U" )
	self->GetInternalControl()->ScrollToTop();
	return 0;
}

int MOAIGwenVerticalScrollBar::_scrollToBottom ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenVerticalScrollBar, "U" )
	self->GetInternalControl()->ScrollToBottom();
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenVerticalScrollBar::CreateGwenControl() {
	return new Gwen::Controls::VerticalScrollBar( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenVerticalScrollBar::MOAIGwenVerticalScrollBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenBaseScrollBar )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenVerticalScrollBar::~MOAIGwenVerticalScrollBar () {
}

//----------------------------------------------------------------//
void MOAIGwenVerticalScrollBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenBaseScrollBar::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenVerticalScrollBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenBaseScrollBar::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "scrollToTop",      _scrollToTop     },
		{ "scrollToBottom",   _scrollToBottom  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}



//----------------------------------------------------------------//
//Horizontal
//----------------------------------------------------------------//
int MOAIGwenHorizontalScrollBar::_scrollToLeft ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenHorizontalScrollBar, "U" )
	self->GetInternalControl()->ScrollToLeft();
	return 0;
}

int MOAIGwenHorizontalScrollBar::_scrollToRight ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenHorizontalScrollBar, "U" )
	self->GetInternalControl()->ScrollToRight();
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenHorizontalScrollBar::CreateGwenControl() {
	return new Gwen::Controls::HorizontalScrollBar( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenHorizontalScrollBar::MOAIGwenHorizontalScrollBar () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenBaseScrollBar )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenHorizontalScrollBar::~MOAIGwenHorizontalScrollBar () {
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalScrollBar::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenBaseScrollBar::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalScrollBar::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenBaseScrollBar::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "scrollToLeft",     _scrollToLeft   },
		{ "scrollToRight",    _scrollToRight  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}

