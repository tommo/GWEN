#ifndef	MOAIGWENCHECKBOX_H
#define	MOAIGWENCHECKBOX_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/CheckBox.h"

//================================================================//
// MOAIGwenCheckBox
//================================================================//
/**	@lua MOAIGwenCheckBox
	@text Box2D joint.
*/

class MOAIGwenCheckBox :
	public MOAIGwenButton {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenButton::TOTAL_EVENTS,
		EVENT_CHECK,
		EVENT_UNCHECK,
		TOTAL_EVENTS,
	};

private:

	static int		_setChecked   ( lua_State* L );
	static int		_toggle       ( lua_State* L );
	static int		_isChecked    ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenCheckBox )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenButton::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onCheckChanged,  EVENT_CHANGE );
		ConnectEventCallBack( GetInternalControl()->onChecked,       EVENT_CHECK );
		ConnectEventCallBack( GetInternalControl()->onUnChecked,     EVENT_UNCHECK );
	};

public:
		
	inline Gwen::Controls::CheckBox* GetInternalControl() { 
		return static_cast < Gwen::Controls::CheckBox* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenCheckBox )
	
	//----------------------------------------------------------------//
						MOAIGwenCheckBox			();
						~MOAIGwenCheckBox			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
