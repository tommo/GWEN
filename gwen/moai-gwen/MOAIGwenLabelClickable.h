#ifndef	MOAIGWENLABELCLICKABLE_H
#define	MOAIGWENLABELCLICKABLE_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/LabelClickable.h"

//================================================================//
// MOAIGwenLabelClickable
//================================================================//
/**	@lua MOAIGwenLabelClickable
	@text Box2D joint.
*/
class MOAIGwenLabelClickable :
	public MOAIGwenButton {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenButton::TOTAL_EVENTS
	};

private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLabelClickable )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenButton::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::LabelClickable* GetInternalControl() { 
		return static_cast < Gwen::Controls::LabelClickable* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenLabelClickable )
	
	//----------------------------------------------------------------//
						MOAIGwenLabelClickable			();
						~MOAIGwenLabelClickable			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
