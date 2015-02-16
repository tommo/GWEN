#include "moai-gwen/MOAIGwenTreeControl.h"

//----------------------------------------------------------------//
int MOAIGwenTreeControl::_clear ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTreeControl, "U" )
	self->GetInternalControl()->Clear();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenTreeControl::_setAllowMultiSelect ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTreeControl, "U" )
	self->GetInternalControl()->AllowMultiSelect( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenTreeControl::_getScrollControl ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTreeControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->Scroller() );
	return 1;
}


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenTreeControl::CreateGwenControl() {
	return new Gwen::Controls::TreeControl( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenTreeControl::MOAIGwenTreeControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenTreeNode )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenTreeControl::~MOAIGwenTreeControl () {
}


//----------------------------------------------------------------//
void MOAIGwenTreeControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenTreeNode::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenTreeControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenTreeNode::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "clear",               _clear               },
		{ "getScrollControl",    _getScrollControl    },
		{ "setAllowMultiSelect", _setAllowMultiSelect },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
