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

int MOAIGwenControl::_getParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Controls::Base* parent = self->GetInternalControl()->GetParent();
	if( parent ){
		MOAIGwenControl* control = _GwenToMoai( parent );
		control->PushLuaUserdata( state );
		return 0;
	} else {
		lua_pushnil( state );
	}
	return 1;
}


int MOAIGwenControl::_getChildren( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )

	lua_newtable( L );

	unsigned int count = 1;
	Gwen::Controls::Base::List & children = self->GetInternalControl()->GetChildren();
	for ( Gwen::Controls::Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
	{
		Gwen::Controls::Base* child = *iter ;
		lua_pushnumber ( state, count );
		PushGwenControl( state, child );
		lua_settable( L, -3 );
		++count;
	}
	return 1;
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
int MOAIGwenControl::_moveTo ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	self->GetInternalControl()->MoveTo( x, y );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_moveBy ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	self->GetInternalControl()->MoveBy( x, y );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getTypeName ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	lua_pushstring( state, self->GetInternalControl()->GetTypeName() );	
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_getChildrenCount ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->NumChildren() );	
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_sendToBack ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->SendToBack();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_bringToFront ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->BringToFront();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_bringNextToControl ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UU" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	bool behind = state.GetValue< bool >( 3, false );
	if( control )
		self->GetInternalControl()->BringNextToControl( control->GetInternalControl(), behind );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_fitChildren ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->SizeToChildren() );	
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_getChildrenSize ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Point size = self->GetInternalControl()->ChildrenSize();
	state.Push( size.x );
	state.Push( size.y );
	return 2;
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

Gwen::Controls::Base* MOAIGwenControl::CreateGwenControl() {
	return NULL;
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaClass ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		{ "new",             MOAILogMessages::_alertNewIsUnsupported },
		{ NULL, NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	luaL_Reg regTable [] = {
		{ "setSkin",              _setSkin            },
		{ "setParent",            _setParent          },
		{ "addChild",             _addChild           },
		{ "getChildrenCount",     _getChildrenCount   },
		{ "getChildren",          _getChildren        },

		{ "sendToBack",           _sendToBack         },
		{ "bringToFront",         _bringToFront       },
		{ "bringNextToControl",   _bringNextToControl },

		{ "getChildrenSize",      _getChildrenSize    },
		{ "fitChildren",          _fitChildren        },

		//ATTR
		{ "getSize",              _getSize            },
		{ "setSize",              _setSize            },

		{ "getPos",               _getPos             },
		{ "setPos",               _setPos             },

		{ "moveTo",               _moveTo             },
		{ "moveBy",               _moveBy             },
		{ "getTypeName",          _getTypeName        },

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
