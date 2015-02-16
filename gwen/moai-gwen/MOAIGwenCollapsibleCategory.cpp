#include "moai-gwen/MOAIGwenCollapsibleCategory.h"
#include "Gwen/Controls/CollapsibleCategory.h"


//----------------------------------------------------------------//
int MOAIGwenCollapsibleCategory::_setText(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenCollapsibleCategory, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetText( text );
	return 0;
}

int MOAIGwenCollapsibleCategory::_add ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCollapsibleCategory, "US" )
	cc8* name = state.GetValue < cc8* >( 2, "" );
	Gwen::Controls::Button* item = self->GetInternalControl()->Add( name );
	MOAIGwenControl* control = _GwenToMoai( item );
	control->PushLuaUserdata( state );
	return 1;
}

int MOAIGwenCollapsibleCategory::_deselectAll(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenCollapsibleCategory, "U" )
	self->GetInternalControl()->UnselectAll();
	return 0;
}


int MOAIGwenCollapsibleCategory::_getSelection ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenCollapsibleCategory, "U" )
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
Gwen::Controls::Base* MOAIGwenCollapsibleCategory::CreateGwenControl() {
	return new Gwen::Controls::CollapsibleCategory( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleCategory::MOAIGwenCollapsibleCategory () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenCollapsibleCategory::~MOAIGwenCollapsibleCategory () {
}

//----------------------------------------------------------------//
void MOAIGwenCollapsibleCategory::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_SELECT",   ( u32 )EVENT_SELECT  );
	luaL_Reg regTable [] = {
		{ "new",		_new },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenCollapsibleCategory::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setText",        _setText      },
		{ "add",            _add          },
		{ "deselectAll",    _deselectAll  },
		{ "getSelection",   _getSelection },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
