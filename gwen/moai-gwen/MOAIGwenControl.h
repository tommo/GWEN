#ifndef	MOAIGWENCONTROL_H
#define	MOAIGWENCONTROL_H

#include "Gwen/Controls/Base.h"
#include "moai-gwen/headers.h"

class MOAIGwenSkin;
class MOAIGwenSystem;


//================================================================//
// MOAIGwenControl
//================================================================//
/**	@lua MOAIGwenControl
	@text Box2D joint.
*/

class MOAIGwenControl :
	public MOAILuaObject {
private:

	struct ControlRef : public Gwen::Controls::Base::ExternalRef
	{
		Gwen::Controls::Base*	ref;
		MOAIGwenControl*    owner;
		ControlRef() { ref = NULL; }
		~ControlRef() { if( ref ) ref->SetExternalRef( NULL ); }
		virtual void OnBind( Gwen::Controls::Base* control ) {
			assert( this->ref == NULL );
			owner->Retain();
			this->ref = control;
		}

		virtual void OnDelete( Gwen::Controls::Base* control ) {
			assert( control == this->ref );
			owner->Release();
			this->ref = NULL;
		}
	};

	static int    _setSkin              ( lua_State* L );

	static int    _getParent            ( lua_State* L );
	static int    _setParent            ( lua_State* L );
	static int    _addChild             ( lua_State* L );

	static int    _getChildrenCount     ( lua_State* L );
	// static int    _getChildren          ( lua_State* L );

	static int    _fitChildren          ( lua_State* L );
	static int    _getChildrenSize      ( lua_State* L );

	static int    _getSize              ( lua_State* L );
	static int    _setSize              ( lua_State* L );
	static int    _getPos               ( lua_State* L );
	static int    _setPos               ( lua_State* L );

	static int    _isValid              ( lua_State* L );

	static int    _getTypeName          ( lua_State* L );

protected:

	ControlRef mControlRef;

	MOAILuaSharedPtr < MOAIGwenSkin > mSkin;
	//----------------------------------------------------------------//
	void    SetInternalControl( Gwen::Controls::Base* control ) {
		control->SetExternalRef( &this->mControlRef );
	};

	virtual Gwen::Controls::Base* CreateGwenControl();

	MOAIGwenControl* Init() {
		return this->Init( this->CreateGwenControl() );
	}
	
	MOAIGwenControl* Init( Gwen::Controls::Base* control ) {
		this->SetInternalControl( control );
		return this;
	}

public:
	
	friend class MOAIGwenSystem;
	friend class Gwen::Controls::Base;
	
	inline Gwen::Controls::Base* GetInternalControl() { return this->mControlRef.ref; };
	inline bool IsValid() { return this->mControlRef.ref != NULL ; };

	void    SetSkin    ( MOAIGwenSkin* skin );
	void    AddChild   ( MOAIGwenControl* control );
	void    SetParent  ( MOAIGwenControl* control );

	//----------------------------------------------------------------//
  DECL_LUA_FACTORY ( MOAIGwenControl )
	
						MOAIGwenControl  ();
						~MOAIGwenControl ();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );

static MOAIGwenControl* _GwenToMoai( Gwen::Controls::Base* control );

};


#define MOAI_GWEN_NEW( ThisClass )\
	static int _new ( lua_State* L ) {\
		MOAILuaState state ( L );\
		ThisClass *control = new ThisClass();\
		control->Init();\
		control->PushLuaUserdata( state );\
		return 1;\
	}	
#endif
