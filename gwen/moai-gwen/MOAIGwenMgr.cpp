#include "moai-gwen/MOAIGwenMgr.h"
#include "moai-gwen/MOAIGwenRenderer.h"

#include "Gwen/Skins/Simple.h"

// #include <zl-util/ZLDeviceTime.h>
#include "Gwen/Platform.h"
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
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//----------------------------------------------------------------//
void MOAIGwenMgr::RegisterLuaFuncs(MOAILuaState& state)
{
	UNUSED(state);
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