#ifndef	MOAIGwenStatusBar_H
#define	MOAIGwenStatusBar_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/StatusBar.h"

//================================================================//
// MOAIGwenStatusBar
//================================================================//
/**	@lua MOAIGwenStatusBar
	@text Box2D joint.
*/
class MOAIGwenStatusBar :
	public MOAIGwenLabel {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenLabel::TOTAL_EVENTS
	};

private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenStatusBar )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenLabel::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::StatusBar* GetInternalControl() { 
		return static_cast < Gwen::Controls::StatusBar* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenStatusBar )
	
	//----------------------------------------------------------------//
						MOAIGwenStatusBar			();
						~MOAIGwenStatusBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
