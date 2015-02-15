#ifndef	MOAIGWENMENUBAR_H
#define	MOAIGWENMENUBAR_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenMenu.h"
#include "Gwen/Controls/MenuStrip.h"

//================================================================//
// MOAIGwenMenuBar
//================================================================//
/**	@lua MOAIGwenMenuBar
	@text Box2D joint.
*/
class MOAIGwenMenuBar :
	public MOAIGwenMenu {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenMenu::TOTAL_EVENTS,
	};

private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenMenuBar )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenMenu::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::MenuStrip* GetInternalControl() { 
		return static_cast < Gwen::Controls::MenuStrip* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenMenuBar )
	
	//----------------------------------------------------------------//
						MOAIGwenMenuBar			();
						~MOAIGwenMenuBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
