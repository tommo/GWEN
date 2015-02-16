#include "moai-gwen/MOAIGwenLayoutTable.h"
//----------------------------------------------------------------//
//TableRow
//----------------------------------------------------------------//

int MOAIGwenLayoutTableRow::_getCellText ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTableRow, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	const Gwen::TextObject& text = self->GetInternalControl()->GetText( id );
	lua_pushstring( state, text.c_str() );
	return 1;
}

int MOAIGwenLayoutTableRow::_setCellText ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTableRow, "UNS" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	cc8* text = state.GetValue < cc8* >( 3, "" );
	self->GetInternalControl()->SetCellText( id, text );
	return 0;
}

int MOAIGwenLayoutTableRow::_setCellControl ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTableRow, "UNU" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	MOAIGwenControl* control = state.GetLuaObject< MOAIGwenControl >( 3, 0 );
	bool mouseInputEnabled = state.GetValue < bool >( 4, false );
	self->GetInternalControl()->SetCellContents( id, control->GetInternalControl(), mouseInputEnabled );
	return 1;
}

int MOAIGwenLayoutTableRow::_getCell ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTableRow, "UN" )
	int id = state.GetValue< int >( 2, 1 ) - 1;
	Gwen::Controls::Base* raw = self->GetInternalControl()->GetCellContents( id );
	MOAIGwenControl* control = _GwenToMoai( raw );
	if( control ) {
		control->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

int MOAIGwenLayoutTableRow::_setSelected ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTableRow, "U" )
	bool selected = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetSelected( selected );
	return 0;
}


int MOAIGwenLayoutTableRow::_setTextColor(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLayoutTableRow, "UNNN" )
	float r = state.GetValue < float >( 2, 1.0f );
	float g = state.GetValue < float >( 3, 1.0f );
	float b = state.GetValue < float >( 4, 1.0f );
	float a = state.GetValue < float >( 5, 1.0f );
	self->GetInternalControl()->SetTextColor( 
		Gwen::Color(
			r * 255,
			g * 255,
			b * 255,
			a * 255
		)
	);
	return 0;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenLayoutTableRow::CreateGwenControl() {
	return new Gwen::Controls::Layout::TableRow( NULL );
}

//----------------------------------------------------------------//
MOAIGwenLayoutTableRow::MOAIGwenLayoutTableRow () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenLayoutTableRow::~MOAIGwenLayoutTableRow () {
}


//----------------------------------------------------------------//
void MOAIGwenLayoutTableRow::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_SELECT",   ( u32 )EVENT_SELECT  );
	luaL_Reg regTableRow [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTableRow );
}

//----------------------------------------------------------------//
void MOAIGwenLayoutTableRow::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setCellText",     _setCellText    },
		{ "getCellText",     _getCellText    },
		{ "setCellControl",  _setCellControl },
		{ "getCell",         _getCell        },
		{ "setTextColor",    _setTextColor   },
		{ "setSelected",     _setSelected    },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}



//----------------------------------------------------------------//
//Table
//----------------------------------------------------------------//
int MOAIGwenLayoutTable::_setColumnCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UN" )
	self->GetInternalControl()->SetColumnCount(
		state.GetValue < u32 >( 2, 1 )
		);
	return 0;
}

int MOAIGwenLayoutTable::_setColumnWidth ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UNN" )
	u32 id      = state.GetValue < u32 >( 2, 1 ) - 1;
	float width = state.GetValue < float >( 2, 50.0f );
	self->GetInternalControl()->SetColumnWidth(	id, width	);
	return 0;
}

int MOAIGwenLayoutTable::_getRow ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	Gwen::Controls::Base* raw = self->GetInternalControl()->GetRow( id );
	MOAIGwenControl* control = _GwenToMoai( raw );
	if( control ) {
		control->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
	return 0;
}

int MOAIGwenLayoutTable::_removeRow ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	Gwen::Controls::Layout::TableRow* row = self->GetInternalControl()->GetRow( id );
	if( !row )
		self->GetInternalControl()->Remove( row );
	return 0;
}

int MOAIGwenLayoutTable::_addRow ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "U" )
	Gwen::Controls::Base* raw = self->GetInternalControl()->AddRow();
	MOAIGwenControl* control = _GwenToMoai( raw );
	control->PushLuaUserdata( state );
	return 1;
}

int MOAIGwenLayoutTable::_getRowCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UN" )
	state.Push ( self->GetInternalControl()->RowCount() );
	return 1;
}

int MOAIGwenLayoutTable::_clear ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLayoutTable, "UN" )
	self->GetInternalControl()->Clear();
	return 0;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenLayoutTable::CreateGwenControl() {
	return new Gwen::Controls::Layout::Table( NULL );
}

//----------------------------------------------------------------//
MOAIGwenLayoutTable::MOAIGwenLayoutTable () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenLayoutTable::~MOAIGwenLayoutTable () {
}


//----------------------------------------------------------------//
void MOAIGwenLayoutTable::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new", _new },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenLayoutTable::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setColumnCount",  _setColumnCount },
		{ "setColumnWidth",  _setColumnWidth },
		{ "addRow",          _addRow         },
		{ "getRow",          _getRow         },
		{ "removeRow",       _removeRow      },
		{ "getRowCount",     _getRowCount    },
		{ "clear",           _clear          },
		{ NULL, NULL  }
	};


	
	luaL_register ( state, 0, regTable );
}
