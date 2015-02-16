#include "moai-gwen/MOAIGwenCollapsibleList.h"
#include "Gwen/Controls/CollapsibleList.h"


//----------------------------------------------------------------//
int MOAIGwenCollapsibleList::_addCategory ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCollapsibleList, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::CollapsibleCategory* category = self->GetInternalControl()->Add( name );
	MOAIGwenControl* control = _GwenToMoai( category );
	control->PushLuaUserdata( state );
	return 1;
}

int MOAIGwenCollapsibleList::_deselectAll(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenCollapsibleList, "U" )
	self->GetInternalControl()->UnselectAll();
	return 0;
}

int MOAIGwenCollapsibleList::_getSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCollapsibleList, "U" )
	Gwen::Controls::Button* selected = self->GetInternalControl()->GetSelected();
	MOAIGwenControl* control = _GwenToMoai( selected );
	if( control ) {
		control->PushLuaUserdata( state );
		return 1;
	} else {
		lua_pushnil( state );
		return 1;
	}
}

//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenCollapsibleList::CreateGwenControl() {
	return new Gwen::Controls::CollapsibleList( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleList::MOAIGwenCollapsibleList () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenScrollControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleList::~MOAIGwenCollapsibleList () {
}

//----------------------------------------------------------------//
void MOAIGwenCollapsibleList::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_SELECT",   ( u32 )EVENT_SELECT  );
	luaL_Reg regTable [] = {
		{ "new",		_new },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenCollapsibleList::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenScrollControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "addCategory",  _addCategory  },
		{ "deselectAll",  _deselectAll  },
		{ "getSelection", _getSelection },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
