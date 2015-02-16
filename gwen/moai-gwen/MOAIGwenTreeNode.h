#ifndef	MOAIGWENTreeNode_H
#define	MOAIGWENTreeNode_H

#include "moai-gwen/headers.h"
#include "moai-gwen/MOAIGwenControl.h"
#include "Gwen/Controls/TreeNode.h"

//================================================================//
// MOAIGwenTreeNode
//================================================================//
/**	@lua MOAIGwenTreeNode
	@text Box2D joint.
*/
class MOAIGwenTreeNode :
	public MOAIGwenControl {
public:
	enum Events{
		EVENT_SELECT_CHANGE = MOAIGwenControl::TOTAL_EVENTS,
		EVENT_SELECT,
		EVENT_DESELECT,
		TOTAL_EVENTS,
	};
private:

	static int _addNode          ( lua_State* L );
	static int _getChildNodes    ( lua_State* L );
	static int _setText          ( lua_State* L );
	static int _getText          ( lua_State* L );
	static int _setImage         ( lua_State* L );
	static int _collapse         ( lua_State* L );
	static int _expand           ( lua_State* L );
	static int _expandAll        ( lua_State* L );
	static int _setSelectable    ( lua_State* L );
	static int _isSelected       ( lua_State* L );
	static int _setSelected      ( lua_State* L );
	static int _deselectAll      ( lua_State* L );
	static int _getTitleButton   ( lua_State* L );

	//----------------------------------------------------------------//
	MOAI_GWEN_NEW( MOAIGwenTreeNode )
	virtual Gwen::Controls::Base* CreateGwenControl();

protected:
	virtual void ConnectEvents() {
		MOAIGwenControl::ConnectEvents();
		ConnectEventCallBack( GetInternalControl()->onSelectChange,  EVENT_SELECT_CHANGE );
		ConnectEventCallBack( GetInternalControl()->onSelect,        EVENT_SELECT );
		ConnectEventCallBack( GetInternalControl()->onUnselect,      EVENT_DESELECT );
	};

public:
		
	inline Gwen::Controls::TreeNode* GetInternalControl() { 
		return static_cast < Gwen::Controls::TreeNode* >( this->mControlRef.ref );
	};

  DECL_LUA_FACTORY ( MOAIGwenTreeNode )
	
	//----------------------------------------------------------------//
						MOAIGwenTreeNode			( Gwen::Controls::TreeNode* TreeNode );
						MOAIGwenTreeNode			();
						~MOAIGwenTreeNode			();
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
