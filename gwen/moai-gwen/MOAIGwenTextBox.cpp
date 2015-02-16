#include "moai-gwen/MOAIGwenTextBox.h"

int MOAIGwenTextBox::_setReadOnly ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	bool readonly = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetEditable( !readonly );
	return 0;
}

int MOAIGwenTextBox::_setEditable ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	bool editable = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetEditable( editable );
	return 0;
}

int MOAIGwenTextBox::_deleteSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	self->GetInternalControl()->EraseSelection();
	return 0;
}

int MOAIGwenTextBox::_getSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	if( self->GetInternalControl()->HasSelection() ) {
		lua_pushstring( state, self->GetInternalControl()->GetSelection().c_str() );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenTextBox::_hasSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	state.Push( self->GetInternalControl()->HasSelection() );
	return 1;
}

int MOAIGwenTextBox::_setSelectAllOnFocus ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	self->GetInternalControl()->SetSelectAllOnFocus( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenTextBox::_getCursorPos ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	state.Push ( self->GetInternalControl()->GetCursorPos() );
	state.Push ( self->GetInternalControl()->GetCursorEnd() );
	return 2;
}

int MOAIGwenTextBox::_setCursorPos ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "UN" )
	u32 begin = state.GetValue < u32 >( 2, 0 );
	u32 end   = state.GetValue < u32 >( 3, begin );	
	self->GetInternalControl()->SetCursorPos( begin );
	self->GetInternalControl()->SetCursorEnd( end );
	return 0;
}


int MOAIGwenTextBox::_moveCursorToEnd ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	self->GetInternalControl()->MoveCaretToEnd();
	return 0;
}

int MOAIGwenTextBox::_moveCursorToStart ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTextBox, "U" )
	self->GetInternalControl()->MoveCaretToStart();
	return 0;
}


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenTextBox::CreateGwenControl() {
	return new Gwen::Controls::TextBox( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenTextBox::MOAIGwenTextBox () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenLabel )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenTextBox::~MOAIGwenTextBox () {
}


//----------------------------------------------------------------//
void MOAIGwenTextBox::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaClass( state );
	
	state.SetField ( -1, "EVENT_CHANGE",        ( u32 )EVENT_CHANGE       );
	state.SetField ( -1, "EVENT_RETURN_PRESS",  ( u32 )EVENT_RETURN_PRESS );

	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenTextBox::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenLabel::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setReadOnly",         _setReadOnly         },
		{ "setEditable",         _setEditable         },
		{ "hasSelection",        _hasSelection        },
		{ "getSelection",        _getSelection        },
		{ "deleteSelection",     _deleteSelection     },
		{ "setSelectAllOnFocus", _setSelectAllOnFocus },
		{ "moveCursorToEnd",     _moveCursorToEnd     },
		{ "moveCursorToStart",   _moveCursorToStart   },
		{ "getCursorPos",        _getCursorPos        },
		{ "setCursorPos",        _setCursorPos        },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
