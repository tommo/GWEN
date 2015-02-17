#ifndef	MOAIGWENPageControl_H
#define	MOAIGWENPageControl_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/PageControl.h"

//================================================================//
// MOAIGwenPageControl
//================================================================//
/**	@lua MOAIGwenPageControl
	@text Box2D joint.
*/
class MOAIGwenPageControl :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_PAGE_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_FINISH,
		TOTAL_EVENTS
	};

private:
	static int _getPageCount          ( lua_State* L );
	static int _setPageCount          ( lua_State* L );
	static int _showPage              ( lua_State* L );
	static int _getPageNumber         ( lua_State* L );
	static int _getPage               ( lua_State* L );
	static int _getCurrentPage        ( lua_State* L );
	static int _nextPage              ( lua_State* L );
	static int _previousPage          ( lua_State* L );
	static int _finish                ( lua_State* L );
	static int _getNextButton         ( lua_State* L );
	static int _getBackButton         ( lua_State* L );
	static int _getFinishButton       ( lua_State* L );
	static int _getLabel              ( lua_State* L );
	static int _useFinishButton       ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenPageControl )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onPageChanged,   EVENT_PAGE_CHANGE );
		ConnectEventCallBack( GetInternalControl()->onFinish,        EVENT_FINISH      );
	};

public:
		
	inline Gwen::Controls::PageControl* GetInternalControl() { 
		return static_cast < Gwen::Controls::PageControl* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenPageControl )
	
	//----------------------------------------------------------------//
						MOAIGwenPageControl			();
						~MOAIGwenPageControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
