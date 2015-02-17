#include "moai-gwen/MOAIGwenTabControl.h"
#include "moai-gwen/MOAIGwenTabButton.h"

int MOAIGwenTabControl::_addPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 3, 0 );
	Gwen::Controls::Base* content = NULL;
	if( control ) content = control->GetInternalControl();
	Gwen::Controls::TabButton* tab = self->GetInternalControl()->AddPage( name, content );
	PushGwenControlOrNil( state, tab );
	return 1;
}

int MOAIGwenTabControl::_addTab ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "UU" )
	MOAIGwenTabButton* tab = state.GetLuaObject< MOAIGwenTabButton >( 2, 0 );
	if( tab ) {
		self->GetInternalControl()->AddPage( tab->GetInternalControl() );
		tab->PushLuaUserdata( state );
		return 1;
	}
	return 0;
}

int MOAIGwenTabControl::_removeTab ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "UU" )
	MOAIGwenTabButton* tab = state.GetLuaObject< MOAIGwenTabButton >( 2, 0 );
	if( tab )
		self->GetInternalControl()->RemovePage( tab->GetInternalControl() );
	return 0;
}

int MOAIGwenTabControl::_getTabCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "U" )
	state.Push( self->GetInternalControl()->TabCount() );
	return 1;
}

int MOAIGwenTabControl::_getTab ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	PushGwenControlOrNil( state, self->GetInternalControl()->GetTab( id ) );
	return 1;
}

int MOAIGwenTabControl::_getCurrentTab ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetCurrentButton() );
	return 1;
}

int MOAIGwenTabControl::_getCurrentPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "U" )
	Gwen::Controls::TabButton* tab = self->GetInternalControl()->GetCurrentButton();
	if( tab ) {
		PushGwenControlOrNil( state, tab->GetPage() );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenTabControl::_setTabBarPosition ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "UN" )
	u32 pos = state.GetValue < u32 >( 2, 0 );
	self->GetInternalControl()->SetTabStripPosition( pos );
	return 0;
}

int MOAIGwenTabControl::_setAllowReorder ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTabControl, "UB" )
	bool allowed    = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetAllowReorder( allowed );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenTabControl::CreateGwenControl() {
	return new Gwen::Controls::TabControl( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenTabControl::MOAIGwenTabControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenTabControl::~MOAIGwenTabControl () {
}


//----------------------------------------------------------------//
void MOAIGwenTabControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );

	state.SetField ( -1, "EVENT_TAB_CLOSE",    ( u32 )EVENT_TAB_CLOSE );
	state.SetField ( -1, "EVENT_TAB_ADD",      ( u32 )EVENT_TAB_ADD   );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenTabControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "addPage",           _addPage           },
		{ "addTab",            _addTab            },
		{ "removeTab",         _removeTab         },
		{ "getTabCount",       _getTabCount       },
		{ "getTab",            _getTab            },
		{ "getCurrentTab",     _getCurrentTab     },
		{ "getCurrentPage",    _getCurrentPage    },
		{ "setTabBarPosition", _setTabBarPosition },
		{ "setAllowReorder",   _setAllowReorder   },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
