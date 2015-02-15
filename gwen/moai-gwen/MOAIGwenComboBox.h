#ifndef	MOAIGWENComboBox_H
#define	MOAIGWENComboBox_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/ComboBox.h"

//================================================================//
// MOAIGwenComboBox
//================================================================//
/**	@lua MOAIGwenComboBox
	@text Box2D joint.
*/

class MOAIGwenComboBox :
	public MOAIGwenButton {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenButton::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:

	// static int		_addItem          ( lua_State* L );
	// static int		_selectItem       ( lua_State* L );
	// static int		_selectItemByName ( lua_State* L );
	// static int		_clearItems       ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenComboBox )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenButton::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onSelection,  EVENT_CHANGE );
	};

public:
		
	inline Gwen::Controls::ComboBox* GetInternalControl() { 
		return static_cast < Gwen::Controls::ComboBox* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenComboBox )
	
	//----------------------------------------------------------------//
						MOAIGwenComboBox			();
						~MOAIGwenComboBox			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
