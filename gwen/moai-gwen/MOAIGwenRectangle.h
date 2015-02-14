#ifndef	MOAIGWENRECTANGLE_H
#define	MOAIGWENRECTANGLE_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Rectangle.h"

//================================================================//
// MOAIGwenRectangle
//================================================================//
/**	@lua MOAIGwenRectangle
	@text Box2D joint.
*/
class MOAIGwenRectangle :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _setColor              ( lua_State* L );
	static int _getColor              ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenRectangle )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::Rectangle* GetInternalControl() { 
		return static_cast < Gwen::Controls::Rectangle* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenRectangle )
	
	//----------------------------------------------------------------//
						MOAIGwenRectangle			();
						~MOAIGwenRectangle			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
