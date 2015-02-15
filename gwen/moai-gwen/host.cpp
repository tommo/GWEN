// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moai-gwen/host.h>
#include <moai-gwen/headers.h>

#include <moai-gwen/ControlTypes.h>


//================================================================//
// aku-Gwen
//================================================================//
#define REGISTER_GWEN_CLASS( name ) REGISTER_LUA_CLASS ( MOAIGwen##name )

void RegisterGwenControlTypes() {
	//Skins
	REGISTER_GWEN_CLASS ( Skin )
	REGISTER_GWEN_CLASS ( SkinTexturedBase )
	REGISTER_GWEN_CLASS ( SkinSimple )

	REGISTER_GWEN_CLASS ( Canvas )
	REGISTER_GWEN_CLASS ( WindowControl )
	// // REGISTER_GWEN_CLASS ( WindowCanvas )

	REGISTER_GWEN_CLASS ( Button )
	REGISTER_GWEN_CLASS ( Label )
	REGISTER_GWEN_CLASS ( LabelClickable )
	REGISTER_GWEN_CLASS ( CheckBox )
	REGISTER_GWEN_CLASS ( ComboBox )
	REGISTER_GWEN_CLASS ( RadioButton )
	REGISTER_GWEN_CLASS ( GroupBox )
	REGISTER_GWEN_CLASS ( RadioButtonGroup )

	REGISTER_GWEN_CLASS ( Menu )
	REGISTER_GWEN_CLASS ( MenuItem )
	REGISTER_GWEN_CLASS ( MenuBar )

	REGISTER_GWEN_CLASS ( ToolBar )
	REGISTER_GWEN_CLASS ( ToolButton )

	REGISTER_GWEN_CLASS ( ScrollControl )

	REGISTER_GWEN_CLASS ( ProgressBar )
	REGISTER_GWEN_CLASS ( ColorPicker )

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
