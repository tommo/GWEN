#ifndef	MOAIGWENTextBox_H
#define	MOAIGWENTextBox_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/TextBox.h"

//================================================================//
// MOAIGwenTextBox
//================================================================//
/**	@lua MOAIGwenTextBox
	@text Box2D joint.
*/
class MOAIGwenTextBox :
	public MOAIGwenLabel {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenLabel::TOTAL_EVENTS,
		EVENT_RETURN_PRESS,
		TOTAL_EVENTS,
	};

private:
	
	static int _setReadOnly          ( lua_State* L );
	static int _setEditable          ( lua_State* L );
	static int _hasSelection         ( lua_State* L );
	static int _getSelection         ( lua_State* L );
	static int _deleteSelection      ( lua_State* L );
	static int _setSelectAllOnFocus  ( lua_State* L );
	static int _moveCursorToEnd      ( lua_State* L );
	static int _moveCursorToStart    ( lua_State* L );
	static int _getCursorPos         ( lua_State* L );
	static int _setCursorPos         ( lua_State* L );
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenTextBox )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenLabel::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onTextChanged,  EVENT_CHANGE );
		ConnectEventCallBack( GetInternalControl()->onReturnPressed,   EVENT_RETURN_PRESS );
	};

public:
		
	inline Gwen::Controls::TextBox* GetInternalControl() { 
		return static_cast < Gwen::Controls::TextBox* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenTextBox )
	
	//----------------------------------------------------------------//
						MOAIGwenTextBox			();
						~MOAIGwenTextBox			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
