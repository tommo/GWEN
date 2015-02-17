#ifndef	MOAIGWENPROPERTIES_H
#define	MOAIGWENPROPERTIES_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Properties.h"

//================================================================//
// MOAIGwenPropertyRow
//================================================================//
/**	@lua MOAIGwenPropertyRow
*/
class MOAIGwenPropertyRow :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
	};

private:
	static int _getLabel     ( lua_State* L );
	static int _getProperty  ( lua_State* L );
	static int _setProperty  ( lua_State* L );
	static int _isEditing    ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenPropertyRow )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onChange,  EVENT_CHANGE );
	};

public:
		
	inline Gwen::Controls::PropertyRow* GetInternalControl() { 
		return static_cast < Gwen::Controls::PropertyRow* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenPropertyRow )
	
	//----------------------------------------------------------------//
						MOAIGwenPropertyRow			();
						~MOAIGwenPropertyRow			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//================================================================//
// MOAIGwenProperties
//================================================================//
/**	@lua MOAIGwenProperties
*/
class MOAIGwenProperties :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS,
	};

private:
	static int _add     ( lua_State* L );
	static int _find    ( lua_State* L );
	static int _clear   ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenProperties )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::Properties* GetInternalControl() { 
		return static_cast < Gwen::Controls::Properties* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenProperties )
	
	//----------------------------------------------------------------//
						MOAIGwenProperties			();
						~MOAIGwenProperties			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


#endif
