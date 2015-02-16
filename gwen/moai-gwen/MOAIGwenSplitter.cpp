#include "moai-gwen/MOAIGwenSplitter.h"

//----------------------------------------------------------------//
int MOAIGwenVerticalSplitter::_setPanels ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenVerticalSplitter, "U" )	
	Gwen::Controls::Base* raw1 = 0;
	Gwen::Controls::Base* raw2 = 0;
	MOAIGwenControl* control1 = state.GetLuaObject< MOAIGwenControl >( 2, 0 );
	MOAIGwenControl* control2 = state.GetLuaObject< MOAIGwenControl >( 3, 0 );
	if( control1 ) raw1 = control1->GetInternalControl();
	if( control2 ) raw2 = control2->GetInternalControl();
	self->GetInternalControl()->SetPanels( raw1, raw2 );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenVerticalSplitter::_setScaling ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenVerticalSplitter, "UN" )
	float scale = state.GetValue< float >( 2, 1.0f );
	self->GetInternalControl()->SetScaling( false, scale * 100 );
	return 0;
}

int MOAIGwenVerticalSplitter::_getSplitterPos ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenVerticalSplitter, "U" )
	state.Push( (float) self->GetInternalControl()->SplitterPos() );
	return 1;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenVerticalSplitter::CreateGwenControl() {
	return new Gwen::Controls::SplitterVertical( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenVerticalSplitter::MOAIGwenVerticalSplitter () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenVerticalSplitter::~MOAIGwenVerticalSplitter () {
}


//----------------------------------------------------------------//
void MOAIGwenVerticalSplitter::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenVerticalSplitter::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setPanels",      _setPanels       },
		{ "setScaling",     _setScaling      },
		{ "getSplitterPos", _getSplitterPos  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}



//----------------------------------------------------------------//
//Horizontal
//----------------------------------------------------------------//
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenHorizontalSplitter::CreateGwenControl() {
	return new Gwen::Controls::SplitterHorizontal( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenHorizontalSplitter::MOAIGwenHorizontalSplitter () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenVerticalSplitter )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenHorizontalSplitter::~MOAIGwenHorizontalSplitter () {
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalSplitter::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenVerticalSplitter::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalSplitter::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenVerticalSplitter::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
