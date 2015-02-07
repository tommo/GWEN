#ifndef	MOAIGWENBUTTON_H
#define	MOAIGWENBUTTON_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"

//================================================================//
// MOAIGwenButton
//================================================================//
/**	@lua MOAIGwenButton
	@text Box2D joint.
*/
class MOAIGwenButton :
	public MOAIGwenControl {
private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
		
  DECL_LUA_FACTORY ( MOAIGwenButton )
	
	//----------------------------------------------------------------//
						MOAIGwenButton			();
						~MOAIGwenButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
