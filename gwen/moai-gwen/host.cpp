// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/host.h>
#include <moai-gwen/headers.h>

#include <moai-gwen/ControlTypes.h>


//================================================================//
// aku-Gwen
//================================================================//
void RegisterGwenControlTypes() {
	//Skins
	REGISTER_LUA_CLASS ( MOAIGwenSkin )
	REGISTER_LUA_CLASS ( MOAIGwenSkinTexturedBase )
	REGISTER_LUA_CLASS ( MOAIGwenSkinSimple )

	REGISTER_LUA_CLASS ( MOAIGwenCanvas )
	REGISTER_LUA_CLASS ( MOAIGwenWindowControl )
	// // REGISTER_LUA_CLASS ( MOAIGwenWindowCanvas )

	REGISTER_LUA_CLASS ( MOAIGwenButton )
	REGISTER_LUA_CLASS ( MOAIGwenLabel )
	REGISTER_LUA_CLASS ( MOAIGwenCheckBox )

}

//----------------------------------------------------------------//
void AKUGwenAppFinalize () {
}

//----------------------------------------------------------------//
void AKUGwenAppInitialize () {
}

//----------------------------------------------------------------//
void AKUGwenContextInitialize () {
	MOAIGwenMgr::Affirm();
	// System
	REGISTER_LUA_CLASS ( MOAIGwenMgr )
	REGISTER_LUA_CLASS ( MOAIGwenSystem )

	// Controls
	REGISTER_LUA_CLASS ( MOAIGwenControl )

	RegisterGwenControlTypes();
}
