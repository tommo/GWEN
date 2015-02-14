#ifndef	MOAIGWENWINDOWCONTROL_H
#define	MOAIGWENWINDOWCONTROL_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/WindowControl.h"

//================================================================//
// MOAIGwenWindowControl
//================================================================//
/**	@lua MOAIGwenWindowControl
	@text Box2D joint.
*/
class MOAIGwenWindowControl :
	public MOAIGwenControl {
public:
	enum Events {
		EVENT_CLOSE = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_RESIZE,
		TOTAL_EVENTS
	};

private:
	
	static int _setTitle           ( lua_State* L );
	static int _setClosable        ( lua_State* L );
	static int _setResizable       ( lua_State* L );
	static int _makeModal          ( lua_State* L );
	static int _destroyModal       ( lua_State* L );
	static int _setDeleteOnClose   ( lua_State* L );
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenWindowControl )
	virtual Gwen::Controls::Base* CreateGwenControl();
	
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onWindowClosed,  EVENT_CLOSE );
		ConnectEventCallBack( GetInternalControl()->onResize,  EVENT_RESIZE );

	};

public:
	
	inline Gwen::Controls::WindowControl* GetInternalControl() { 
		return static_cast < Gwen::Controls::WindowControl* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenWindowControl )
	
	//----------------------------------------------------------------//
						MOAIGwenWindowControl			();
						~MOAIGwenWindowControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
