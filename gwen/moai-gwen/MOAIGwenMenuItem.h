#ifndef	MOAIGWENMenuItem_H
#define	MOAIGWENMenuItem_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/MenuItem.h"

//================================================================//
// MOAIGwenMenuItem
//================================================================//
/**	@lua MOAIGwenMenuItem
	@text Box2D joint.
*/

class MOAIGwenMenuItem :
	public MOAIGwenButton {
public:
	enum Events{
		EVENT_SELECT = MOAIGwenButton::TOTAL_EVENTS,
		EVENT_CHANGE,
		EVENT_CHECK,
		EVENT_UNCHECK,
		TOTAL_EVENTS,
	};

private:

	static int		_openMenu         ( lua_State* L );
	static int		_setCheckable     ( lua_State* L );
	static int		_setChecked       ( lua_State* L );
	static int		_toggle           ( lua_State* L );
	static int		_isChecked        ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenMenuItem )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenButton::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onMenuItemSelected,  EVENT_SELECT );
		ConnectEventCallBack( GetInternalControl()->onCheckChange,       EVENT_CHANGE );
		ConnectEventCallBack( GetInternalControl()->onChecked,           EVENT_CHECK );
		ConnectEventCallBack( GetInternalControl()->onUnChecked,         EVENT_UNCHECK );
	};

public:
		
	inline Gwen::Controls::MenuItem* GetInternalControl() { 
		return static_cast < Gwen::Controls::MenuItem* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenMenuItem )
	
	//----------------------------------------------------------------//
						MOAIGwenMenuItem			();
						~MOAIGwenMenuItem			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
