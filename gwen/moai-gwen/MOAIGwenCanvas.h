#ifndef	MOAIGWENCANVAS_H
#define	MOAIGWENCANVAS_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"

//================================================================//
// MOAIGwenCanvas
//================================================================//
/**	@lua MOAIGwenCanvas
	@text Box2D joint.
*/
class MOAIGwenCanvas :
	public MOAIGwenControl {
private:
	//----------------------------------------------------------------//
	
public:
		
  DECL_LUA_FACTORY ( MOAIGwenCanvas )
	
	//----------------------------------------------------------------//
						MOAIGwenCanvas			();
						~MOAIGwenCanvas			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
