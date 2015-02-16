#ifndef	MOAIGWENCOLLAPSIBLELIST_H
#define	MOAIGWENCOLLAPSIBLELIST_H

#include "moai-gwen/headers.h"
#include "moai-gwen/MOAIGwenScrollControl.h"
#include "Gwen/Controls/CollapsibleList.h"

//================================================================//
// MOAIGwenCollapsibleList
//================================================================//
/**	@lua MOAIGwenCollapsibleList
	@text Box2D joint.
*/
class MOAIGwenCollapsibleList :
	public MOAIGwenScrollControl {
public:
	enum Events{
		EVENT_SELECT = MOAIGwenScrollControl::TOTAL_EVENTS,
		TOTAL_EVENTS,
	};

private:

	static int _addCategory           ( lua_State* L );
	static int _deselectAll           ( lua_State* L );
	static int _getSelection          ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenCollapsibleList )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenScrollControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onSelection, EVENT_SELECT );
	};

public:
		
	inline Gwen::Controls::CollapsibleList* GetInternalControl() { 
		return static_cast < Gwen::Controls::CollapsibleList* >( this->mControlRef.ref );
	};

  DECL_LUA_FACTORY ( MOAIGwenCollapsibleList )
	
	//----------------------------------------------------------------//
						MOAIGwenCollapsibleList			( Gwen::Controls::CollapsibleList* CollapsibleList );
						MOAIGwenCollapsibleList			();
						~MOAIGwenCollapsibleList			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
