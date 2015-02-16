#include "moai-gwen/MOAIGwenTreeNode.h"
#include "Gwen/Controls/TreeNode.h"


int MOAIGwenTreeNode::_addNode ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTreeNode, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::TreeNode* node = self->GetInternalControl()->AddNode( text );
	PushGwenControl( state, node );
	return 1;
}

int MOAIGwenTreeNode::_getChildNodes( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )

	lua_newtable( L );

	u32 count = 1;
	Gwen::Controls::Base::List & children = self->GetInternalControl()->GetChildNodes();
	for ( Gwen::Controls::Base::List::iterator iter = children.begin(); iter != children.end(); ++iter )
	{
		Gwen::Controls::Base* child = *iter ;
		lua_pushnumber ( state, count );
		PushGwenControl( state, child );
		lua_settable( L, -3 );
		++count;
	}
	return 1;
}


int MOAIGwenTreeNode::_getText ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenTreeNode, "U" )
	const Gwen::TextObject& text = self->GetInternalControl()->GetText();
	lua_pushstring( state, text.c_str() );
	return 1;
}


int MOAIGwenTreeNode::_setText(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetText( text );
	return 0;
}

int MOAIGwenTreeNode::_setImage(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "US" )
	cc8* image = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetImage( image );
	return 0;
}

int MOAIGwenTreeNode::_expand(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	self->GetInternalControl()->Open();
	return 0;
}

int MOAIGwenTreeNode::_collapse(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	self->GetInternalControl()->Close();
	return 0;
}

int MOAIGwenTreeNode::_expandAll(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	self->GetInternalControl()->ExpandAll();
	return 0;
}

int MOAIGwenTreeNode::_isSelected(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	state.Push( self->GetInternalControl()->IsSelected() );
	return 1;
}

int MOAIGwenTreeNode::_setSelected(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	bool selected = state.GetValue < bool >( 2, true );
	bool notify   = state.GetValue < bool >( 3, true );
	self->GetInternalControl()->SetSelected( selected, notify );
	return 0;
}


int MOAIGwenTreeNode::_setSelectable(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	bool selectable = state.GetValue < bool >( 2, true );
	self->GetInternalControl()->SetSelectable( selectable );
	return 0;
}

int MOAIGwenTreeNode::_deselectAll(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	self->GetInternalControl()->DeselectAll();
	return 0;
}

int MOAIGwenTreeNode::_getTitleButton(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenTreeNode, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetButton() );
	return 1;
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenTreeNode::CreateGwenControl() {
	return new Gwen::Controls::TreeNode( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenTreeNode::MOAIGwenTreeNode () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenTreeNode::~MOAIGwenTreeNode () {
}

//----------------------------------------------------------------//
void MOAIGwenTreeNode::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );

	state.SetField ( -1, "EVENT_SELECT_CHANGE",  ( u32 )EVENT_SELECT_CHANGE );
	state.SetField ( -1, "EVENT_SELECT",         ( u32 )EVENT_SELECT        );
	state.SetField ( -1, "EVENT_DESELECT",       ( u32 )EVENT_DESELECT      );

	luaL_Reg regTable [] = {
		{ "new",		_new },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenTreeNode::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "addNode",        _addNode        },
		{ "getChildNodes",  _getChildNodes  },
		{ "setText",        _setText        },
		{ "getText",        _getText        },
		{ "setImage",       _setImage       },
		{ "collapse",       _collapse       },
		{ "expand",         _expand         },
		{ "expandAll",      _expandAll      },
		{ "setSelectable",  _setSelectable  },
		{ "isSelected",     _isSelected     },
		{ "setSelected",    _setSelected    },
		{ "deselectAll",    _deselectAll    },
		{ "getTitleButton", _getTitleButton },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
