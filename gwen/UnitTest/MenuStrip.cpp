#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/MenuStrip.h"

using namespace Gwen;

class MenuStrip : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( MenuStrip, GUnit )
		{
			Dock( Pos::Fill );
			Gwen::Controls::MenuStrip* menu = new Gwen::Controls::MenuStrip( this );
			{
				Gwen::Controls::MenuItem* pRoot = menu->AddItem( GWEN_T("File") );
				pRoot->GetMenu()->AddItem( GWEN_T("New"), GWEN_T("test16.png"), GWEN_T("Ctrl + N") )->SetAction( this, &ThisClass::MenuItemSelect );
				pRoot->GetMenu()->AddItem( GWEN_T("Load"), GWEN_T("test16.png"), GWEN_T("Ctrl+L") )->SetAction( this, &ThisClass::MenuItemSelect );
				pRoot->GetMenu()->AddItem( GWEN_T("Save"), GWEN_T(""), GWEN_T("CTRL+S") )->SetAction( this, &ThisClass::MenuItemSelect );
				pRoot->GetMenu()->AddItem( GWEN_T("Save As.."), GWEN_T(""), GWEN_T("Ctrl+Shift+S") )->SetAction( this, &ThisClass::MenuItemSelect );
				pRoot->GetMenu()->AddItem( GWEN_T("Quit"), GWEN_T(""), GWEN_T("Ctrl+Q") )->SetAction( this, &ThisClass::MenuItemSelect );
			}
			{
				Gwen::Controls::MenuItem* pRoot = menu->AddItem( GWEN_T("\u043F\u0438\u0440\u0430\u0442\u0441\u0442\u0432\u043E") );
				pRoot->GetMenu()->AddItem( GWEN_T("\u5355\u5143\u6D4B\u8BD5") )->SetAction( this, &ThisClass::MenuItemSelect );
				pRoot->GetMenu()->AddItem( GWEN_T("\u0111\u01A1n v\u1ECB th\u1EED nghi\u1EC7m") )->SetAction( this, &ThisClass::MenuItemSelect );
			}
			{
				Gwen::Controls::MenuItem* pRoot = menu->AddItem( GWEN_T("Submenu") );
				Gwen::Controls::MenuItem* pCheckable = pRoot->GetMenu()->AddItem( GWEN_T("Checkable") );
				pCheckable->SetCheckable( true );
				pCheckable->SetChecked( true );
				{
					Gwen::Controls::MenuItem* pRootB = pRoot->GetMenu()->AddItem( GWEN_T("Two") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.One") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Two") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Three") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Four") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Five") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Six") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Seven") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Eight") );
					pRootB->GetMenu()->AddItem( GWEN_T("Two.Nine"), GWEN_T("test16.png") );
				}
				pRoot->GetMenu()->AddItem( GWEN_T("Three") );
				pRoot->GetMenu()->AddItem( GWEN_T("Four") );
				pRoot->GetMenu()->AddItem( GWEN_T("Five") );
				{
					Gwen::Controls::MenuItem* pRootB = pRoot->GetMenu()->AddItem( GWEN_T("Six") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.One") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Two") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Three") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Four") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Five"), GWEN_T("test16.png") );
					{
						Gwen::Controls::MenuItem* pRootC = pRootB->GetMenu()->AddItem( GWEN_T("Six.Six") );
						pRootC->GetMenu()->AddItem( GWEN_T("Sheep") );
						pRootC->GetMenu()->AddItem( GWEN_T("Goose") );
						{
							Gwen::Controls::MenuItem* pRootD = pRootC->GetMenu()->AddItem( GWEN_T("Camel") );
							pRootD->GetMenu()->AddItem( GWEN_T("Eyes") );
							pRootD->GetMenu()->AddItem( GWEN_T("Nose") );
							{
								Gwen::Controls::MenuItem* pRootE = pRootD->GetMenu()->AddItem( GWEN_T("Hair") );
								pRootE->GetMenu()->AddItem( GWEN_T("Blonde") );
								pRootE->GetMenu()->AddItem( GWEN_T("Black") );
								{
									Gwen::Controls::MenuItem* pRootF = pRootE->GetMenu()->AddItem( GWEN_T("Red") );
									pRootF->GetMenu()->AddItem( GWEN_T("Light") );
									pRootF->GetMenu()->AddItem( GWEN_T("Medium") );
									pRootF->GetMenu()->AddItem( GWEN_T("Dark") );
								}
								pRootE->GetMenu()->AddItem( GWEN_T("Brown") );
							}
							pRootD->GetMenu()->AddItem( GWEN_T("Ears") );
						}
						pRootC->GetMenu()->AddItem( GWEN_T("Duck") );
					}
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Seven") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Eight") );
					pRootB->GetMenu()->AddItem( GWEN_T("Six.Nine") );
				}
				pRoot->GetMenu()->AddItem( GWEN_T("Seven") );
			}
		}


		void MenuItemSelect( Base* pControl )
		{
			Gwen::Controls::MenuItem* pMenuItem = ( Gwen::Controls::MenuItem* ) pControl;
			UnitPrint( Utility::Format( GWEN_T("Menu Selected: %ls"), pMenuItem->GetText().GetUnicode().c_str() ) );
		}

};



DEFINE_UNIT_TEST( MenuStrip, GWEN_T("MenuStrip") );
