#ifndef	MOAIGWENProgressBar_H
#define	MOAIGWENProgressBar_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/ProgressBar.h"

//================================================================//
// MOAIGwenProgressBar
//================================================================//
/**	@lua MOAIGwenProgressBar
	@text Box2D joint.
*/
class MOAIGwenProgressBar :
	public MOAIGwenLabel {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenLabel::TOTAL_EVENTS,
	};

private:
	
	static int _setHorizontal           ( lua_State* L );
	static int _setVertical             ( lua_State* L );
	static int _setValue                ( lua_State* L );
	static int _getValue                ( lua_State* L );
	static int _setAutoLabel            ( lua_State* L );
	static int _setCycleSpeed           ( lua_State* L );
	static int _getCycleSpeed           ( lua_State* L );
	static int _updateCycle             ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenProgressBar )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenLabel::ConnectEvents();
	};

public:
	
	inline Gwen::Controls::ProgressBar* GetInternalControl() { 
		return static_cast < Gwen::Controls::ProgressBar* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenProgressBar )
	
	//----------------------------------------------------------------//
						MOAIGwenProgressBar			();
						~MOAIGwenProgressBar			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
