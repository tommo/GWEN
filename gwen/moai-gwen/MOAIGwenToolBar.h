#ifndef	MOAIGWENTOOLBAR_H
#define	MOAIGWENTOOLBAR_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
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

#endif
