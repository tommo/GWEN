#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/TextBox.h"

using namespace Gwen;

class TextBox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( TextBox, GUnit )
		{
			{
				Gwen::Controls::TextBox* label = new Gwen::Controls::TextBox( this );
				label->SetText( GWEN_T("") );
				label->SetPos( 10, 10 );
				label->onTextChanged.Add( this, &ThisClass::OnEdit );
				label->onReturnPressed.Add( this, &ThisClass::OnSubmit );
			}
			{
				Gwen::Controls::TextBox* label = new Gwen::Controls::TextBox( this );
				label->SetText( GWEN_T("Normal Everyday Label") );
				label->SetPos( 10, 10 + 25 );
			}
			{
				Gwen::Controls::TextBox* label = new Gwen::Controls::TextBox( this );
				label->SetText( GWEN_T("Select All Text On Focus") );
				label->SetPos( 10, 10 + 25 * 2 );
				label->SetSelectAllOnFocus( true );
			}
			{
				Gwen::Controls::TextBox* label = new Gwen::Controls::TextBox( this );
				label->SetText( GWEN_T("Different Coloured Text, for some reason") );
				label->SetTextColor( Gwen::Color( 255, 0, 255, 255 ) );
				label->SetPos( 10, 10 + 25 * 3 );
			}
			{
				Gwen::Controls::TextBoxNumeric* label = new Gwen::Controls::TextBoxNumeric( this );
				label->SetText( GWEN_T("2004") );
				label->SetTextColor( Gwen::Color( 255, 0, 255, 255 ) );
				label->SetPos( 10, 10 + 25 * 4 );
			}
			{
				m_Font.facename = GWEN_T("Impact");
				m_Font.size = 50;
				Gwen::Controls::TextBox* label = new Gwen::Controls::TextBox( this );
				label->SetText( GWEN_T("Different Font") );
				label->SetPos( 10, 10 + 25 * 5 );
				label->SetFont( &m_Font );
				label->SetSize( 200, 55 );
			}
			{
				Gwen::Controls::TextBoxMultiline* label = new Gwen::Controls::TextBoxMultiline( this );
				label->SetText( GWEN_T("I think we're losing sight of the real issue here, which is: what are we gonna call ourselves?\n\nErm, and I think it comes down to a choice between \"The League Against Salivating Monsters\" or my own personal preference, which is \"The Committee for the Liberation and Integration of Terrifying Organisms and their Rehabilitation Into Society.\" Erm, one drawback with that: the abbreviation is \"CLITORIS.\"") );
				label->SetPos( 220, 10 );
				label->SetSize( 200, 180 );
			}
		}

		void OnEdit( Gwen::Controls::Base* pControl )
		{

			Gwen::Controls::TextBox* textbox = ( Gwen::Controls::TextBox* )( pControl );
			UnitPrint( Utility::Format( GWEN_T("Textbox Edit: [%ls]\n"), textbox->GetText().GetUnicode().c_str() ) );
		}

		void OnSubmit( Gwen::Controls::Base* pControl )
		{
			Gwen::Controls::TextBox* textbox = ( Gwen::Controls::TextBox* )( pControl );
			UnitPrint( Utility::Format( GWEN_T("Textbox Submit: [%ls]\n"), textbox->GetText().GetUnicode().c_str() ) );
		}

		Gwen::Font	m_Font;
};



DEFINE_UNIT_TEST( TextBox, GWEN_T("TextBox") );
