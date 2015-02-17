#ifndef	MOAIGWENBUTTON_H
#define	MOAIGWENBUTTON_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/Button.h"

//================================================================//
// MOAIGwenButton
//================================================================//
/**	@lua MOAIGwenButton
	@text Box2D joint.
*/
class MOAIGwenButton :
	public MOAIGwenLabel {
public:
	enum Events{
		EVENT_CLICK = MOAIGwenLabel::TOTAL_EVENTS,
		EVENT_DOWN,
		EVENT_UP,
		EVENT_TOGGLE,
		TOTAL_EVENTS,
	};

private:
	
	static int _isPressed        ( lua_State* L );
	static int _setIsToggle      ( lua_State* L );
	static int _isToggle         ( lua_State* L );
	static int _getToggleState   ( lua_State* L );
	static int _setToggleState   ( lua_State* L );
	static int _setImage         ( lua_State* L );
	static int _setImageAlpha    ( lua_State* L );
	static int _fitContent       ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenLabel::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onPress,  EVENT_CLICK );
		ConnectEventCallBack( GetInternalControl()->onDown,   EVENT_DOWN );
		ConnectEventCallBack( GetInternalControl()->onUp,     EVENT_UP );
		ConnectEventCallBack( GetInternalControl()->onToggle, EVENT_TOGGLE );
	};

public:
		
	inline Gwen::Controls::Button* GetInternalControl() { 
		return static_cast < Gwen::Controls::Button* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenButton )
	
	//----------------------------------------------------------------//
						MOAIGwenButton			();
						~MOAIGwenButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
