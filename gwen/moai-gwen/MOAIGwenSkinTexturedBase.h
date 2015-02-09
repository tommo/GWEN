#ifndef MOAIGWENSKINTEXTUREBASE_H
#define MOAIGWENSKINTEXTUREBASE_H

#include "Gwen/Skins/TexturedBase.h"
#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenSkin.h"

//================================================================//
// MOAIGwenSkinTexturedBase
//================================================================//
/**	@lua MOAIGwenSkinTexturedBase
*/
class MOAIGwenSkinTexturedBase :
	public MOAIGwenSkin {
protected:
	
	static int _init( lua_State* L );

public:
	
	friend class MOAIGwenSystem;
  DECL_LUA_FACTORY ( MOAIGwenSkinTexturedBase )

 	Gwen::Skin::TexturedBase* GetGwenSkin() {
 		return static_cast< Gwen::Skin::TexturedBase* >( this->mGwenSkin );
 	}
	
	//----------------------------------------------------------------//
						MOAIGwenSkinTexturedBase			();
						~MOAIGwenSkinTexturedBase			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
