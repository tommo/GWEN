#ifndef	MOAIGWENRADIOBUTTON_H
#define	MOAIGWENRADIOBUTTON_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenCheckBox.h"
#include "Gwen/Controls/RadioButton.h"

//================================================================//
// MOAIGwenRadioButton
//================================================================//
/**	@lua MOAIGwenRadioButton
	@text Box2D joint.
*/

class MOAIGwenRadioButton :
	public MOAIGwenCheckBox {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenCheckBox::TOTAL_EVENTS
	};
private:

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenRadioButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenCheckBox::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::RadioButton* GetInternalControl() { 
		return static_cast < Gwen::Controls::RadioButton* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenRadioButton )
	
	//----------------------------------------------------------------//
						MOAIGwenRadioButton			();
						~MOAIGwenRadioButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


#endif
