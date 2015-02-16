#ifndef	MOAIGwenVerticalSplitter_H
#define	MOAIGwenVerticalSplitter_H

#include "moai-gwen/headers.h"

#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Splitters.h"

//================================================================//
// MOAIGwenVerticalSplitter
//================================================================//
/**	@lua MOAIGwenVerticalSplitter
	@text Box2D joint.
*/
class MOAIGwenVerticalSplitter :
	public MOAIGwenControl {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenControl::TOTAL_EVENTS
	};

private:
	static int _setPanels             ( lua_State* L );
	static int _setScaling            ( lua_State* L );
	static int _getSplitterPos        ( lua_State* L );
		
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenVerticalSplitter )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::SplitterVertical* GetInternalControl() { 
		return static_cast < Gwen::Controls::SplitterVertical* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenVerticalSplitter )
	
	//----------------------------------------------------------------//
						MOAIGwenVerticalSplitter			();
						~MOAIGwenVerticalSplitter			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};


//----------------------------------------------------------------//
//----------------------------------------------------------------//
class MOAIGwenHorizontalSplitter :
	public MOAIGwenVerticalSplitter {
public:
	enum Events{
		TOTAL_EVENTS = MOAIGwenVerticalSplitter::TOTAL_EVENTS
	};
private:
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenHorizontalSplitter )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenVerticalSplitter::ConnectEvents();
	};

public:
		
	inline Gwen::Controls::SplitterHorizontal* GetInternalControl() { 
		return static_cast < Gwen::Controls::SplitterHorizontal* >( this->mControlRef.ref );
	}

  DECL_LUA_FACTORY ( MOAIGwenHorizontalSplitter )
	
	//----------------------------------------------------------------//
						MOAIGwenHorizontalSplitter			();
						~MOAIGwenHorizontalSplitter			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};
#endif
