#include "moai-gwen/MOAIGwenLayoutTile.h"

//----------------------------------------------------------------//
int MOAIGwenLayoutTile::_setTileSize ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTile, "UNN" )
	float w = state.GetValue < float >( 2, 100.0f );
	float h = state.GetValue < float >( 3, 100.0f );
	self->GetInternalControl()->SetTileSize( w, h );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenLayoutTile::CreateGwenControl() {
	return new Gwen::Controls::Layout::Tile( NULL );
}

//----------------------------------------------------------------//
MOAIGwenLayoutTile::MOAIGwenLayoutTile () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenLayoutTile::~MOAIGwenLayoutTile () {
}


//----------------------------------------------------------------//
void MOAIGwenLayoutTile::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenLayoutTile::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setTileSize",      _setTileSize  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
