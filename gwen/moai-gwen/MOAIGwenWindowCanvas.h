#ifndef	MOAIGwenWindowCanvas_H
#define	MOAIGwenWindowCanvas_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenCanvas.h"
#include "Gwen/Controls/WindowCanvas.h"

//================================================================//
// MOAIGwenWindowCanvas
//================================================================//
/**	@lua MOAIGwenWindowCanvas
	@text Box2D joint.
*/
class MOAIGwenWindowCanvas :
	public MOAIGwenCanvas {
private:
	//----------------------------------------------------------------//
	
public:
		
  DECL_LUA_FACTORY ( MOAIGwenWindowCanvas )
	
	//----------------------------------------------------------------//
						MOAIGwenWindowCanvas			();
						~MOAIGwenWindowCanvas			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
