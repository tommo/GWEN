#ifndef	MOAIGWENLAYOUTTable_H
#define	MOAIGWENLAYOUTTable_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Layout/Table.h"

//================================================================//
// MOAIGwenLayoutTable
//================================================================//
/**	@lua MOAIGwenLayoutTableRow
	@text Box2D joint.
*/
class MOAIGwenLayoutTableRow :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_SELECT = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS
	};

private:
	static int _setCellText         ( lua_State* L );
	static int _getCellText         ( lua_State* L );
	static int _setCellControl      ( lua_State* L );
	static int _getCell             ( lua_State* L );
	static int _setTextColor        ( lua_State* L );
	static int _setSelected         ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLayoutTableRow )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onRowSelected,  EVENT_SELECT );
	};

public:
		
	inline Gwen::Controls::Layout::TableRow* GetInternalControl() { 
		return static_cast < Gwen::Controls::Layout::TableRow* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenLayoutTableRow )
	
	//----------------------------------------------------------------//
						MOAIGwenLayoutTableRow			();
						~MOAIGwenLayoutTableRow			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//================================================================//
// MOAIGwenLayoutTable
//================================================================//
/**	@lua MOAIGwenLayoutTable
	@text Box2D joint.
*/
class MOAIGwenLayoutTable :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _setColumnCount  ( lua_State* L );
	static int _setColumnWidth  ( lua_State* L );
	static int _addRow          ( lua_State* L );
	static int _getRow          ( lua_State* L );
	static int _removeRow       ( lua_State* L );
	static int _getRowCount     ( lua_State* L );
	static int _clear           ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLayoutTable )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::Layout::Table* GetInternalControl() { 
		return static_cast < Gwen::Controls::Layout::Table* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenLayoutTable )
	
	//----------------------------------------------------------------//
						MOAIGwenLayoutTable			();
						~MOAIGwenLayoutTable			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
