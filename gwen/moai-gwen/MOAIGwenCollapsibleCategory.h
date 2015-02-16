#ifndef	MOAIGWENCollapsibleCategory_H
#define	MOAIGWENCollapsibleCategory_H

#include "moai-gwen/headers.h"
#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/CollapsibleCategory.h"

//================================================================//
// MOAIGwenCollapsibleCategory
//================================================================//
/**	@lua MOAIGwenCollapsibleCategory
	@text Box2D joint.
*/
class MOAIGwenCollapsibleCategory :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_SELECT = MOAIGwenControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:

	static int _setText               ( lua_State* L );
	static int _add                   ( lua_State* L );
	static int _deselectAll           ( lua_State* L );
	static int _getSelection          ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenCollapsibleCategory )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onSelection, EVENT_SELECT );
	};

public:
		
	inline Gwen::Controls::CollapsibleCategory* GetInternalControl() { 
		return static_cast < Gwen::Controls::CollapsibleCategory* >( this->mControlRef.ref );
	};

  DECL_LUA_FACTORY ( MOAIGwenCollapsibleCategory )
	
	//----------------------------------------------------------------//
						MOAIGwenCollapsibleCategory			( Gwen::Controls::CollapsibleCategory* CollapsibleCategory );
						MOAIGwenCollapsibleCategory			();
						~MOAIGwenCollapsibleCategory			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
