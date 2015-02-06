#ifndef	MOAIGWENLABEL_H
#define	MOAIGWENLABEL_H

#include "moai-gwen/headers.h"
#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Label.h"

//================================================================//
// MOAIGwenLabel
//================================================================//
/**	@lua MOAIGwenLabel
	@text Box2D joint.
*/
class MOAIGwenLabel :
	public MOAIGwenControl {
private:
	//----------------------------------------------------------------//
public:
		
  DECL_LUA_FACTORY ( MOAIGwenLabel )
	
	//----------------------------------------------------------------//
						MOAIGwenLabel			( Gwen::Controls::Label* label );
						MOAIGwenLabel			();
						~MOAIGwenLabel			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
