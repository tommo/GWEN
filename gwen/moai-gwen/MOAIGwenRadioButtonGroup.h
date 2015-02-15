#ifndef	MOAIGwenRadioButtonGroup_H
#define	MOAIGwenRadioButtonGroup_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/RadioButtonController.h"

class MOAIGwenSystem;
//================================================================//
// MOAIGwenRadioButtonGroup
//================================================================//
/**	@lua MOAIGwenRadioButtonGroup
	@text Box2D joint.
*/
class MOAIGwenRadioButtonGroup :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:
	
	static int _addOption     ( lua_State* L );
	static int _getSelection  ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenRadioButtonGroup )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onSelectionChange,  EVENT_CHANGE );
	};

public:
	
	MOAIGwenSystem* mRootSystem;

	inline Gwen::Controls::RadioButtonController* GetInternalControl() { 
		return static_cast < Gwen::Controls::RadioButtonController* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenRadioButtonGroup )

	//----------------------------------------------------------------//
						MOAIGwenRadioButtonGroup			( Gwen::Controls::Base* control );
						MOAIGwenRadioButtonGroup			();
						~MOAIGwenRadioButtonGroup			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
