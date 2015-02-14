/*
	GWEN
	Copyright (c) 2010 Facepunch Studios
	See license in Gwen.h
*/


#include "Gwen/Controls/ColorPicker.h"
#include "Gwen/Controls/HorizontalSlider.h"
#include "Gwen/Controls/GroupBox.h"
#include "Gwen/Controls/TextBox.h"
#include "Gwen/Utility.h"

using namespace Gwen;
using namespace Gwen::Controls;
using namespace Gwen::ControlsInternal;

GWEN_CONTROL_CONSTRUCTOR( ColorPicker )
{
	SetMouseInputEnabled( true );
	SetSize( 256, 150 );
	CreateControls();
	SetColor( Gwen::Color( 50, 60, 70, 255 ) );
}

void ColorPicker::CreateColorControl( Gwen::String name, int y )
{
	int colorSize = 12;
	GroupBox* colorGroup = new GroupBox( this );
	colorGroup->SetPos( 10, y );
	colorGroup->SetText( name );
	colorGroup->SetSize( 160, 35 );
	colorGroup->SetName( name + GWEN_T("groupbox") );
	ColorDisplay* disp = new ColorDisplay( colorGroup );
	disp->SetName( name );
	disp->SetBounds( 0 , 3, colorSize, colorSize );
	TextBoxNumeric* numeric = new TextBoxNumeric( colorGroup );
	numeric->SetName( name + GWEN_T("Box") );
	numeric->SetPos( 105, 0 );
	numeric->SetSize( 26, 16 );
	numeric->SetSelectAllOnFocus( true );
	numeric->onTextChanged.Add( this, &ColorPicker::NumericTyped );
	HorizontalSlider* slider = new HorizontalSlider( colorGroup );
	slider->SetPos( colorSize + 5 , 1 );
	slider->SetRange( 0, 255 );
	slider->SetSize( 80, Gwen::Utility::Max( colorSize, 15 ) );
	slider->SetName( name + GWEN_T("Slider") );
	slider->onValueChanged.Add( this, &ColorPicker::SlidersMoved );
}

void ColorPicker::NumericTyped( Gwen::Controls::Base* control )
{
	TextBoxNumeric* box = gwen_cast<TextBoxNumeric> ( control );

	if ( !box )
	{ return; }

	if ( box->GetText() == GWEN_T("") )
	{ return; }

	int textValue = Gwen::Utility::Strings::To::Int( box->GetText().GetUnicode() );

	if ( textValue < 0 ) { textValue = 0; }

	if ( textValue > 255 ) { textValue = 255; }

	if ( box->GetName().find( GWEN_T("Red") ) != Gwen::String::npos )
	{ SetRed( textValue ); }

	if ( box->GetName().find( GWEN_T("Green") ) != Gwen::String::npos )
	{ SetGreen( textValue ); }

	if ( box->GetName().find( GWEN_T("Blue") ) != Gwen::String::npos )
	{ SetBlue( textValue ); }

	if ( box->GetName().find( GWEN_T("Alpha") ) != Gwen::String::npos )
	{ SetAlpha( textValue ); }

	UpdateControls();
}

void ColorPicker::SetColor( Gwen::Color color )
{
	m_Color = color;
	UpdateControls();
}

void ColorPicker::CreateControls()
{
	int startY = 5;
	int height = 35;
	CreateColorControl( GWEN_T("Red"),	 startY );
	CreateColorControl( GWEN_T("Green"), startY + height );
	CreateColorControl( GWEN_T("Blue"),  startY + height * 2 );
	CreateColorControl( GWEN_T("Alpha"), startY + height * 3 );
	GroupBox* finalGroup = new GroupBox( this );
	finalGroup->SetPos( 180, 40 );
	finalGroup->SetSize( 60, 60 );
	finalGroup->SetText( GWEN_T("Result") );
	finalGroup->SetName( GWEN_T("ResultGroupBox") );
	ColorDisplay* disp = new ColorDisplay( finalGroup );
	disp->SetName( GWEN_T("Result") );
	disp->SetBounds( 7 , 5, 32, 32 );
	disp->SetDrawCheckers( true );
	//UpdateControls();
}

void ColorPicker::UpdateColorControls( Gwen::String name, Gwen::Color col, int sliderVal )
{
	ColorDisplay* disp = gwen_cast<ColorDisplay> ( FindChildByName( name, true ) );
	disp->SetColor( col );
	HorizontalSlider* slider = gwen_cast<HorizontalSlider> ( FindChildByName( name + GWEN_T("Slider"), true ) );
	slider->SetFloatValue( sliderVal );
	TextBoxNumeric* box = gwen_cast<TextBoxNumeric> ( FindChildByName( name + GWEN_T("Box"), true ) );
	box->SetText( Gwen::Utility::ToString( sliderVal ) );
}

void ColorPicker::UpdateControls()
{
	//This is a little weird, but whatever for now
	UpdateColorControls( GWEN_T("Red"),		Color( GetColor().r, 0, 0, 255 ), GetColor().r );
	UpdateColorControls( GWEN_T("Green"),	Color( 0, GetColor().g, 0, 255 ), GetColor().g );
	UpdateColorControls( GWEN_T("Blue"),	Color( 0, 0, GetColor().b, 255 ), GetColor().b );
	UpdateColorControls( GWEN_T("Alpha"),	Color( 255, 255, 255, GetColor().a ), GetColor().a );
	ColorDisplay* disp = gwen_cast<ColorDisplay> ( FindChildByName( GWEN_T("Result"), true ) );
	disp->SetColor( Color( GetColor().r, GetColor().g, GetColor().b, GetColor().a ) );
	onColorChanged.Call( this );
}
void ColorPicker::SlidersMoved( Gwen::Controls::Base* control )
{
	/*
	HorizontalSlider* redSlider		= gwen_cast<HorizontalSlider>(	FindChildByName( "RedSlider",   true ) );
	HorizontalSlider* greenSlider	= gwen_cast<HorizontalSlider>(	FindChildByName( "GreenSlider", true ) );
	HorizontalSlider* blueSlider	= gwen_cast<HorizontalSlider>(	FindChildByName( "BlueSlider",  true ) );
	HorizontalSlider* alphaSlider	= gwen_cast<HorizontalSlider>(	FindChildByName( "AlphaSlider", true ) );
	*/
	HorizontalSlider* slider = gwen_cast<HorizontalSlider> ( control );

	if ( slider )
	{ SetColorByName( GetColorFromName( slider->GetName() ), slider->GetFloatValue() ); }

	UpdateControls();
	//SetColor( Gwen::Color( redSlider->GetValue(), greenSlider->GetValue(), blueSlider->GetValue(), alphaSlider->GetValue() ) );
}

void ColorPicker::Layout( Skin::Base* skin )
{
	BaseClass::Layout( skin );
	SizeToChildren( false, true );
	SetSize( Width(), Height() + 5 );
	GroupBox* groupBox = gwen_cast<GroupBox> ( FindChildByName( GWEN_T("ResultGroupBox"), true ) );

	if ( groupBox )
	{ groupBox->SetPos( groupBox->X(), Height() * 0.5f - groupBox->Height() * 0.5f ); }

	UpdateControls();
}


int ColorPicker::GetColorByName( Gwen::String colorName )
{
	if ( colorName == GWEN_T("Red") )
	{ return GetColor().r; }
	else if ( colorName == GWEN_T("Green") )
	{ return GetColor().g; }
	else if ( colorName == GWEN_T("Blue") )
	{ return GetColor().b; }
	else if ( colorName == GWEN_T("Alpha") )
	{ return GetColor().a; }
	else
	{ return 0; }
}

Gwen::String ColorPicker::GetColorFromName( Gwen::String name )
{
	if ( name.find( GWEN_T("Red") ) != Gwen::String::npos )
	{ return GWEN_T("Red"); }

	if ( name.find( GWEN_T("Green") ) != Gwen::String::npos )
	{ return GWEN_T("Green"); }

	if ( name.find( GWEN_T("Blue") ) != Gwen::String::npos )
	{ return GWEN_T("Blue"); }

	if ( name.find( GWEN_T("Alpha") ) != Gwen::String::npos )
	{ return GWEN_T("Alpha"); }
	else
	{ return GWEN_T(""); }
}

void ColorPicker::SetColorByName( Gwen::String colorName, int colorValue )
{
	if ( colorName == GWEN_T("Red") )
	{ SetRed( colorValue ); }
	else if ( colorName == GWEN_T("Green") )
	{ SetGreen( colorValue ); }
	else if ( colorName == GWEN_T("Blue") )
	{ SetBlue( colorValue ); }
	else if ( colorName == GWEN_T("Alpha") )
	{ SetAlpha( colorValue ); }
}

void ColorPicker::SetAlphaVisible( bool visible )
{
	GroupBox* groupBox = gwen_cast<GroupBox> ( FindChildByName( GWEN_T("Alphagroupbox"), true ) );
	groupBox->SetHidden( !visible );
	Invalidate();
}
