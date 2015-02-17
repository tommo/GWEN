#ifndef	MOAIGWENPROPERTY_H
#define	MOAIGWENPROPERTY_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Property/BaseProperty.h"


//================================================================//
// MOAIGwenBaseProperty
//================================================================//
/**	@lua MOAIGwenBaseProperty
	@text Box2D joint.
*/
class MOAIGwenBaseProperty :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS
	};

private:
	static int _getValue     ( lua_State* L );
	static int _setValue     ( lua_State* L );
	static int _isEditing    ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenBaseProperty )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onChange,  EVENT_CHANGE );
	};

public:
		
	inline Gwen::Controls::Property::Base* GetInternalControl() { 
		return static_cast < Gwen::Controls::Property::Base* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenBaseProperty )
	
	//----------------------------------------------------------------//
						MOAIGwenBaseProperty			();
						~MOAIGwenBaseProperty			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
