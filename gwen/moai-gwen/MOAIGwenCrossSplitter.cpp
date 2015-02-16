#include "moai-gwen/MOAIGwenCrossSplitter.h"

int MOAIGwenCrossSplitter::_setPanel ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "UNU" )
	int panelId = state.GetValue< int >( 2, 1 ) - 1;
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 3, 0 );
	if( panelId > 3 || panelId < 0 ) return 0;
	if( control ) {
		self->GetInternalControl()->SetPanel( panelId, control->GetInternalControl() );
	}
	return 0;
}

int MOAIGwenCrossSplitter::_getPanel ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "U" )
	int panelId = state.GetValue< int >( 2, 1 ) - 1;
	if( panelId > 3 || panelId < 0 ) return 0;
	Gwen::Controls::Base* raw = self->GetInternalControl()->GetPanel( panelId );
	MOAIGwenControl* control = _GwenToMoai( raw );
	if( control ) {
		control->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenCrossSplitter::_isZoomed ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "U" )
	state.Push( self->GetInternalControl()->IsZoomed() );
	return 1;
}

int MOAIGwenCrossSplitter::_centerSplitter ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "U" )
	self->GetInternalControl()->CenterPanels();
	return 0;
}

int MOAIGwenCrossSplitter::_zoom ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "U" )
	int panelId = state.GetValue < int >( 2, 0 ) - 1;
	if( panelId <= 0 ){
		self->GetInternalControl()->UnZoom();
	} else {
		self->GetInternalControl()->Zoom( panelId );
	}
	return 1;
}

int MOAIGwenCrossSplitter::_setSplitterSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCrossSplitter, "UN" )
	float size = state.GetValue < float >( 2, 10.0f );
	self->GetInternalControl()->SetSplitterSize( size );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenCrossSplitter::CreateGwenControl() {
	return new Gwen::Controls::CrossSplitter( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenCrossSplitter::MOAIGwenCrossSplitter () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenCrossSplitter::~MOAIGwenCrossSplitter () {
}


//----------------------------------------------------------------//
void MOAIGwenCrossSplitter::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_ZOOM_CHANGE",   ( u32 )EVENT_ZOOM_CHANGE  );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenCrossSplitter::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setPanel",          _setPanel        },
		{ "getPanel",          _getPanel        },
		{ "isZoomed",          _isZoomed        },
		{ "zoom",              _zoom            },
		{ "centerSplitter",    _centerSplitter  },
		{ "setSplitterSize",   _setSplitterSize },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
