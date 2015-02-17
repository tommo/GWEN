#ifndef	MOAIGWENDragger_H
#define	MOAIGWENDragger_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Dragger.h"

//================================================================//
// MOAIGwenDragger
//================================================================//
/**	@lua MOAIGwenDragger
	@text Box2D joint.
*/
class MOAIGwenDragger :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_DRAG_START = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_DRAG_END,
		TOTAL_EVENTS
	};

private:
	static int _setAllowMove          ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenDragger )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onDragStart, EVENT_DRAG_START );
		ConnectEventCallBack( GetInternalControl()->onDragged, EVENT_DRAG_END );
	};

public:
		
	inline Gwen::ControlsInternal::Dragger* GetInternalControl() { 
		return static_cast < Gwen::ControlsInternal::Dragger* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenDragger )
	
	//----------------------------------------------------------------//
						MOAIGwenDragger			();
						~MOAIGwenDragger			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
