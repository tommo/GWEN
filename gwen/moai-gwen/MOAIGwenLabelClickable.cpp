#include "moai-gwen/MOAIGwenLabelClickable.h"


Gwen::Controls::Base* MOAIGwenLabelClickable::CreateGwenControl() {
	return new Gwen::Controls::LabelClickable( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenLabelClickable::MOAIGwenLabelClickable () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenButton )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenLabelClickable::~MOAIGwenLabelClickable () {
}


//----------------------------------------------------------------//
void MOAIGwenLabelClickable::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaClass( state );
	
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenLabelClickable::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
