#ifndef MOAIGWENSYSTEM_H
#define MOAIGWENSYSTEM_H


#include <moai-gwen/headers.h>

#include <moai-sim/MOAIAction.h>
#include <moai-sim/MOAIGraphicsProp.h>

#include "Gwen/Controls/Base.h"

class MOAIGwenCanvas;
class MOAIGwenSkin;

class MOAIGwenSystem :
	public MOAIGraphicsProp,
	public MOAIAction {
private:
	
	static int    _setSkin                 ( lua_State* L );
	static int    _sendKeyEvent            ( lua_State* L );
	static int    _sendMouseWheelEvent     ( lua_State* L );
	static int    _sendMouseMoveEvent      ( lua_State* L );
	static int    _sendMouseButtonEvent    ( lua_State* L );

	static int    _getCanvas         ( lua_State* L );


	//----------------------------------------------------------------//
	u32						OnGetModelBounds		( ZLBox& bounds );
	void					OnUpdate				( float step );

	//----------------------------------------------------------------//
	MOAILuaSharedPtr < MOAIGwenCanvas >  mCanvas;
	MOAILuaSharedPtr < MOAIGwenSkin >    mSkin;


public:
	Gwen::Controls::Canvas* GetGwenCanvs(); 

	void			Draw					( int subPrimID, float lod );
	bool			IsDone					();

	void    SetSkin    ( MOAIGwenSkin* skin );

	DECL_LUA_FACTORY ( MOAIGwenSystem )
	MOAIGwenSystem();
	~MOAIGwenSystem();

	void			RegisterLuaClass		( MOAILuaState& state );
	void			RegisterLuaFuncs		( MOAILuaState& state );
	
	/* data */
};

#endif
