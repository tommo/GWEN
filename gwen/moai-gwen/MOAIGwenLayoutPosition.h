#ifndef	MOAIGWENLAYOUTPOSITION_H
#define	MOAIGWENLAYOUTPOSITION_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Layout/Position.h"

//================================================================//
// MOAIGwenLayoutPosition
//================================================================//
/**	@lua MOAIGwenLayoutPosition
	@text Box2D joint.
*/
class MOAIGwenLayoutPosition :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _setPosition              ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLayoutPosition )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::Layout::Position* GetInternalControl() { 
		return static_cast < Gwen::Controls::Layout::Position* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenLayoutPosition )
	
	//----------------------------------------------------------------//
						MOAIGwenLayoutPosition			();
						~MOAIGwenLayoutPosition			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
