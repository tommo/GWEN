#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/Properties.h"
#include "Gwen/Controls/PropertyTree.h"
#include "Gwen/Controls/Property/ColorSelector.h"
#include "Gwen/Controls/Property/Checkbox.h"
#include "Gwen/Controls/Property/ComboBox.h"

using namespace Gwen;

class Properties : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( Properties, GUnit )
		{
			{
				Gwen::Controls::Properties* props = new Gwen::Controls::Properties( this );
				props->SetBounds( 10, 10, 150, 300 );
				{
					{
						Gwen::Controls::PropertyRow* pRow = props->Add( GWEN_T("First Name") );
						pRow->onChange.Add( this, &Properties::OnFirstNameChanged );
					}
					props->Add( GWEN_T("Middle Name") );
					props->Add( GWEN_T("Last Name") );
				}
			}
			{
				Gwen::Controls::PropertyTree* ptree = new Gwen::Controls::PropertyTree( this );
				ptree->SetBounds( 200, 10, 200, 200 );
				{
					Gwen::Controls::Properties* props = ptree->Add( GWEN_T("Item One") );
					props->Add( GWEN_T("Middle Name") );
					props->Add( GWEN_T("Last Name") );
					props->Add( GWEN_T("Four") );
				}
				{
					Gwen::Controls::Properties* props = ptree->Add( GWEN_T("Item Two") );
					props->Add( GWEN_T("More Items") );
					props->Add( GWEN_T("Checkbox"), new Gwen::Controls::Property::Checkbox( props ), GWEN_T("1") );
					props->Add( GWEN_T("To Fill") );
					props->Add( GWEN_T("ColorSelector"), new Gwen::Controls::Property::ColorSelector( props ), GWEN_T("255 0 0") );
					props->Add( GWEN_T("Out Here") );
					// Combo Box Test
					{
						Gwen::Controls::Property::ComboBox* pCombo = new Gwen::Controls::Property::ComboBox( props );
						pCombo->GetComboBox()->AddItem( GWEN_T("Option One"), GWEN_T("one") );
						pCombo->GetComboBox()->AddItem( GWEN_T("Number Two"), GWEN_T("two") );
						pCombo->GetComboBox()->AddItem( GWEN_T("Door Three"), GWEN_T("three") );
						pCombo->GetComboBox()->AddItem( GWEN_T("Four Legs"), GWEN_T("four") );
						pCombo->GetComboBox()->AddItem( GWEN_T("Five Birds"), GWEN_T("five") );
						Gwen::Controls::PropertyRow* pRow = props->Add( GWEN_T("ComboBox"), pCombo, GWEN_T("1") );
						pRow->onChange.Add( this, &Properties::OnFirstNameChanged );
					}
				}
				ptree->ExpandAll();
			}
		}

		void OnFirstNameChanged( Controls::Base* pControl )
		{
			Gwen::Controls::PropertyRow* pRow = ( Gwen::Controls::PropertyRow* ) pControl;
			UnitPrint( Utility::Format( GWEN_T("First Name Changed: %ls"), pRow->GetProperty()->GetPropertyValue().GetUnicode().c_str() ) );
		}

};



DEFINE_UNIT_TEST( Properties, GWEN_T("Properties") );
