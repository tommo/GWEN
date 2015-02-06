#include "moai-gwen/MOAIGwenControl.h"
#include "moai-gwen/MOAIGwenSkin.h"

//----------------------------------------------------------------//
// Glue
//----------------------------------------------------------------//
int MOAIGwenControl::_setParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	self->SetParent( control );
	return 0;
}

int MOAIGwenControl::_setSkin ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	//TODO
	MOAIGwenSkin* skin = state.GetLuaObject< MOAIGwenSkin >( 2, 0 );
	self->mSkin.Set( *self, skin );
	if( skin ) {
		self->GetInternalControl()->SetSkin( skin->GetGwenSkin() );
	} else {
		self->GetInternalControl()->SetSkin( NULL );
	}
	return 0;
}

int MOAIGwenControl::_addChild ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UU" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	if( control )	control->SetParent( self );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_setSize ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float width  = state.GetValue < float >( 2, 0.0f );
	float height = state.GetValue < float >( 3, 0.0f );
	self->GetInternalControl()->SetSize( width, height );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getSize ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	float width  = self->GetInternalControl()->Width();
	float height = self->GetInternalControl()->Height();
	state.Push( width );
	state.Push( height );
	return 2;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_setPos ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	self->GetInternalControl()->SetPos( x, y );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getPos ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	float x = self->GetInternalControl()->X();
	float y = self->GetInternalControl()->Y();
	state.Push( x );
	state.Push( y );
	return 2;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getTypeName ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	lua_pushstring( state, self->GetInternalControl()->GetTypeName() );	
	return 1;
}

//----------------------------------------------------------------//
MOAIGwenControl::MOAIGwenControl () {
	RTTI_SINGLE ( MOAILuaObject )
	this->mControlRef.owner = this;
	// this->mGwenControl = this->CreateGwenControl();
	// assert( this->mGwenControl );
	// // this->mGwenControl->UserData.Set( "_MOAI_OBJECT_", this );
	// this->mGwenControl->MoaiObject = this;
}

//----------------------------------------------------------------//
MOAIGwenControl::~MOAIGwenControl () {
	this->mSkin.Set( *this, 0 );
	// if( this->mGwenControl ) {
	// 	this->ReleaseInternalControl( this->mGwenControl );
	// }
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaClass ( MOAILuaState& state ) {
	UNUSED( state );
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		{ "setSkin",   _setSkin   },
		{ "setParent", _setParent },
		{ "addChild",  _addChild  },

		//ATTR
		{ "getSize",   _getSize   },
		{ "setSize",   _setSize   },

		{ "getPos",   _getPos     },
		{ "setPos",   _setPos     },

		{ "getTypeName",   _getTypeName  },

		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenControl::SetSkin ( MOAIGwenSkin* skin ) {
	this->mSkin.Set( *this, skin );
	this->GetInternalControl()->SetSkin( skin->mGwenSkin );
}

void MOAIGwenControl::SetParent ( MOAIGwenControl* parent ) {
	this->GetInternalControl()->SetParent( parent->GetInternalControl() );
	//TODO:ref holding
}
