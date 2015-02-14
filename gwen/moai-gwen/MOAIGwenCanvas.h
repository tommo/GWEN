#ifndef	MOAIGWENCANVAS_H
#define	MOAIGWENCANVAS_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Canvas.h"

class MOAIGwenSystem;
//================================================================//
// MOAIGwenCanvas
//================================================================//
/**	@lua MOAIGwenCanvas
	@text Box2D joint.
*/
class MOAIGwenCanvas :
	public MOAIGwenControl {
private:
	
	static int _setScale     ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenCanvas )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	
	MOAIGwenSystem* mRootSystem;

	inline Gwen::Controls::Canvas* GetInternalControl() { 
		return static_cast < Gwen::Controls::Canvas* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenCanvas )

	//----------------------------------------------------------------//
						MOAIGwenCanvas			( Gwen::Controls::Base* control );
						MOAIGwenCanvas			();
						~MOAIGwenCanvas			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
