#include "moai-gwen/MOAIGwenSlider.h"

int MOAIGwenBaseSlider::_setSnapToNotch ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "U" )
	self->GetInternalControl()->SetClampToNotches( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenBaseSlider::_setNotchCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "UN" )
	u32 count = state.GetValue < u32 >( 2, 0 );
	self->GetInternalControl()->SetNotchCount( count );
	return 0;
}

int MOAIGwenBaseSlider::_getNotchCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "U" )
	state.Push( self->GetInternalControl()->GetNotchCount() );
	return 1;
}

int MOAIGwenBaseSlider::_setValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "UN" )
	float value = state.GetValue < float >( 2, 0.0f );
	bool forceUpdate = state.GetValue < bool >( 3, true );
	self->GetInternalControl()->SetFloatValue( value, forceUpdate );
	return 0;
}

int MOAIGwenBaseSlider::_getValue ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "U" )
	state.Push( self->GetInternalControl()->GetFloatValue() );
	return 1;
}

int MOAIGwenBaseSlider::_setRange ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "U" )
	float rmin = state.GetValue < float >( 2, -FLT_MAX );
	float rmax = state.GetValue < float >( 3,  FLT_MAX );
	self->GetInternalControl()->SetRange( rmin, rmax );
	return 0;
}

int MOAIGwenBaseSlider::_getRange ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenBaseSlider, "U" )
	state.Push( self->GetInternalControl()->GetMin() );
	state.Push( self->GetInternalControl()->GetMax() );
	return 2;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenBaseSlider::CreateGwenControl() {
	//TODO:abstract control...
	return NULL;
}

//----------------------------------------------------------------//
MOAIGwenBaseSlider::MOAIGwenBaseSlider () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenBaseSlider::~MOAIGwenBaseSlider () {
}


//----------------------------------------------------------------//
void MOAIGwenBaseSlider::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_CHANGE",   ( u32 )EVENT_CHANGE  );
	luaL_Reg regTable [] = {
		{ "new", MOAILogMessages::_alertNewIsUnsupported },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenBaseSlider::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getRange",         _getRange       },
		{ "setRange",         _setRange       },
		{ "setNotchCount",    _setNotchCount  },
		{ "getNotchCount",    _getNotchCount  },
		{ "setSnapToNotch",   _setSnapToNotch },
		{ "getValue",         _getValue       },
		{ "setValue",         _setValue       },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}


//----------------------------------------------------------------//
//VERTICAL
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenVerticalSlider::CreateGwenControl() {
	return new Gwen::Controls::VerticalSlider( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenVerticalSlider::MOAIGwenVerticalSlider () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenBaseSlider )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenVerticalSlider::~MOAIGwenVerticalSlider () {
}

//----------------------------------------------------------------//
void MOAIGwenVerticalSlider::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenBaseSlider::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenVerticalSlider::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenBaseSlider::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}



//----------------------------------------------------------------//
//Horizontal
//----------------------------------------------------------------//

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenHorizontalSlider::CreateGwenControl() {
	return new Gwen::Controls::HorizontalSlider( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenHorizontalSlider::MOAIGwenHorizontalSlider () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenBaseSlider )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenHorizontalSlider::~MOAIGwenHorizontalSlider () {
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalSlider::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenBaseSlider::RegisterLuaClass( state );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenHorizontalSlider::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenBaseSlider::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}

