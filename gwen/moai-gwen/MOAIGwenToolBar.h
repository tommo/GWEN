#ifndef	MOAIGWENTOOLBAR_H
#define	MOAIGWENTOOLBAR_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "moai-gwen/MOAIGwenButton.h"
#include "Gwen/Controls/Button.h"
#include "Gwen/Controls/ToolBar.h"

//================================================================//
// MOAIGwenToolBar
//================================================================//
/**	@lua MOAIGwenToolBar
	@text Box2D joint.
*/
class MOAIGwenToolBar :
	public MOAIGwenControl {
private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenToolBar )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	
	inline Gwen::Controls::ToolBarStrip* GetInternalControl() { 
		return static_cast < Gwen::Controls::ToolBarStrip* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenToolBar )

	//----------------------------------------------------------------//
						MOAIGwenToolBar			( Gwen::Controls::Base* control );
						MOAIGwenToolBar			();
						~MOAIGwenToolBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//----------------------------------------------------------------//
//----------------------------------------------------------------//
class MOAIGwenToolButton :
	public MOAIGwenButton {
private:
	
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenToolButton )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	
	inline Gwen::Controls::ToolBarButton* GetInternalControl() { 
		return static_cast < Gwen::Controls::ToolBarButton* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenToolButton )

	//----------------------------------------------------------------//
						MOAIGwenToolButton			( Gwen::Controls::Base* control );
						MOAIGwenToolButton			();
						~MOAIGwenToolButton			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};
#endif
