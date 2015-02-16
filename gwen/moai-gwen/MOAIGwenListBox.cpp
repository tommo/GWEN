#include "moai-gwen/MOAIGwenListBox.h"

int MOAIGwenListBox::_clear ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	self->GetInternalControl()->Clear();
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenListBox::CreateGwenControl() {
	return new Gwen::Controls::ListBox( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenListBox::MOAIGwenListBox () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenScrollControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenListBox::~MOAIGwenListBox () {
}


//----------------------------------------------------------------//
void MOAIGwenListBox::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",   ( u32 )EVENT_CHANGE  );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenListBox::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "clear",   _clear  },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
