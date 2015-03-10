#include "moai-gwen/MOAIGwenProperty.h"


int MOAIGwenBaseProperty::_getValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseProperty, "U" )
	Gwen::TextObject t = self->GetInternalControl()->GetPropertyValue();
	lua_pushstring( state, t.c_str() );
	return 1;
}

int MOAIGwenBaseProperty::_setValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseProperty, "US" )
	cc8* value = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetPropertyValue( value );
	return 0;
}

int MOAIGwenBaseProperty::_isEditing ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseProperty, "U" )
	state.Push( self->GetInternalControl()->IsEditing() );
	return 1;
}

Gwen::Controls::Base* MOAIGwenBaseProperty::CreateGwenControl() {
	// return new Gwen::Controls::Property::Base( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
	return NULL;
}

//----------------------------------------------------------------//
MOAIGwenBaseProperty::MOAIGwenBaseProperty () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenBaseProperty::~MOAIGwenBaseProperty () {
}


//----------------------------------------------------------------//
void MOAIGwenBaseProperty::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",   ( u32 )EVENT_CHANGE  );

	luaL_Reg regTable [] = {
		{ "new", MOAILogMessages::_alertNewIsUnsupported },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenBaseProperty::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getValue",     _getValue   },
		{ "setValue",     _setValue   },
		{ "isEditing",    _isEditing  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
