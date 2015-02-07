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

	static int    _getName              ( lua_State* L );
	static int    _setName              ( lua_State* L );

	static int    _getParent            ( lua_State* L );
	static int    _setParent            ( lua_State* L );
	static int    _addChild             ( lua_State* L );
	static int    _getChildren          ( lua_State* L );
	static int    _getChildrenCount     ( lua_State* L );
	static int    _findChildByName      ( lua_State* L );
	static int    _removeAllChildren      ( lua_State* L );

	static int    _sendToBack           ( lua_State* L );
	static int    _bringToFront         ( lua_State* L );
	static int    _bringNextToControl   ( lua_State* L );

	static int    _fitChildren          ( lua_State* L );
	static int    _getChildrenSize      ( lua_State* L );

	static int    _restrictToParent      ( lua_State* L );
	static int    _shouldRestrictToParent ( lua_State* L );

	static int    _getSize              ( lua_State* L );
	static int    _setSize              ( lua_State* L );
	static int    _getPos               ( lua_State* L );
	static int    _setPos               ( lua_State* L );
	static int    _getBounds            ( lua_State* L );
	static int    _getInnerBounds       ( lua_State* L );
	static int    _getRenderBounds      ( lua_State* L );

	static int    _getControlAt         ( lua_State* L );

	static int    _setPadding           ( lua_State* L );
	static int    _setMargin            ( lua_State* L );

	static int    _isVisible            ( lua_State* L );
	static int    _isLocalVisible       ( lua_State* L );
	static int    _setVisible           ( lua_State* L );
	static int    _show                 ( lua_State* L );
	static int    _hide                 ( lua_State* L );

	static int    _isDisabled           ( lua_State* L );
	static int    _setDisabled          ( lua_State* L );
	static int    _enable               ( lua_State* L );
	static int    _disable              ( lua_State* L );

	static int    _hasFocus             ( lua_State* L );
	static int    _setFocus             ( lua_State* L );
	static int    _focus                ( lua_State* L );
	static int    _blur                 ( lua_State* L );

	static int    _isOnTop              ( lua_State* L );
	static int    _isHovered            ( lua_State* L );
	static int    _isTabable            ( lua_State* L );
	static int    _setTabable           ( lua_State* L );

	static int    _moveTo               ( lua_State* L );
	static int    _moveBy               ( lua_State* L );

	static int    _setDock              ( lua_State* L );
	static int    _getDock              ( lua_State* L );

	static int    _isValid              ( lua_State* L );

	static int    _getTypeName          ( lua_State* L );

	static int    _isMenuComponent      ( lua_State* L );
	static int    _closeMenus           ( lua_State* L );
	static int    _setToolTip           ( lua_State* L );

	static int    _invalidate           ( lua_State* L );
	static int    _invalidateChildren   ( lua_State* L );
	static int    _invalidateParent     ( lua_State* L );

protected:

	ControlRef mControlRef;

	MOAILuaSharedPtr < MOAIGwenSkin > mSkin;
	//----------------------------------------------------------------//
	void    SetInternalControl( Gwen::Controls::Base* control ) {
		control->SetExternalRef( &this->mControlRef );
	};

	virtual Gwen::Controls::Base* CreateGwenControl();

public:
	MOAIGwenControl* Init() {
		return this->Init( this->CreateGwenControl() );
	}
	
	MOAIGwenControl* Init( Gwen::Controls::Base* control ) {
		this->SetInternalControl( control );
		return this;
	}
	
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

//----------------------------------------------------------------//
	static MOAIGwenControl* _GwenToMoai( Gwen::Controls::Base* control );
	static bool PushGwenControl( MOAILuaState& state, Gwen::Controls::Base* control ) {
		MOAIGwenControl* control1 = _GwenToMoai( control );
		if( control1 ){
			control1->PushLuaUserdata( state );
			return true;
		}
		return false;
	}

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
