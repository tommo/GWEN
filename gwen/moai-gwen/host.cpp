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
	REGISTER_GWEN_CLASS ( Rectangle )
	REGISTER_GWEN_CLASS ( ImagePanel )
	REGISTER_GWEN_CLASS ( CheckBox )
	REGISTER_GWEN_CLASS ( ComboBox )
	REGISTER_GWEN_CLASS ( RadioButton )
	REGISTER_GWEN_CLASS ( RadioButtonGroup )
	REGISTER_GWEN_CLASS ( GroupBox )
	REGISTER_GWEN_CLASS ( ListBox )
	REGISTER_GWEN_CLASS ( TextBox )
	
	REGISTER_GWEN_CLASS ( TreeNode )
	REGISTER_GWEN_CLASS ( TreeControl )

	REGISTER_GWEN_CLASS ( TabButton )
	REGISTER_GWEN_CLASS ( TabControl )
	
	REGISTER_GWEN_CLASS ( Menu )
	REGISTER_GWEN_CLASS ( MenuItem )
	REGISTER_GWEN_CLASS ( MenuBar )

	REGISTER_GWEN_CLASS ( VerticalSlider )
	REGISTER_GWEN_CLASS ( HorizontalSlider )

	REGISTER_GWEN_CLASS ( Dragger )
	REGISTER_GWEN_CLASS ( VerticalSplitter )
	REGISTER_GWEN_CLASS ( HorizontalSplitter )
	REGISTER_GWEN_CLASS ( CrossSplitter )

	REGISTER_GWEN_CLASS ( ToolBar )
	REGISTER_GWEN_CLASS ( ToolButton )
	
	REGISTER_GWEN_CLASS ( StatusBar )
	REGISTER_GWEN_CLASS ( DockBase )

	REGISTER_GWEN_CLASS ( ScrollControl )
	REGISTER_GWEN_CLASS ( BaseScrollBar )
	REGISTER_GWEN_CLASS ( VerticalScrollBar )
	REGISTER_GWEN_CLASS ( HorizontalScrollBar )

	REGISTER_GWEN_CLASS ( ProgressBar )
	REGISTER_GWEN_CLASS ( ColorPicker )
	REGISTER_GWEN_CLASS ( CollapsibleList )
	REGISTER_GWEN_CLASS ( CollapsibleCategory )
	REGISTER_GWEN_CLASS ( PageControl )

	//property
	REGISTER_GWEN_CLASS ( PropertyRow )
	REGISTER_GWEN_CLASS ( Properties )
	REGISTER_GWEN_CLASS ( PropertyTree )
	REGISTER_GWEN_CLASS ( BaseProperty )


	//layout
	REGISTER_GWEN_CLASS ( LayoutPosition )
	REGISTER_GWEN_CLASS ( LayoutTable )
	REGISTER_GWEN_CLASS ( LayoutTableRow )
	REGISTER_GWEN_CLASS ( LayoutTile )
	
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
