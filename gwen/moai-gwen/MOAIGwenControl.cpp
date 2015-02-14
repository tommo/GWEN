#include "moai-gwen/MOAIGwenControl.h"
#include "moai-gwen/MOAIGwenSkin.h"
#include "moai-gwen/MOAIGwenCanvas.h"

//----------------------------------------------------------------//
// Glue
//----------------------------------------------------------------//
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

//----------------------------------------------------------------//
int MOAIGwenControl::_setParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	self->SetParent( control );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_addChild ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UU" )
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	if( control )	{
		control->SetParent( self );
		control->PushLuaUserdata( state );
		return 1;
	}
	return 0;
}

int MOAIGwenControl::_getParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Controls::Base* parent = self->GetInternalControl()->GetParent();
	if( parent ){
		MOAIGwenControl* control = _GwenToMoai( parent );
		control->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
	}
	return 1;
}

int MOAIGwenControl::_getChildren( lua_State* L ) {
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

int MOAIGwenControl::_findChildByName( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	bool recursive = state.GetValue < bool >( 3, false );
	Gwen::Controls::Base *found = self->GetInternalControl()->FindChildByName( name, recursive );
	if( found ) {
		PushGwenControl( state, found );
	} else	{
		lua_pushnil( state );
	}
	return 1;
}


int MOAIGwenControl::_removeAllChildren ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->RemoveAllChildren();
	return 0;
}


int MOAIGwenControl::_getCanvas ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	MOAIGwenCanvas* canvas = self->GetCanvas();
	if( canvas ){
		canvas->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenControl::_getSystem ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	MOAIGwenSystem* system = self->GetSystem();
	if( system ){
		system->PushLuaUserdata( state );
		return 1;
	} else {
		return 1;
		lua_pushnil( state );
	}
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getName( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	lua_pushstring( state, self->GetInternalControl()->GetName().c_str() );	
	return 1;
}

int MOAIGwenControl::_setName( lua_State* L )
{
	MOAI_LUA_SETUP ( MOAIGwenControl, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetName( name );	
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
	bool fitWidth  = state.GetValue < bool >( 2, true );
	bool fitHeight = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SizeToChildren( fitWidth, fitHeight );
	return 0;
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
int MOAIGwenControl::_restrictToParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	bool restricted = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->RestrictToParent( restricted );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_shouldRestrictToParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->ShouldRestrictToParent() );	
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_setPadding ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UN" )
	u32 l = state.GetValue < u32 >( 2, 0 );
	u32 t = state.GetValue < u32 >( 3, l );
	u32 r = state.GetValue < u32 >( 4, l );
	u32 b = state.GetValue < u32 >( 5, l );
	self->GetInternalControl()->SetPadding( Gwen::Padding( l, t, r, b ) ); 
	return 0;
}

int MOAIGwenControl::_setMargin ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UN" )
	u32 l = state.GetValue < u32 >( 2, 0 );
	u32 t = state.GetValue < u32 >( 3, l );
	u32 r = state.GetValue < u32 >( 4, l );
	u32 b = state.GetValue < u32 >( 5, l );
	self->GetInternalControl()->SetMargin( Gwen::Margin( l, t, r, b ) ); 
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
int MOAIGwenControl::_getBounds ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Rect bounds = self->GetInternalControl()->GetBounds();
	state.Push( bounds.x );
	state.Push( bounds.y );
	state.Push( bounds.w );
	state.Push( bounds.h );
	return 4;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getInnerBounds ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Rect bounds = self->GetInternalControl()->GetInnerBounds();
	state.Push( bounds.x );
	state.Push( bounds.y );
	state.Push( bounds.w );
	state.Push( bounds.h );
	return 4;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_getRenderBounds ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	Gwen::Rect bounds = self->GetInternalControl()->GetRenderBounds();
	state.Push( bounds.x );
	state.Push( bounds.y );
	state.Push( bounds.w );
	state.Push( bounds.h );
	return 4;
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
int MOAIGwenControl::_setPos ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	self->GetInternalControl()->SetPos( x, y );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_getControlAt ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UNN" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	bool onlyIfMouseEnabled = state.GetValue < bool >( 4, false );
	Gwen::Controls::Base* control =
		self->GetInternalControl()->GetControlAt( x, y, onlyIfMouseEnabled );
	if( control ) {
		PushGwenControl( state, control );
		return 1;
	} else {
		return 0;
	}
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
int MOAIGwenControl::_localToCanvas ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	Gwen::Point p0( x, y );
	Gwen::Point p = self->GetInternalControl()->LocalPosToCanvas( p0 );
	state.Push( p.x );
	state.Push( p.y );
	return 2;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_canvasToLocal ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	float x = state.GetValue < float >( 2, 0.0f );
	float y = state.GetValue < float >( 3, 0.0f );
	Gwen::Point p0( x, y );
	Gwen::Point p = self->GetInternalControl()->CanvasPosToLocal( p0 );
	state.Push( p.x );
	state.Push( p.y );
	return 2;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_isVisible ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->Visible() );
	return 1;
}

int MOAIGwenControl::_isLocalVisible ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( !self->GetInternalControl()->Hidden() );
	return 1;
}

int MOAIGwenControl::_setVisible ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	bool visible = state.GetValue < bool >( 2, true );
	if( visible ){
		self->GetInternalControl()->Show();
	} else {
		self->GetInternalControl()->Hide();
	}
	return 0;
}

int MOAIGwenControl::_show ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Show();
	return 0;
}

int MOAIGwenControl::_hide ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Hide();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_isDisabled ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->IsDisabled() );
	return 1;
}

int MOAIGwenControl::_setDisabled ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	bool disabled = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetDisabled( disabled );
	return 0;
}

int MOAIGwenControl::_enable ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->SetDisabled( false );
	return 0;
}

int MOAIGwenControl::_disable ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->SetDisabled( true );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_hasFocus ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->HasFocus() );
	return 1;
}

int MOAIGwenControl::_setFocus ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	bool focused = state.GetValue < bool >( 2, true );
	if( focused )
		self->GetInternalControl()->Focus();
	else
		self->GetInternalControl()->Blur();
	return 0;
}

int MOAIGwenControl::_focus ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Focus();
	return 0;
}

int MOAIGwenControl::_blur ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Blur();
	return 0;
}

int MOAIGwenControl::_touch ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Touch();
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenControl::_isOnTop ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->IsOnTop() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_isHovered ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->IsHovered() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_isTabable ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->IsTabable() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_setTabable ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UB" )
	bool tabable = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetTabable( tabable );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_getDock ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->GetDock() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_setDock ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "UN" )
	u32 dockId = state.GetValue < u32 >( 2, 0 );
	self->GetInternalControl()->Dock( dockId );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_isMenuComponent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	state.Push( self->GetInternalControl()->IsMenuComponent() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_closeMenus ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->CloseMenus();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_setToolTip ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "US" )
	cc8* tip = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetToolTip( tip );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_invalidate ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->Invalidate();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_invalidateChildren ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->InvalidateChildren();
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenControl::_invalidateParent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenControl, "U" )
	self->GetInternalControl()->InvalidateParent();
	return 0;
}


//----------------------------------------------------------------//
MOAIGwenControl::MOAIGwenControl () {
	RTTI_SINGLE ( MOAIInstanceEventSource )
	this->mControlRef.owner = this;
	// this->mGwenControl = this->CreateGwenControl();
	// assert( this->mGwenControl );
	// // this->mGwenControl->UserData.Set( "_MOAI_OBJECT_", this );
	// this->mGwenControl->MoaiObject = this;
}

//----------------------------------------------------------------//
MOAIGwenControl::~MOAIGwenControl () {
	this->mSkin.Set( *this, 0 );
	//TODO: delete internal control if it has no parent
}


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenControl::CreateGwenControl() {
	return NULL;
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIInstanceEventSource::RegisterLuaClass ( state );
	
	state.SetField ( -1, "EVENT_HOVER_ENTER",					( u32 )EVENT_HOVER_ENTER );
	state.SetField ( -1, "EVENT_HOVER_EXIT",					( u32 )EVENT_HOVER_EXIT );

	luaL_Reg regTable [] = {
		{ "new",             MOAILogMessages::_alertNewIsUnsupported },
		{ NULL, NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIInstanceEventSource::RegisterLuaFuncs ( state );

	luaL_Reg regTable [] = {
		{ "getName",              _getName            },
		{ "setName",              _setName            },
		{ "getTypeName",          _getTypeName        },

		{ "setSkin",              _setSkin            },
		{ "setParent",            _setParent          },
		{ "addChild",             _addChild           },
		{ "getChildrenCount",     _getChildrenCount   },
		{ "getChildren",          _getChildren        },
		{ "findChildByName",      _findChildByName    },
		{ "removeAllChildren",    _removeAllChildren  },
		{ "getCanvas",            _getCanvas          },
		{ "getSystem",            _getSystem          },


		{ "sendToBack",           _sendToBack         },
		{ "bringToFront",         _bringToFront       },
		{ "bringNextToControl",   _bringNextToControl },

		{ "getChildrenSize",      _getChildrenSize    },
		{ "fitChildren",          _fitChildren        },
		
		{ "setMargin",            _setMargin          },
		{ "setPadding",           _setPadding         },

		//ATTR
		{ "getSize",              _getSize            },
		{ "setSize",              _setSize            },

		{ "getBounds",            _getBounds          },
		{ "getInnerBounds",       _getInnerBounds     },
		{ "getRenderBounds",      _getRenderBounds    },

		{ "getPos",               _getPos             },
		{ "setPos",               _setPos             },
		{ "moveTo",               _moveTo             },
		{ "moveBy",               _moveBy             },
		{ "localToCanvas",        _localToCanvas      },
		{ "canvasToLocal",        _canvasToLocal      },

		{ "getControlAt",         _getControlAt       },

		{ "restrictToParent",       _restrictToParent },
		{ "shouldRestrictToParent", _shouldRestrictToParent },

		{ "isVisible",            _isVisible          },
		{ "isLocalVisible",       _isLocalVisible     },
		{ "setVisible",           _setVisible         },
		{ "hide",                 _hide               },
		{ "show",                 _show               },

		{ "isDisabled",           _isDisabled         },
		{ "setDisabled",          _setDisabled        },
		{ "disable",              _disable            },
		{ "enable",               _enable             },

		{ "hasFocus",             _hasFocus           },
		{ "setFocus",             _setFocus           },
		{ "focus",                _focus              },
		{ "blur",                 _blur               },
		{ "touch",                _touch              },

		{ "isTabable",            _isTabable          },
		{ "setTabable",           _setTabable         },

		{ "isHovered",            _isHovered          },
		{ "isOnTop",              _isOnTop            },

		{ "getDock",              _getDock            },
		{ "setDock",              _setDock            },
		

		{ "isMenuComponent",      _isMenuComponent    },
		{ "closeMenus",           _closeMenus         },

		{ "setToolTip",           _setToolTip         },
		{ "invalidate",           _invalidate         },
		{ "invalidateChildren",   _invalidateChildren },
		{ "invalidateParent",     _invalidateParent   },

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
}

MOAIGwenCanvas* MOAIGwenControl::GetCanvas() {
	Gwen::Controls::Base* canvas = this->GetInternalControl()->GetCanvas();
	if( canvas ){
		MOAIGwenCanvas* mcanvas = static_cast < MOAIGwenCanvas* >( _GwenToMoai( canvas ) );
		return mcanvas;
	}
	return NULL;
}

MOAIGwenSystem* MOAIGwenControl::GetSystem() {
	MOAIGwenCanvas* canvas = this->GetCanvas();
	if( !canvas ) return NULL;
	return canvas->mRootSystem;
}
