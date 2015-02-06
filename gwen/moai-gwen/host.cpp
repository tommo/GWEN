// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/host.h>
#include <moai-gwen/headers.h>


//controls
#include <moai-gwen/MOAIGwenCanvas.h>
#include <moai-gwen/MOAIGwenWindowCanvas.h>
#include <moai-gwen/MOAIGwenWindowControl.h>

#include <moai-gwen/MOAIGwenButton.h>
#include <moai-gwen/MOAIGwenLabel.h>

//skins
#include <moai-gwen/MOAIGwenSkinSimple.h>


//================================================================//
// aku-Gwen
//================================================================//

//----------------------------------------------------------------//
void AKUGwenAppFinalize () {
}

//----------------------------------------------------------------//
void AKUGwenAppInitialize () {
}

//----------------------------------------------------------------//
void AKUGwenContextInitialize () {
	MOAIGwenMgr::Affirm();
	// //System
	REGISTER_LUA_CLASS ( MOAIGwenMgr )
	REGISTER_LUA_CLASS ( MOAIGwenSystem )

	// //Controls
	REGISTER_LUA_CLASS ( MOAIGwenControl )
	
	REGISTER_LUA_CLASS ( MOAIGwenCanvas )
	// // REGISTER_LUA_CLASS ( MOAIGwenWindowCanvas )
	REGISTER_LUA_CLASS ( MOAIGwenWindowControl )

	REGISTER_LUA_CLASS ( MOAIGwenButton )
	REGISTER_LUA_CLASS ( MOAIGwenLabel )

	// //Skins
	REGISTER_LUA_CLASS ( MOAIGwenSkin )
	REGISTER_LUA_CLASS ( MOAIGwenSkinSimple )

}
