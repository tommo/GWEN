#ifndef	MOAIGWENBUTTON_H
#define	MOAIGWENBUTTON_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Button.h"

//================================================================//
// MOAIGwenButton
//================================================================//
/**	@lua MOAIGwenButton
	@text Box2D joint.
*/
class MOAIGwenButton :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CLICK = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_DOWN,
		EVENT_UP,
		EVENT_TOGGLE,
		TOTAL_EVENTS,
	};

private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onPress,  EVENT_CLICK );
		ConnectEventCallBack( GetInternalControl()->onDown,   EVENT_DOWN );
		ConnectEventCallBack( GetInternalControl()->onUp,     EVENT_UP );
		ConnectEventCallBack( GetInternalControl()->onToggle, EVENT_TOGGLE );
	};

public:
		
	inline Gwen::Controls::Button* GetInternalControl() { 
		return static_cast < Gwen::Controls::Button* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenButton )
	
	//----------------------------------------------------------------//
						MOAIGwenButton			();
						~MOAIGwenButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
