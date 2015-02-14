#include "moai-gwen/MOAIGwenColorPicker.h"

int MOAIGwenColorPicker::_setColor ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenColorPicker, "U" )
	Gwen::Color c = self->GetInternalControl()->GetColor();
	float r = state.GetValue< float >( 2, (float)c.r/255.0f );
	float g = state.GetValue< float >( 3, (float)c.g/255.0f );
	float b = state.GetValue< float >( 4, (float)c.b/255.0f );
	float a = state.GetValue< float >( 5, (float)c.a/255.0f );
	self->GetInternalControl()->SetColor( Gwen::Color( r*255, g*255, b*255, a*255 ) );
	return 0;
}

int MOAIGwenColorPicker::_getColor ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenColorPicker, "U" )
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
Gwen::Controls::Base* MOAIGwenColorPicker::CreateGwenControl() {
	return new Gwen::Controls::ColorPicker( MOAIGwenMgr::Get().GetDefaultCanvas() );
}

//----------------------------------------------------------------//
MOAIGwenColorPicker::MOAIGwenColorPicker () {
	this->mRootSystem = NULL;
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenColorPicker::~MOAIGwenColorPicker () {
}

//----------------------------------------------------------------//
void MOAIGwenColorPicker::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",      ( u32 )EVENT_CHANGE  );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenColorPicker::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	luaL_Reg regTable [] = {
		{ "getColor",  _getColor  },
		{ "setColor",  _setColor  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
