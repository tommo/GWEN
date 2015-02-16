#ifndef	MOAIGWENDOCKBASE_H
#define	MOAIGWENDOCKBASE_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/DockBase.h"
#include "Gwen/Controls/TabControl.h"

//================================================================//
// MOAIGwenDockBase
//================================================================//
/**	@lua MOAIGwenDockBase
	@text Box2D joint.
*/
class MOAIGwenDockBase :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _getTabControl        ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenDockBase )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::DockBase* GetInternalControl() { 
		return static_cast < Gwen::Controls::DockBase* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenDockBase )
	
	//----------------------------------------------------------------//
						MOAIGwenDockBase			();
						~MOAIGwenDockBase			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
