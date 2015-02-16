#include "moai-gwen/MOAIGwenListBox.h"

int MOAIGwenListBox::_addItem ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	cc8* name = state.GetValue < cc8* >( 3, text );
	Gwen::Controls::Layout::TableRow* row = self->GetInternalControl()->AddItem( text, name );
	PushGwenControl( state, row );
	return 1;
}

int MOAIGwenListBox::_removeItem ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "UU" )
	MOAIGwenLayoutTableRow* row = state.GetLuaObject< MOAIGwenLayoutTableRow >( 2, 0 );
	if( row ){
		self->GetInternalControl()->RemoveItem( row->GetInternalControl() );
	}
	return 0;
}

int MOAIGwenListBox::_getSelectedRow ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	cc8* name = state.GetValue < cc8* >( 3, text );
	Gwen::Controls::Layout::TableRow* row = self->GetInternalControl()->GetSelectedRow();
	PushGwenControl( state, row );
	return 1;
}

int MOAIGwenListBox::_getSelectedRows ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	cc8* name = state.GetValue < cc8* >( 3, text );
	const Gwen::Controls::ListBox::Rows& rows = 
		self->GetInternalControl()->GetSelectedRows();
	lua_newtable( L );
	u32 count = 0;
	for ( Gwen::Controls::ListBox::Rows::const_iterator it = rows.begin() ;
			 it != rows.end();
			 ++it )
	{
		Gwen::Controls::Base* child = *it ;
		lua_pushnumber ( state, count );
		PushGwenControl( state, child );
		lua_settable( L, -3 );
		++count;
	}
	return 1;
}


int MOAIGwenListBox::_getSelectedRowName ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	Gwen::Controls::Layout::TableRow* row = self->GetInternalControl()->GetSelectedRow();
	if( row ){
		lua_pushstring( state, self->GetInternalControl()->GetSelectedRowName().c_str() );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenListBox::_setAllowMultiSelect ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	self->GetInternalControl()->SetAllowMultiSelect( state.GetValue < bool >( 2, true ) );
	return 0;
}

int MOAIGwenListBox::_isAllowMultiSelect ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	state.Push( 
		self->GetInternalControl()->AllowMultiSelect()
	);
	return 1;
}

int MOAIGwenListBox::_select ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "UU" )
	MOAIGwenLayoutTableRow* row = state.GetLuaObject< MOAIGwenLayoutTableRow >( 2, 0 );
	bool additive = state.GetValue < bool >( 3, false );
	if( row )
		self->GetInternalControl()->SetSelectedRow( row->GetInternalControl(), !additive );
	return 0;
}

int MOAIGwenListBox::_selectByName ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "US" )
	cc8* name = state.GetValue < cc8* >( 3, "" );
	bool additive = state.GetValue < bool >( 3, false );
	self->GetInternalControl()->SelectByString( name, !additive );
	return 0;
}

int MOAIGwenListBox::_deselectAll ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "U" )
	self->GetInternalControl()->UnselectAll();
	return 0;
}

int MOAIGwenListBox::_setColumnCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "UN" )
	self->GetInternalControl()->SetColumnCount(
		state.GetValue < u32 >( 2, 1 )
		);
	return 0;
}

int MOAIGwenListBox::_setColumnWidth ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenListBox, "UNN" )
	u32 id      = state.GetValue < u32 >( 2, 1 ) - 1;
	float width = state.GetValue < float >( 2, 50.0f );
	self->GetInternalControl()->SetColumnWidth(	id, width	);
	return 0;
}

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
		{ "addItem",                   _addItem                   },
		{ "removeItem",                _removeItem                },
		{ "deselectAll",               _deselectAll               },
		{ "setAllowMultiSelect", _setAllowMultiSelect },
		{ "isAllowMultiSelect",  _isAllowMultiSelect  },
		{ "getSelectedRows",           _getSelectedRows           },
		{ "getSelectedRow",            _getSelectedRow            },
		{ "getSelectedRowName",        _getSelectedRowName        },
		{ "select",                    _select                    },
		{ "selectByName",              _selectByName              },
		{ "setColumnCount",            _setColumnCount            },
		{ "setColumnWidth",            _setColumnWidth            },
		{ "clear",                     _clear                     },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
