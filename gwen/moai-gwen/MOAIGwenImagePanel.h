#ifndef	MOAIGWENIMAGEPANEL_H
#define	MOAIGWENIMAGEPANEL_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/ImagePanel.h"

//================================================================//
// MOAIGwenImagePanel
//================================================================//
/**	@lua MOAIGwenImagePanel
	@text Box2D joint.
*/
class MOAIGwenImagePanel :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	
	static int _setImage( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenImagePanel )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::ImagePanel* GetInternalControl() { 
		return static_cast < Gwen::Controls::ImagePanel* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenImagePanel )
	
	//----------------------------------------------------------------//
						MOAIGwenImagePanel			();
						~MOAIGwenImagePanel			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
