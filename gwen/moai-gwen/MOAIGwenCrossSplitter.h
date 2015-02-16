#ifndef	MOAIGWENCrossSplitter_H
#define	MOAIGWENCrossSplitter_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/CrossSplitter.h"

//================================================================//
// MOAIGwenCrossSplitter
//================================================================//
/**	@lua MOAIGwenCrossSplitter
	@text Box2D joint.
*/
class MOAIGwenCrossSplitter :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_ZOOM_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS
	};

private:
	static int _setPanel              ( lua_State* L );
	static int _getPanel              ( lua_State* L );
	static int _isZoomed              ( lua_State* L );
	static int _zoom                  ( lua_State* L );
	static int _centerSplitter        ( lua_State* L );
	static int _setSplitterSize       ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenCrossSplitter )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onZoomChange,  EVENT_ZOOM_CHANGE );
	};

public:
		
	inline Gwen::Controls::CrossSplitter* GetInternalControl() { 
		return static_cast < Gwen::Controls::CrossSplitter* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenCrossSplitter )
	
	//----------------------------------------------------------------//
						MOAIGwenCrossSplitter			();
						~MOAIGwenCrossSplitter			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
