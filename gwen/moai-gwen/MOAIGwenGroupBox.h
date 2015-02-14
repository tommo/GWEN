#ifndef	MOAIGwenGroupBox_H
#define	MOAIGwenGroupBox_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/GroupBox.h"

//================================================================//
// MOAIGwenGroupBox
//================================================================//
/**	@lua MOAIGwenGroupBox
	@text Box2D joint.
*/
class MOAIGwenGroupBox :
	public MOAIGwenLabel {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenLabel::TOTAL_EVENTS
	};

private:
	
	static int _setInnerMargin( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenGroupBox )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenLabel::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::GroupBox* GetInternalControl() { 
		return static_cast < Gwen::Controls::GroupBox* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenGroupBox )
	
	//----------------------------------------------------------------//
						MOAIGwenGroupBox			();
						~MOAIGwenGroupBox			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
