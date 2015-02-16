#ifndef	MOAIGWENSLIDER_H
#define	MOAIGWENSLIDER_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Slider.h"
#include "Gwen/Controls/VerticalSlider.h"
#include "Gwen/Controls/HorizontalSlider.h"

//================================================================//
// MOAIGwenBaseSlider
//================================================================//
/**	@lua MOAIGwenBaseSlider
	@text Box2D joint.
*/
class MOAIGwenBaseSlider :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:
	static int _getRange              ( lua_State* L );
	static int _setRange              ( lua_State* L );
	static int _setNotchCount         ( lua_State* L );
	static int _getNotchCount         ( lua_State* L );
	static int _setSnapToNotch        ( lua_State* L );
	static int _getValue              ( lua_State* L );
	static int _setValue              ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenBaseSlider )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onValueChanged,  EVENT_CHANGE );
	};

public:
		
	inline Gwen::Controls::Slider* GetInternalControl() { 
		return static_cast < Gwen::Controls::Slider* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenBaseSlider )
	
	//----------------------------------------------------------------//
						MOAIGwenBaseSlider			();
						~MOAIGwenBaseSlider			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//----------------------------------------------------------------//
//Vertical
//----------------------------------------------------------------//
class MOAIGwenVerticalSlider :
	public MOAIGwenBaseSlider {
private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenVerticalSlider )
	virtual Gwen::Controls::Base* CreateGwenControl();
public:
		
	inline Gwen::Controls::VerticalSlider* GetInternalControl() { 
		return static_cast < Gwen::Controls::VerticalSlider* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenVerticalSlider )
	
	//----------------------------------------------------------------//
						MOAIGwenVerticalSlider			();
						~MOAIGwenVerticalSlider			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

//----------------------------------------------------------------//
//Vertical
//----------------------------------------------------------------//
class MOAIGwenHorizontalSlider :
	public MOAIGwenBaseSlider {
private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenHorizontalSlider )
	virtual Gwen::Controls::Base* CreateGwenControl();
public:
		
	inline Gwen::Controls::HorizontalSlider* GetInternalControl() { 
		return static_cast < Gwen::Controls::HorizontalSlider* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenHorizontalSlider )
	
	//----------------------------------------------------------------//
						MOAIGwenHorizontalSlider			();
						~MOAIGwenHorizontalSlider			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
