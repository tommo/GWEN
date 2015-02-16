#include "moai-gwen/MOAIGwenDragger.h"

//----------------------------------------------------------------//
int MOAIGwenDragger::_setAllowMove ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenDragger, "U" )
	self->GetInternalControl()->SetDoMove( state.GetValue < bool >( 2, true ) );
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenDragger::CreateGwenControl() {
	return new Gwen::ControlsInternal::Dragger( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenDragger::MOAIGwenDragger () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenDragger::~MOAIGwenDragger () {
}


//----------------------------------------------------------------//
void MOAIGwenDragger::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_DRAG_START",    ( u32 )EVENT_DRAG_START   );
	state.SetField ( -1, "EVENT_DRAG_END",  ( u32 )EVENT_DRAG_END );
	luaL_Reg regTable [] = {
		{ "new", MOAILogMessages::_alertNewIsUnsupported },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenDragger::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setAllowMove",    _setAllowMove },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
