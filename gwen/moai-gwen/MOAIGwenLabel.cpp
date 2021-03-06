#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/Label.h"

int MOAIGwenLabel::_getText ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenLabel, "U" )
	const Gwen::TextObject& text = self->GetInternalControl()->GetText();
	lua_pushstring( state, text.c_str() );
	return 1;
}

//----------------------------------------------------------------//
int MOAIGwenLabel::_setText(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetText( text );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenLabel::_setFont(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "USN" )
	cc8* face = state.GetValue < cc8* >( 2, "" );
	u32 size  = state.GetValue < u32 >( 3, 12 );

	self->GetInternalControl()->SetFont( face, size, false );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenLabel::_setTextColor(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "UNNN" )
	Gwen::Color c1 = PullGwenColor( state, 2 );
	self->GetInternalControl()->SetTextColor( c1 );
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenLabel::_setTextColorOverride(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "UNNN" )
	Gwen::Color c1 = PullGwenColor( state, 2 );
	self->GetInternalControl()->SetTextColorOverride( c1 );
	return 0;
}
//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenLabel::CreateGwenControl() {
	return new Gwen::Controls::Label( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenLabel::MOAIGwenLabel () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END
}

//----------------------------------------------------------------//
MOAIGwenLabel::~MOAIGwenLabel () {
}

//----------------------------------------------------------------//
void MOAIGwenLabel::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	luaL_Reg regTable [] = {
		{ "new",		_new },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenLabel::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "setFont",                 _setFont      },
		{ "getText",                 _getText      },
		{ "setText",                 _setText      },
		{ "setTextColor",            _setTextColor },
		{ "setTextColorOverride",    _setTextColorOverride },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
