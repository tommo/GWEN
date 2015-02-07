#ifndef	MOAIGWENWINDOWCONTROL_H
#define	MOAIGWENWINDOWCONTROL_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/WindowControl.h"

//================================================================//
// MOAIGwenWindowControl
//================================================================//
/**	@lua MOAIGwenWindowControl
	@text Box2D joint.
*/
class MOAIGwenWindowControl :
	public MOAIGwenControl {
private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW ( MOAIGwenWindowControl )
	virtual Gwen::Controls::Base* CreateGwenControl();
	
public:
		
  DECL_LUA_FACTORY ( MOAIGwenWindowControl )
	
	//----------------------------------------------------------------//
						MOAIGwenWindowControl			();
						~MOAIGwenWindowControl			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
