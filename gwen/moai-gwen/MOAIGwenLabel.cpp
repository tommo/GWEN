#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/Label.h"


//----------------------------------------------------------------//
MOAIGwenLabel::MOAIGwenLabel () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
	this->SetInternalControl( 
		new Gwen::Controls::Label( MOAIGwenMgr::Get().GetDefaultCanvas() ) 
		);
}

MOAIGwenLabel::MOAIGwenLabel ( Gwen::Controls::Label* label ) {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
	this->SetInternalControl( label );
}


//----------------------------------------------------------------//
MOAIGwenLabel::~MOAIGwenLabel () {
}

//----------------------------------------------------------------//
void MOAIGwenLabel::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
}

//----------------------------------------------------------------//
void MOAIGwenLabel::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		// { "capParticles",		_capParticles },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
