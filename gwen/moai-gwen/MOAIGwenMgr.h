#ifndef MOAI_GWEN_SYSTEM_H
#define MOAI_GWEN_SYSTEM_H

#include <moai-core/headers.h>
#include <moai-sim/headers.h>
#include "Gwen/Gwen.h"
#include "Gwen/Controls/Canvas.h"


class MOAIGwenMgr :
	public MOAIGlobalClass< MOAIGwenMgr, MOAILuaObject > {
private:

	static int		_setTextureLoader       ( lua_State* L );
	static int		_registerFont           ( lua_State* L );

	//----------------------------------------------------------------//
	MOAILuaStrongRef mOnLoadTexture;
	MOAILuaStrongRef mOnUnloadTexture;

	MOAILuaStrongRef mOnLoadFont;
	MOAILuaStrongRef mOnUnloadFont;

	Gwen::Renderer::Base* mRenderer;
	Gwen::Skin::Base*     mDefaultSkin;
	Gwen::Controls::Canvas*   mDefaultCanvas;

	typedef STLMap < STLString, MOAIFont* >::iterator FontMapIt;
  STLMap< STLString, MOAIFont* >  mFontMap;


public:

	Gwen::Renderer::Base*     GetRenderer() { return this->mRenderer; };
	Gwen::Controls::Canvas*   GetDefaultCanvas() { return this->mDefaultCanvas; };

	void LoadTexture         ( Gwen::Texture* texture );
	void ReleaseTexture      ( Gwen::Texture* texture );

	void RegisterFont        ( STLString faceName, MOAIFont* font );
	MOAIFont* FindFont       ( STLString faceName, float size = 10.0f );
	MOAIFont* FindFont       ( Gwen::Font* font );

	DECL_LUA_SINGLETON ( MOAIGwenMgr )

					MOAIGwenMgr			();
					~MOAIGwenMgr		();
	void			RegisterLuaClass	(MOAILuaState& state);
	void			RegisterLuaFuncs	(MOAILuaState& state);
};

#endif
