#ifndef	MOAIGwenColorPicker_H
#define	MOAIGwenColorPicker_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/ColorPicker.h"

class MOAIGwenSystem;
//================================================================//
// MOAIGwenColorPicker
//================================================================//
/**	@lua MOAIGwenColorPicker
	@text Box2D joint.
*/
class MOAIGwenColorPicker :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS
	};

private:
	
	static int _setColor     ( lua_State* L );
	static int _getColor     ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenColorPicker )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	
	MOAIGwenSystem* mRootSystem;

	inline Gwen::Controls::ColorPicker* GetInternalControl() { 
		return static_cast < Gwen::Controls::ColorPicker* >( this->mControlRef.ref );
	}

	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		this->ConnectEventCallBack( GetInternalControl()->onColorChanged,  EVENT_CHANGE );
	}

  DECL_LUA_FACTORY ( MOAIGwenColorPicker )

	//----------------------------------------------------------------//
						MOAIGwenColorPicker			( Gwen::Controls::Base* control );
						MOAIGwenColorPicker			();
						~MOAIGwenColorPicker			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
