#ifndef	MOAIGWENLABEL_H
#define	MOAIGWENLABEL_H

#include "moai-gwen/headers.h"
#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/Label.h"

//================================================================//
// MOAIGwenLabel
//================================================================//
/**	@lua MOAIGwenLabel
	@text Box2D joint.
*/
class MOAIGwenLabel :
	public MOAIGwenControl {
private:

	static int _setText                  ( lua_State* L );
	static int _setTextColor             ( lua_State* L );
	static int _setTextColorOverride     ( lua_State* L );
	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenLabel )
	virtual Gwen::Controls::Base* CreateGwenControl();

public:
		
	inline Gwen::Controls::Label* GetInternalControl() { 
		return static_cast < Gwen::Controls::Label* >( this->mControlRef.ref );
	};

  DECL_LUA_FACTORY ( MOAIGwenLabel )
	
	//----------------------------------------------------------------//
						MOAIGwenLabel			( Gwen::Controls::Label* label );
						MOAIGwenLabel			();
						~MOAIGwenLabel			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
