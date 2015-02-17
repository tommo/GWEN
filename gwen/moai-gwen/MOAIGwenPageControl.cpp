#include "moai-gwen/MOAIGwenPageControl.h"

int MOAIGwenPageControl::_getPageCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	state.Push( self->GetInternalControl()->GetPageCount() );
	return 1;
}

int MOAIGwenPageControl::_setPageCount ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "UN" )
	u32 count = state.GetValue < u32 >( 2, 1 );
	self->GetInternalControl()->SetPageCount( count );
	return 0;
}

int MOAIGwenPageControl::_showPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	self->GetInternalControl()->ShowPage( id );
	return 0;
}

int MOAIGwenPageControl::_getPageNumber ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	state.Push( self->GetInternalControl()->GetPageNumber() );
	return 1;
}


int MOAIGwenPageControl::_getPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "UN" )
	u32 id = state.GetValue < u32 >( 2, 1 ) - 1;
	PushGwenControlOrNil( state, self->GetInternalControl()->GetPage( id ) );
	return 1;
}

int MOAIGwenPageControl::_getCurrentPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->GetCurrentPage() );
	return 1;
}


int MOAIGwenPageControl::_nextPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	self->GetInternalControl()->NextPage();
	return 0;
}

int MOAIGwenPageControl::_previousPage ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	self->GetInternalControl()->PreviousPage();
	return 0;
}

int MOAIGwenPageControl::_finish ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	self->GetInternalControl()->Finish();
	return 0;
}


int MOAIGwenPageControl::_getNextButton ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->NextButton() );
	return 1;
}

int MOAIGwenPageControl::_getBackButton ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->BackButton() );
	return 1;
}

int MOAIGwenPageControl::_getFinishButton ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->FinishButton() );
	return 1;
}

int MOAIGwenPageControl::_getLabel ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	PushGwenControlOrNil( state, self->GetInternalControl()->Label() );
	return 1;
}

int MOAIGwenPageControl::_useFinishButton ( lua_State *L ) {
	MOAI_LUA_SETUP( MOAIGwenPageControl, "U" )
	self->GetInternalControl()->SetUseFinishButton( state.GetValue < bool >( 2, true ) );
	return 0;
}


//----------------------------------------------------------------//
Gwen::Controls::Base* MOAIGwenPageControl::CreateGwenControl() {
	return new Gwen::Controls::PageControl( MOAIGwenMgr::Get().GetDefaultCanvas() ) ;
}

//----------------------------------------------------------------//
MOAIGwenPageControl::MOAIGwenPageControl () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGwenControl )
	RTTI_END	
}

//----------------------------------------------------------------//
MOAIGwenPageControl::~MOAIGwenPageControl () {
}


//----------------------------------------------------------------//
void MOAIGwenPageControl::RegisterLuaClass ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaClass( state );
	state.SetField ( -1, "EVENT_PAGE_CHANGE",    ( u32 )EVENT_PAGE_CHANGE );
	state.SetField ( -1, "EVENT_FINISH",         ( u32 )EVENT_FINISH      );
	luaL_Reg regTable [] = {
		{ "new", MOAILogMessages::_alertNewIsUnsupported },
		{ NULL,  NULL }
	};
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIGwenPageControl::RegisterLuaFuncs ( MOAILuaState& state ) {
	MOAIGwenControl::RegisterLuaFuncs( state );
	
	luaL_Reg regTable [] = {
		{ "getPageCount",      _getPageCount      },
		{ "setPageCount",      _setPageCount      },
		{ "showPage",          _showPage          },
		{ "getPageNumber",     _getPageNumber     },
		{ "getPage",           _getPage           },
		{ "getCurrentPage",    _getCurrentPage    },
		{ "nextPage",          _nextPage          },
		{ "previousPage",      _previousPage      },
		{ "finish",            _finish            },
		{ "getNextButton",     _getNextButton     },
		{ "getBackButton",     _getBackButton     },
		{ "getFinishButton",   _getFinishButton   },
		{ "getLabel",          _getLabel          },
		{ "useFinishButton",   _useFinishButton   },
		{ NULL, NULL  }
	};
	
	luaL_register ( state, 0, regTable );
}
