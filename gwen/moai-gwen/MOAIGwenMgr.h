#ifndef MOAI_GWEN_SYSTEM_H
#define MOAI_GWEN_SYSTEM_H

#include <moai-core/headers.h>
#include "Gwen/Gwen.h"
#include "Gwen/Controls/Canvas.h"


class MOAIGwenMgr :
	public MOAIGlobalClass< MOAIGwenMgr, MOAILuaObject > {
private:

	// static int		_sendMessage(lua_State* L);
	Gwen::Renderer::Base* mRenderer;
	Gwen::Skin::Base*     mDefaultSkin;
	Gwen::Controls::Canvas*   mDefaultCanvas;

public:

	Gwen::Renderer::Base*     GetRenderer() { return this->mRenderer; };
	Gwen::Controls::Canvas*   GetDefaultCanvas() { return this->mDefaultCanvas; };

	DECL_LUA_SINGLETON ( MOAIGwenMgr )

					MOAIGwenMgr			();
					~MOAIGwenMgr		();
	void			RegisterLuaClass	(MOAILuaState& state);
	void			RegisterLuaFuncs	(MOAILuaState& state);
};

#endif
