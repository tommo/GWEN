#ifndef	MOAIGWENTabControl_H
#define	MOAIGWENTabControl_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/TabControl.h"

//================================================================//
// MOAIGwenTabControl
//================================================================//
/**	@lua MOAIGwenTabControl
	@text Box2D joint.
*/
class MOAIGwenTabControl :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_TAB_ADD = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_TAB_CLOSE,
		TOTAL_EVENTS,
	};

private:
	
	static int _addPage           ( lua_State* L );
	static int _addTab            ( lua_State* L );
	static int _removeTab         ( lua_State* L );
	static int _getTabCount       ( lua_State* L );
	static int _getTab            ( lua_State* L );
	static int _getCurrentTab     ( lua_State* L );
	static int _getCurrentPage    ( lua_State* L );
	static int _setTabBarPosition ( lua_State* L );
	static int _setAllowReorder   ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenTabControl )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onLoseTab, EVENT_TAB_CLOSE );
		ConnectEventCallBack( GetInternalControl()->onAddTab,  EVENT_TAB_ADD );
	};

public:
		
	inline Gwen::Controls::TabControl* GetInternalControl() { 
		return static_cast < Gwen::Controls::TabControl* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenTabControl )
	
	//----------------------------------------------------------------//
						MOAIGwenTabControl			();
						~MOAIGwenTabControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
