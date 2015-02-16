#ifndef	MOAIGWENTreeControl_H
#define	MOAIGWENTreeControl_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenTreeNode.h"
#include "Gwen/Controls/TreeControl.h"

//================================================================//
// MOAIGwenTreeControl
//================================================================//
/**	@lua MOAIGwenTreeControl
	@text Box2D joint.
*/
class MOAIGwenTreeControl :
	public MOAIGwenTreeNode {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenTreeNode::TOTAL_EVENTS
	};

private:
	static int _clear                 ( lua_State* L );
	static int _getScrollControl      ( lua_State* L );
	static int _setAllowMultiSelect   ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenTreeControl )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenTreeNode::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::TreeControl* GetInternalControl() { 
		return static_cast < Gwen::Controls::TreeControl* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenTreeControl )
	
	//----------------------------------------------------------------//
						MOAIGwenTreeControl			();
						~MOAIGwenTreeControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
