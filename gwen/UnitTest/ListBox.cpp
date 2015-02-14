#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/ListBox.h"

using namespace Gwen;

class ListBox : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( ListBox, GUnit )
		{
			{
				Gwen::Controls::ListBox* ctrl = new Gwen::Controls::ListBox( this );
				ctrl->SetBounds( 10, 10, 100, 200 );
				ctrl->AddItem( GWEN_T("First") );
				ctrl->AddItem( GWEN_T("Blue") );
				ctrl->AddItem( GWEN_T("Yellow") );
				ctrl->AddItem( GWEN_T("Orange") );
				ctrl->AddItem( GWEN_T("Brown") );
				ctrl->AddItem( GWEN_T("Black") );
				ctrl->AddItem( GWEN_T("Green") );
				ctrl->AddItem( GWEN_T("Dog") );
				ctrl->AddItem( GWEN_T("Cat Blue") );
				ctrl->AddItem( GWEN_T("Shoes") );
				ctrl->AddItem( GWEN_T("Shirts") );
				ctrl->AddItem( GWEN_T("Chair") );
				ctrl->AddItem( GWEN_T("Last") );
				ctrl->SelectByString( GWEN_T("Bl*"), true );
				ctrl->SetAllowMultiSelect( true );
				ctrl->SetKeyboardInputEnabled( true );
				ctrl->onRowSelected.Add( this, &ThisClass::RowSelected );
			}
			{
				Gwen::Controls::ListBox* ctrl = new Gwen::Controls::ListBox( this );
				ctrl->SetBounds( 120, 10, 200, 200 );
				ctrl->SetColumnCount( 3 );
				ctrl->SetAllowMultiSelect( true );
				ctrl->onRowSelected.Add( this, &ThisClass::RowSelected );
				{
					Gwen::Controls::Layout::TableRow* pRow = ctrl->AddItem( GWEN_T("Baked Beans") );
					pRow->SetCellText( 1, GWEN_T("Heinz") );
					pRow->SetCellText( 2, GWEN_T("£3.50") );
				}
				{
					Gwen::Controls::Layout::TableRow* pRow = ctrl->AddItem( GWEN_T("Bananas") );
					pRow->SetCellText( 1, GWEN_T("Trees") );
					pRow->SetCellText( 2, GWEN_T("$1.27") );
				}
				{
					Gwen::Controls::Layout::TableRow* pRow = ctrl->AddItem( GWEN_T("Chicken") );
					pRow->SetCellText( 1, GWEN_T("\u5355\u5143\u6D4B\u8BD5") );
					pRow->SetCellText( 2, GWEN_T("\u20AC8.95") );
				}
			}
		}


		void RowSelected( Gwen::Controls::Base* pControl )
		{
			Gwen::Controls::ListBox* ctrl = ( Gwen::Controls::ListBox* ) pControl;
			UnitPrint( Utility::Format( GWEN_T("Listbox Item Selected: %ls"), ctrl->GetSelectedRow()->GetText( 0 ).GetUnicode().c_str() ) );
		}

		Gwen::Font	m_Font;
};



DEFINE_UNIT_TEST( ListBox, GWEN_T("ListBox") );
