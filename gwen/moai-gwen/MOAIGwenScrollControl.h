#ifndef	MOAIGWENSCROLLCONTROL_H
#define	MOAIGWENSCROLLCONTROL_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/ScrollControl.h"

class MOAIGwenSystem;
//================================================================//
// MOAIGwenScrollControl
//================================================================//
/**	@lua MOAIGwenScrollControl
	@text Box2D joint.
*/
class MOAIGwenScrollControl :
	public MOAIGwenControl {
private:
	
	static int _setScrollEnabled        ( lua_State* L );
	static int _isScrollEnabled         ( lua_State* L );
	static int _setAutoHideScrollBars   ( lua_State* L );
	static int _setAlwaysShowScrollBars ( lua_State* L );
	static int _setInnerSize            ( lua_State* L );
	static int _scrollToTop             ( lua_State* L );
	static int _scrollToBottom          ( lua_State* L );
	static int _scrollToLeft            ( lua_State* L );
	static int _scrollToRight           ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenScrollControl )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	
	MOAIGwenSystem* mRootSystem;

	inline Gwen::Controls::ScrollControl* GetInternalControl() { 
		return static_cast < Gwen::Controls::ScrollControl* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenScrollControl )

	//----------------------------------------------------------------//
						MOAIGwenScrollControl			( Gwen::Controls::Base* control );
						MOAIGwenScrollControl			();
						~MOAIGwenScrollControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
