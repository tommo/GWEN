#include "moai-gwen/MOAIGwenComboBox.h"

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenComboBox::CreateGwenControl() {
	return new Gwen::Controls::ComboBox( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenComboBox::MOAIGwenComboBox () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenButton )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenComboBox::~MOAIGwenComboBox () {
}


//----------------------------------------------------------------//
void MOAIGwenComboBox::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",     ( u32 )EVENT_CHANGE    );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenComboBox::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenButton::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		// { "addItem",           _addItem           },
		// { "selectItem",        _selectItem        },
		// { "selectItemByName",  _selectItemByName  },
		// { "clearItems",        _clearItems        },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
