#ifndef MOAIGWENSKINSIMPLE_H
#define MOAIGWENSKINSIMPLE_H

#include "Gwen/Skins/Simple.h"
#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenSkin.h"

//================================================================//
// MOAIGwenSkinSimple
//================================================================//
/**	@lua MOAIGwenSkinSimple
*/
class MOAIGwenSkinSimple :
	public MOAIGwenSkin {
protected:
	
public:
	
	friend class MOAIGwenSystem;
  DECL_LUA_FACTORY ( MOAIGwenSkinSimple )
	
	//----------------------------------------------------------------//
						MOAIGwenSkinSimple			();
						~MOAIGwenSkinSimple			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
