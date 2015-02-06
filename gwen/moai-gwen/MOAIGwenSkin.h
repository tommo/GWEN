#ifndef MOAIGWENSKIN_H
#define MOAIGWENSKIN_H

#include "Gwen/Gwen.h"
#include "Gwen/Skin.h"
#include "moai-gwen/headers.h"

class MOAIGwenSystem;
class MOAIGwenControl;

//================================================================//
// MOAIGwenSkin
//================================================================//
/**	@lua MOAIGwenSkin
	@text Box2D joint.
*/
class MOAIGwenSkin :
	public MOAILuaObject {
protected:
	friend class MOAIGwenSystem;
	friend class MOAIGwenControl;
	
	Gwen::Skin::Base*	mGwenSkin;

	//----------------------------------------------------------------//
	
public:
	
	Gwen::Skin::Base*	GetGwenSkin() { return mGwenSkin; };

  DECL_LUA_FACTORY ( MOAIGwenSkin )
	
	//----------------------------------------------------------------//
						MOAIGwenSkin			();
						~MOAIGwenSkin			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
