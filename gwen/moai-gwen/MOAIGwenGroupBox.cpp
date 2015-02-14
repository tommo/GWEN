#include "moai-gwen/MOAIGwenGroupBox.h"

int MOAIGwenGroupBox::_setInnerMargin ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenGroupBox, "UN" )
	u32 margin = state.GetValue < u32 >( 2, 0 );
	self->GetInternalControl()->SetInnerMargin( margin );
	return 0;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenGroupBox::CreateGwenControl() {
	return new Gwen::Controls::GroupBox( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenGroupBox::MOAIGwenGroupBox () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenLabel )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenGroupBox::~MOAIGwenGroupBox () {
}


//----------------------------------------------------------------//
void MOAIGwenGroupBox::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenGroupBox::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setInnerMargin",   _setInnerMargin  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
