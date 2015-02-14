#include "moai-gwen/MOAIGwenCheckBox.h"


int MOAIGwenCheckBox::_toggle ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCheckBox, "U" )
	self->GetInternalControl()->Toggle();
	return 0;
}

int MOAIGwenCheckBox::_setChecked ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCheckBox, "U" )
	self->GetInternalControl()->SetChecked( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenCheckBox::_isChecked ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCheckBox, "U" )
	state.Push( self->GetInternalControl()->IsChecked() );
	return 1;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenCheckBox::CreateGwenControl() {
	return new Gwen::Controls::CheckBox( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenCheckBox::MOAIGwenCheckBox () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenCheckBox::~MOAIGwenCheckBox () {
}


//----------------------------------------------------------------//
void MOAIGwenCheckBox::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",     ( u32 )EVENT_CHANGE    );
	state.SetField ( -1, "EVENT_CHECK",      ( u32 )EVENT_CHECK     );
	state.SetField ( -1, "EVENT_UNCHECK",    ( u32 )EVENT_UNCHECK   );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenCheckBox::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setChecked",     _setChecked  },
		{ "toggle",         _toggle      },
		{ "isChecked",      _isChecked   },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
