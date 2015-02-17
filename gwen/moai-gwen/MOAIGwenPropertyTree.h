#ifndef	MOAIGWENPROPERTYTREE_H
#define	MOAIGWENPROPERTYTREE_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenTreeControl.h"
#include "Gwen/Controls/Properties.h"
#include "Gwen/Controls/PropertyTree.h"

//================================================================//
// MOAIGwenPropertyTree
//================================================================//
/**	@lua MOAIGwenPropertyTree
	@text Box2D joint.
*/
class MOAIGwenPropertyTree :
	public MOAIGwenTreeControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenTreeControl::TOTAL_EVENTS,
	};

private:
	static int _addCategory     ( lua_State* L );
	static int _findCategory    ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenPropertyTree )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenTreeControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::PropertyTree* GetInternalControl() { 
		return static_cast < Gwen::Controls::PropertyTree* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenPropertyTree )
	
	//----------------------------------------------------------------//
						MOAIGwenPropertyTree			();
						~MOAIGwenPropertyTree			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
