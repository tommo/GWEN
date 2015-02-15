#include "moai-gwen/MOAIGwenRadioButtonGroup.h"

int MOAIGwenRadioButtonGroup::_addOption ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenRadioButtonGroup, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	cc8* name = state.GetValue < cc8* >( 2, text );
	self->GetInternalControl()->AddOption( text, name );
	return 0;
}

int MOAIGwenRadioButtonGroup::_getSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenRadioButtonGroup, "U" )
	if( self->GetInternalControl()->GetSelected() ) {
		lua_pushstring( state, self->GetInternalControl()->GetSelectedName().c_str() );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenRadioButtonGroup::CreateGwenControl() {
	return new Gwen::Controls::RadioButtonController( NULL );
}

//----------------------------------------------------------------//
MOAIGwenRadioButtonGroup::MOAIGwenRadioButtonGroup () {
	this->mRootSystem = NULL;
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenRadioButtonGroup::~MOAIGwenRadioButtonGroup () {
}

//----------------------------------------------------------------//
void MOAIGwenRadioButtonGroup::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",   ( u32 )EVENT_CHANGE  );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenRadioButtonGroup::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "addOption",        _addOption     },
		{ "getSelection",     _getSelection  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
