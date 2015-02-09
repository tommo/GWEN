#include "moai-gwen/MOAIGwenMgr.h"
#include "moai-gwen/MOAIGwenRenderer.h"

#include "Gwen/Skins/Simple.h"
#include "Gwen/Texture.h"

// #include <zl-util/ZLDeviceTime.h>
#include "Gwen/Platform.h"

#include "moai-sim/pch.h"
#include "moai-sim/MOAITexture.h"

//----------------------------------------------------------------//

int MOAIGwenMgr::_setTextureLoader ( lua_State* L ) {
	MOAILuaState state ( L );
	MOAIGwenMgr& mgr = MOAIGwenMgr::Get();
	if( state.IsType( 1, LUA_TFUNCTION ) && state.IsType( 2, LUA_TFUNCTION ) ){
		mgr.mOnLoadTexture.SetRef ( state, 1 );
		mgr.mOnUnloadTexture.SetRef ( state, 2 );
	} else {
		mgr.mOnLoadTexture.Clear();
		mgr.mOnUnloadTexture.Clear();
	}
	return 0;
}

//----------------------------------------------------------------//
MOAIGwenMgr::MOAIGwenMgr ()
{
	RTTI_SINGLE ( MOAILuaObject )
	this->mRenderer = new Gwen::Renderer::MOAIRenderer();
	this->mDefaultSkin = new Gwen::Skin::Simple( this->mRenderer );
	this->mDefaultCanvas = new Gwen::Controls::Canvas( this->mDefaultSkin );
}

//----------------------------------------------------------------//
MOAIGwenMgr::~MOAIGwenMgr ()
{
	//FIXME: MOAI Globals should be removed after a FULL LUA GC
	delete this->mDefaultCanvas ;
	// delete this->mDefaultSkin ;
	// delete this->mRenderer;
}

//----------------------------------------------------------------//
void MOAIGwenMgr::RegisterLuaClass(MOAILuaState& state)
{
	luaL_Reg regTable[] = {
		{ "setTextureLoader",  _setTextureLoader },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//----------------------------------------------------------------//
void MOAIGwenMgr::RegisterLuaFuncs(MOAILuaState& state)
{
	UNUSED(state);
}


void MOAIGwenMgr::LoadTexture( Gwen::Texture* texture ) {
	//TODO: lua callback support
	if( this->mOnLoadTexture ) {
		MOAIScopedLuaState state = MOAILuaRuntime::Get ().State ();
		if ( this->mOnLoadTexture.PushRef ( state )) {
			lua_pushstring( state, texture->name.c_str() );
			state.DebugCall ( 1, 1 );
			MOAITexture* tex = state.GetLuaObject < MOAITexture >( -1, 0 );
		}
	} else {
		//default loader
		MOAITexture* tex = new MOAITexture();
		tex->Init( texture->name.c_str(), MOAIImageTransform::TRUECOLOR | MOAIImageTransform::PREMULTIPLY_ALPHA );
		// printf("loading texture %s\n", texture->name.c_str() );
		// printf("%d,%d\n", tex->GetWidth(), tex->GetHeight() );
		texture->data = tex;
		texture->width = tex->GetWidth();
		texture->height = tex->GetHeight();
		tex->Retain();
	}
}

void MOAIGwenMgr::ReleaseTexture( Gwen::Texture* texture ) {
	//TODO
	if( texture->data ) {
		MOAITexture* tex = static_cast< MOAITexture* >( texture->data );
		tex->Release();
	}
}


//----------------------------------------------------------------//
//Platform helpers
static Gwen::UnicodeString gs_ClipboardEmulator;
void Gwen::Platform::Sleep( unsigned int iMS )
{
	// TODO.
}

void Gwen::Platform::SetCursor( unsigned char iCursor )
{
	// No platform independent way to do this
}

Gwen::UnicodeString Gwen::Platform::GetClipboardText()
{
	return gs_ClipboardEmulator;
}

bool Gwen::Platform::SetClipboardText( const Gwen::UnicodeString & str )
{
	gs_ClipboardEmulator = str;
	return true;
}

float Gwen::Platform::GetTimeInSeconds()
{
	return ZLDeviceTime::GetTimeInSeconds();
}

bool Gwen::Platform::FileOpen( const String & Name, const String & StartPath, const String & Extension, Gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback )
{
	// No platform independent way to do this.
	// Ideally you would open a system dialog here
	return false;
}

bool Gwen::Platform::FileSave( const String & Name, const String & StartPath, const String & Extension, Gwen::Event::Handler* pHandler, Gwen::Event::Handler::FunctionWithInformation fnCallback )
{
	// No platform independent way to do this.
	// Ideally you would open a system dialog here
	return false;
}

bool Gwen::Platform::FolderOpen( const String & Name, const String & StartPath, Gwen::Event::Handler* pHandler, Event::Handler::FunctionWithInformation fnCallback )
{
	return false;
}

void* Gwen::Platform::CreatePlatformWindow( int x, int y, int w, int h, const Gwen::String & strWindowTitle )
{
	return NULL;
}

void Gwen::Platform::DestroyPlatformWindow( void* pPtr )
{
}

void Gwen::Platform::MessagePump( void* pWindow, Gwen::Controls::Canvas* ptarget )
{
}

void Gwen::Platform::SetBoundsPlatformWindow( void* pPtr, int x, int y, int w, int h )
{
}

void Gwen::Platform::SetWindowMaximized( void* pPtr, bool bMax, Gwen::Point & pNewPos, Gwen::Point & pNewSize )
{
}

void Gwen::Platform::SetWindowMinimized( void* pPtr, bool bMinimized )
{
}

bool Gwen::Platform::HasFocusPlatformWindow( void* pPtr )
{
	return true;
}

void Gwen::Platform::GetDesktopSize( int & w, int & h )
{
	w = 1024;
	h = 768;
}

void Gwen::Platform::GetCursorPos( Gwen::Point & po )
{
}