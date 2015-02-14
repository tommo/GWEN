#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/ComboBox.h"

using namespace Gwen;

class ComboBox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ComboBox, GUnit )
		{
			{
				Gwen::Controls::ComboBox* combo = new Gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 50 );
				combo->SetWidth( 200 );
				combo->AddItem( GWEN_T("Option One"), GWEN_T("one") );
				combo->AddItem( GWEN_T("Number Two"), GWEN_T("two") );
				combo->AddItem( GWEN_T("Door Three"), GWEN_T("three") );
				combo->AddItem( GWEN_T("Four Legs"), GWEN_T("four") );
				combo->AddItem( GWEN_T("Five Birds"), GWEN_T("five") );
				combo->onSelection.Add( this, &ComboBox::OnComboSelect );
			}
			{
				// Empty..
				Gwen::Controls::ComboBox* combo = new Gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 80 );
				combo->SetWidth( 200 );
			}
			{
				// Empty..
				Gwen::Controls::ComboBox* combo = new Gwen::Controls::ComboBox( this );
				combo->SetPos( 50, 110 );
				combo->SetWidth( 200 );

				for ( int i = 0; i < 500; i++ )
				{ combo->AddItem( GWEN_T("Lots Of Options") ); }
			}
		}

		void OnComboSelect( Gwen::Controls::Base* pControl )
		{
			Gwen::Controls::ComboBox* combo = ( Gwen::Controls::ComboBox* ) pControl;
			UnitPrint( Utility::Format( GWEN_T("Combo Changed: %s"), combo->GetSelectedItem()->GetText().GetUnicode().c_str() ) );
		}
};



DEFINE_UNIT_TEST( ComboBox, GWEN_T("ComboBox") );
