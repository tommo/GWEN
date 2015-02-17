#include "moai-gwen/MOAIGwenProperties.h"
#include "moai-gwen/MOAIGwenProperty.h"

//================================================================//
// MOAIGwenPropertyRow
//================================================================//

int MOAIGwenPropertyRow::_getProperty ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyRow, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetProperty() );
	return 1;
}

int MOAIGwenPropertyRow::_setProperty ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyRow, "UU" )
	MOAIGwenBaseProperty* control = state.GetLuaObject < MOAIGwenBaseProperty >( 2, 0 );
	if( control ) {
		self->GetInternalControl()->SetProperty( control->GetInternalControl() );
	}
	return 0;
}

int MOAIGwenPropertyRow::_getLabel ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyRow, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetLabel() );
	return 1;
}

int MOAIGwenPropertyRow::_isEditing ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPropertyRow, "U" )
	state.Push( self->GetInternalControl()->IsEditing() );
	return 1;
}

Gwen::Controls::Base* MOAIGwenPropertyRow::CreateGwenControl() {
	return new Gwen::Controls::PropertyRow( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenPropertyRow::MOAIGwenPropertyRow () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenPropertyRow::~MOAIGwenPropertyRow () {
}


//----------------------------------------------------------------//
void MOAIGwenPropertyRow::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",   ( u32 )EVENT_CHANGE  );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenPropertyRow::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getLabel",     _getLabel    },
		{ "getProperty",  _getProperty },
		{ "setProperty",  _setProperty },
		{ "isEditing",    _isEditing   },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}



//================================================================//
// MOAIGwenProperties
//================================================================//

int MOAIGwenProperties::_add ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProperties, "USU" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	MOAIGwenBaseProperty* prop = state.GetLuaObject < MOAIGwenBaseProperty >( 3, 0 );
	cc8* value = state.GetValue < cc8* >( 4, "" );
	if( prop ) {
		Gwen::Controls::PropertyRow* row = 
			self->GetInternalControl()->Add( name, prop->GetInternalControl(), value );
		PushGwenControlOrNil( state, row );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenProperties::_find ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProperties, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::PropertyRow* row = self->GetInternalControl()->Find( name );
	PushGwenControlOrNil( state, row );
	return 1;
}


int MOAIGwenProperties::_clear ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenProperties, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->Clear();
	return 0;
}

Gwen::Controls::Base* MOAIGwenProperties::CreateGwenControl() {
	return new Gwen::Controls::Properties( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenProperties::MOAIGwenProperties () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenProperties::~MOAIGwenProperties () {
}


//----------------------------------------------------------------//
void MOAIGwenProperties::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenProperties::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "add",     _add   },
		{ "find",    _find  },
		{ "clear",   _clear },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}

