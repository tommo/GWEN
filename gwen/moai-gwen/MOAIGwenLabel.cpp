#include "moai-gwen/MOAIGwenLabel.h"
#include "Gwen/Controls/Label.h"


//----------------------------------------------------------------//
int MOAIGwenLabel::_setText(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "US" )
	cc8* text = state.GetValue < cc8* >( 2, "" );
	self->GetInternalControl()->SetText( text );
	return 0;
}


//----------------------------------------------------------------//
int MOAIGwenLabel::_setTextColor(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "UNNN" )
	float r = state.GetValue < float >( 2, 1.0f );
	float g = state.GetValue < float >( 3, 1.0f );
	float b = state.GetValue < float >( 4, 1.0f );
	float a = state.GetValue < float >( 5, 1.0f );
	self->GetInternalControl()->SetTextColor( 
		Gwen::Color(
			r * 255,
			g * 255,
			b * 255,
			a * 255
		)
	);
	return 0;
}

//----------------------------------------------------------------//
int MOAIGwenLabel::_setTextColorOverride(lua_State* L)
{
	MOAI_LUA_SETUP ( MOAIGwenLabel, "UNNN" )
	float r = state.GetValue < float >( 2, 1.0f );
	float g = state.GetValue < float >( 3, 1.0f );
	float b = state.GetValue < float >( 4, 1.0f );
	float a = state.GetValue < float >( 5, 1.0f );
	self->GetInternalControl()->SetTextColorOverride( 
		Gwen::Color(
			r * 255,
			g * 255,
			b * 255,
			a * 255
		)
	);
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
		{ "setText",                 _setText      },
		{ "setTextColor",            _setTextColor },
		{ "setTextColorOverride",    _setTextColorOverride },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}
