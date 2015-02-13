#ifndef MOAI_GWEN_SYSTEM_H
#define MOAI_GWEN_SYSTEM_H

#include <moai-core/headers.h>
#include "Gwen/Gwen.h"
#include "Gwen/Controls/Canvas.h"


class MOAIGwenMgr :
	public MOAIGlobalClass< MOAIGwenMgr, MOAILuaObject > {
private:

	static int		_setTextureLoader(lua_State* L);

	//----------------------------------------------------------------//
	MOAILuaStrongRef mOnLoadTexture;
	MOAILuaStrongRef mOnUnloadTexture;

	Gwen::Renderer::Base* mRenderer;
	Gwen::Skin::Base*     mDefaultSkin;
	Gwen::Controls::Canvas*   mDefaultCanvas;

public:

	Gwen::Renderer::Base*     GetRenderer() { return this->mRenderer; };
	Gwen::Controls::Canvas*   GetDefaultCanvas() { return this->mDefaultCanvas; };

	void LoadTexture         ( Gwen::Texture* texture );
	void ReleaseTexture      ( Gwen::Texture* texture );
	void LoadFont            ( Gwen::Font* font );
	void ReleaseFont         ( Gwen::Font* font );

	DECL_LUA_SINGLETON ( MOAIGwenMgr )

					MOAIGwenMgr			();
					~MOAIGwenMgr		();
	void			RegisterLuaClass	(MOAILuaState& state);
	void			RegisterLuaFuncs	(MOAILuaState& state);
};

#endif
