#include "MOAIGwenSystem.h"
#include "MOAIGwenCanvas.h"

//----------------------------------------------------------------//
// Glue
//----------------------------------------------------------------//
int MOAIGwenSystem::_setSkin ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenSystem, "UU" )
	//TODO
	MOAIGwenSkin* skin = state.GetLuaObject< MOAIGwenSkin >( 2, 0 );
	self->SetSkin( skin );
	return 0;
}

int MOAIGwenSystem::_sendKeyEvent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenSystem, "U" )
	//TODO
	return 0;
}

int MOAIGwenSystem::_sendMouseEvent ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenSystem, "U" )
	//TODO
	return 0;
}


int MOAIGwenSystem::_getCanvas ( lua_State* L ) {
	MOAI_LUA_SETUP ( MOAIGwenSystem, "U" )
	//TODO
	self->mCanvas->PushLuaUserdata( state );
	return 1;
}

//----------------------------------------------------------------//
//
//----------------------------------------------------------------//
MOAIGwenSystem::MOAIGwenSystem () {
	RTTI_BEGIN
		RTTI_EXTEND ( MOAIGraphicsProp )
		RTTI_EXTEND ( MOAIAction )
	RTTI_END
	this->SetMask ( MOAIProp::CAN_DRAW | MOAIProp::CAN_DRAW_DEBUG );
	MOAIGwenCanvas* canvas = new MOAIGwenCanvas();
	canvas->Init();
	this->mCanvas.Set( *this, canvas );
}

//----------------------------------------------------------------//
MOAIGwenSystem::~MOAIGwenSystem () {
	this->mCanvas.Set( *this, 0 );
	this->mSkin.Set( *this, 0 );
}

//----------------------------------------------------------------//
void MOAIGwenSystem::RegisterLuaClass ( MOAILuaState& state ) {

	MOAIGraphicsProp::RegisterLuaClass ( state );
	MOAIAction::RegisterLuaClass ( state );
}

//----------------------------------------------------------------//
void MOAIGwenSystem::RegisterLuaFuncs ( MOAILuaState& state ) {
	
	MOAIGraphicsProp::RegisterLuaFuncs ( state );
	MOAIAction::RegisterLuaFuncs ( state );
	
	luaL_Reg regTable [] = {
		{ "getCanvas",             _getCanvas },
		{ "setSkin",               _setSkin },
		{ "sendKeyEvent",          _setSkin },
		// { "sendMouseEvent",        _setSkin },
		{ NULL, NULL }
	};
	
	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
u32 MOAIGwenSystem::OnGetModelBounds ( ZLBox& bounds ) {
	//TODO
	return BOUNDS_GLOBAL;
}


//----------------------------------------------------------------//
void MOAIGwenSystem::OnUpdate ( float step ) {
	this->ScheduleUpdate ();
}

//----------------------------------------------------------------//
bool MOAIGwenSystem::IsDone () {

	return false;
}

//----------------------------------------------------------------//
void MOAIGwenSystem::Draw ( int subPrimID, float lod ) {
	UNUSED ( subPrimID );

	if ( !this->IsVisible ( lod ) ) return;

	this->LoadGfxState ();
	this->LoadTransforms ();

	MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get ();
	
	gfxDevice.SetVertexPreset ( MOAIVertexFormatMgr::XYZWC );
	gfxDevice.SetVertexMtxMode ( MOAIGfxDevice::VTX_STAGE_MODEL, MOAIGfxDevice::VTX_STAGE_PROJ );
	gfxDevice.SetUVMtxMode ( MOAIGfxDevice::UV_STAGE_MODEL, MOAIGfxDevice::UV_STAGE_TEXTURE );

	( ( Gwen::Controls::Canvas* ) this->mCanvas->GetInternalControl() )->RenderCanvas();

}

//----------------------------------------------------------------//
void MOAIGwenSystem::SetSkin ( MOAIGwenSkin* skin ) {
	this->mSkin.Set( *this, skin );
	if( this->mCanvas ) {
		this->mCanvas->SetSkin( skin );
	}
}
