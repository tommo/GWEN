#ifndef	MOAIGWENLAYOUTTile_H
#define	MOAIGWENLAYOUTTile_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Layout/Tile.h"

//================================================================//
// MOAIGwenLayoutTile
//================================================================//
/**	@lua MOAIGwenLayoutTile
	@text Box2D joint.
*/
class MOAIGwenLayoutTile :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _setTileSize         ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLayoutTile )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::Layout::Tile* GetInternalControl() { 
		return static_cast < Gwen::Controls::Layout::Tile* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenLayoutTile )
	
	//----------------------------------------------------------------//
						MOAIGwenLayoutTile			();
						~MOAIGwenLayoutTile			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
