#ifndef	MOAIGWENMenu_H
#define	MOAIGWENMenu_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenScrollControl.h"
#include "Gwen/Controls/Menu.h"

//================================================================//
// MOAIGwenMenu
//================================================================//
/**	@lua MOAIGwenMenu
	@text Box2D joint.
*/
class MOAIGwenMenu :
	public MOAIGwenScrollControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenScrollControl::TOTAL_EVENTS
	};

private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenMenu )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenScrollControl::ConnectEvents();
		// ConnectEventCallBack( GetInternalControl()->onToggle, EVENT_TOGGLE );
	};

public:
		
	inline Gwen::Controls::Menu* GetInternalControl() { 
		return static_cast < Gwen::Controls::Menu* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenMenu )
	
	//----------------------------------------------------------------//
						MOAIGwenMenu			();
						~MOAIGwenMenu			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
