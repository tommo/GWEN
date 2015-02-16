#ifndef	MOAIGWENScrollBar_H
#define	MOAIGWENScrollBar_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/ScrollBar.h"
#include "Gwen/Controls/VerticalScrollBar.h"
#include "Gwen/Controls/HorizontalScrollBar.h"

//================================================================//
// MOAIGwenBaseScrollBar
//================================================================//
/**	@lua MOAIGwenBaseScrollBar
	@text Box2D joint.
*/
class MOAIGwenBaseScrollBar :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_SCROLL = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:
	static int _setScrollSize         ( lua_State* L );
	static int _setPageSize           ( lua_State* L );
	static int _setStepSize           ( lua_State* L );
	static int _getStepSize           ( lua_State* L );
	static int _setValue              ( lua_State* L );
	static int _getValue              ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenBaseScrollBar )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onBarMoved,  EVENT_SCROLL );
	};

public:
		
	inline Gwen::Controls::BaseScrollBar* GetInternalControl() { 
		return static_cast < Gwen::Controls::BaseScrollBar* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenBaseScrollBar )
	
	//----------------------------------------------------------------//
						MOAIGwenBaseScrollBar			();
						~MOAIGwenBaseScrollBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//----------------------------------------------------------------//
//Vertical
//----------------------------------------------------------------//
class MOAIGwenVerticalScrollBar :
	public MOAIGwenBaseScrollBar {
private:
	static int _scrollToTop        ( lua_State* L );
	static int _scrollToBottom     ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenVerticalScrollBar )
	virtual Gwen::Controls::Base* CreateGwenControl();
public:
		
	inline Gwen::Controls::VerticalScrollBar* GetInternalControl() { 
		return static_cast < Gwen::Controls::VerticalScrollBar* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenVerticalScrollBar )
	
	//----------------------------------------------------------------//
						MOAIGwenVerticalScrollBar			();
						~MOAIGwenVerticalScrollBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

//----------------------------------------------------------------//
//Vertical
//----------------------------------------------------------------//
class MOAIGwenHorizontalScrollBar :
	public MOAIGwenBaseScrollBar {
private:
	static int _scrollToLeft       ( lua_State* L );
	static int _scrollToRight      ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenHorizontalScrollBar )
	virtual Gwen::Controls::Base* CreateGwenControl();
public:
		
	inline Gwen::Controls::HorizontalScrollBar* GetInternalControl() { 
		return static_cast < Gwen::Controls::HorizontalScrollBar* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenHorizontalScrollBar )
	
	//----------------------------------------------------------------//
						MOAIGwenHorizontalScrollBar			();
						~MOAIGwenHorizontalScrollBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
