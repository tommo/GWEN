#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/TabControl.h"
#include "Gwen/Controls/RadioButtonController.h"

using namespace Gwen;

class TabControl : public GUnit
{
	public:

		Controls::TabControl* m_pDockControlLeft;

		GWEN_CONTROL_INLINE( TabControl, GUnit )
		{
			{
				m_pDockControlLeft = new Controls::TabControl( this );
				m_pDockControlLeft->SetBounds( 10, 10, 200, 200 );
				{
					Controls::TabButton* pButton = m_pDockControlLeft->AddPage( GWEN_T("Controls") );
					Base* pPage = pButton->GetPage();
					{
						Controls::RadioButtonController* pRadio = new Controls::RadioButtonController( pPage );
						pRadio->SetBounds( 10, 10, 100, 100 );
						pRadio->AddOption( GWEN_T("Top") )->Select();
						pRadio->AddOption( GWEN_T("Bottom") );
						pRadio->AddOption( GWEN_T("Left") );
						pRadio->AddOption( GWEN_T("Right") );
						pRadio->onSelectionChange.Add( this, &ThisClass::OnDockChange );
					}
				}
				m_pDockControlLeft->AddPage( GWEN_T("Red") );
				m_pDockControlLeft->AddPage( GWEN_T("Green") );
				m_pDockControlLeft->AddPage( GWEN_T("Blue") );
			}
			{
				Controls::TabControl* pDragMe = new Controls::TabControl( this );
				pDragMe->SetBounds( 220, 10, 200, 200 );
				pDragMe->AddPage( GWEN_T("You") );
				pDragMe->AddPage( GWEN_T("Can") );
				pDragMe->AddPage( GWEN_T("Reorder") )->SetImage( GWEN_T("test16.png") );
				pDragMe->AddPage( GWEN_T("These") );
				pDragMe->AddPage( GWEN_T("Tabs") );
				pDragMe->SetAllowReorder( true );
			}
		}

		void OnDockChange( Gwen::Controls::Base* pControl )
		{
			Gwen::Controls::RadioButtonController* rc = ( Gwen::Controls::RadioButtonController* ) pControl;

			if ( rc->GetSelectedLabel() == GWEN_T("Top") )		{ m_pDockControlLeft->SetTabStripPosition( Pos::Top ); }

			if ( rc->GetSelectedLabel() == GWEN_T("Bottom") )	{ m_pDockControlLeft->SetTabStripPosition( Pos::Bottom ); }

			if ( rc->GetSelectedLabel() == GWEN_T("Left") )	{ m_pDockControlLeft->SetTabStripPosition( Pos::Left ); }

			if ( rc->GetSelectedLabel() == GWEN_T("Right") )	{ m_pDockControlLeft->SetTabStripPosition( Pos::Right ); }
		}

		Gwen::Font	m_Font;
};



DEFINE_UNIT_TEST( TabControl, GWEN_T("TabControl") );
