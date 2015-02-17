#include "moai-gwen/MOAIGwenPropertyTree.h"


int MOAIGwenPropertyTree::_addCategory ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyTree, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::Properties* p = self->GetInternalControl()->Add( name );
	PushGwenControlOrNil( state,  p );
	return 1;
}

int MOAIGwenPropertyTree::_findCategory ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyTree, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::Properties* p = self->GetInternalControl()->Find( name );
	PushGwenControlOrNil( state,  p );
	return 1;
}

Gwen::Controls::Base* MOAIGwenPropertyTree::CreateGwenControl() {
	return new Gwen::Controls::PropertyTree( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenPropertyTree::MOAIGwenPropertyTree () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenPropertyTree::~MOAIGwenPropertyTree () {
}


//----------------------------------------------------------------//
void MOAIGwenPropertyTree::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenPropertyTree::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "addCategory",      _addCategory  },
		{ "findCategory",     _findCategory },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
