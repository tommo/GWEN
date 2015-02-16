#ifndef	MOAIGWENListBox_H
#define	MOAIGWENListBox_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenScrollControl.h"
#include "Gwen/Controls/ListBox.h"

//================================================================//
// MOAIGwenListBox
//================================================================//
/**	@lua MOAIGwenListBox
	@text Box2D joint.
*/
class MOAIGwenListBox :
	public MOAIGwenScrollControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenScrollControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:
	
	static int _clear         ( lua_State *L ) ;
	// static int _deselectAll   ( lua_State *L ) ;
	// static int _setAllowMultipleSelection   ( lua_State *L ) ;
	// static int _isAllowMultipleSelection    ( lua_State *L ) ;
	// static int _getTable   ( lua_State *L ) ;

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenListBox )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenScrollControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onRowSelected,  EVENT_CHANGE );
	};

public:
		
	inline Gwen::Controls::ListBox* GetInternalControl() { 
		return static_cast < Gwen::Controls::ListBox* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenListBox )
	
	//----------------------------------------------------------------//
						MOAIGwenListBox			();
						~MOAIGwenListBox			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
