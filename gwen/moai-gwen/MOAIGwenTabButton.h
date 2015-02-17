#ifndef	MOAIGWENTabButton_H
#define	MOAIGWENTabButton_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/TabButton.h"

//================================================================//
// MOAIGwenTabButton
//================================================================//
/**	@lua MOAIGwenTabButton
	@text Box2D joint.
*/

class MOAIGwenTabButton :
	public MOAIGwenButton {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenButton::TOTAL_EVENTS
	};

private:

	static int		_setPage         ( lua_State* L );
	static int		_getPage         ( lua_State* L );
	static int		_getTabControl   ( lua_State* L );
	static int		_isActive        ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenTabButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenButton::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::TabButton* GetInternalControl() { 
		return static_cast < Gwen::Controls::TabButton* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenTabButton )
	
	//----------------------------------------------------------------//
						MOAIGwenTabButton			();
						~MOAIGwenTabButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
