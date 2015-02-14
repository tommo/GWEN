#include "moai-gwen/MOAIGwenRectangle.h"

//----------------------------------------------------------------//
int MOAIGwenRectangle::_setColor ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenRectangle, "U" )
	Gwen::Color c = self->GetInternalControl()->GetColor();
	float r = state.GetValue< float >( 2, (float)c.r/255.0f );
	float g = state.GetValue< float >( 3, (float)c.g/255.0f );
	float b = state.GetValue< float >( 4, (float)c.b/255.0f );
	float a = state.GetValue< float >( 5, (float)c.a/255.0f );
	self->GetInternalControl()->SetColor( Gwen::Color( r*255, g*255, b*255, a*255 ) );
	return 0;
}

int MOAIGwenRectangle::_getColor ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenRectangle, "U" )
	Gwen::Color c = self->GetInternalControl()->GetColor();
	float r = state.GetValue< float >( 2, (float)c.r/255.0f );
	float g = state.GetValue< float >( 3, (float)c.g/255.0f );
	float b = state.GetValue< float >( 4, (float)c.b/255.0f );
	float a = state.GetValue< float >( 5, (float)c.a/255.0f );
	state.Push( r );
	state.Push( g );
	state.Push( b );
	state.Push( a );
	return 4;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenRectangle::CreateGwenControl() {
	return new Gwen::Controls::Rectangle( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenRectangle::MOAIGwenRectangle () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenRectangle::~MOAIGwenRectangle () {
}


//----------------------------------------------------------------//
void MOAIGwenRectangle::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenRectangle::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getColor", _getColor  },
		{ "setColor", _setColor  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
