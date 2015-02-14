#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/CollapsibleList.h"

using namespace Gwen;

class CollapsibleList : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( CollapsibleList, GUnit )
		{
			Gwen::Controls::CollapsibleList* pControl = new Gwen::Controls::CollapsibleList( this );
			pControl->SetSize( 100, 200 );
			pControl->SetPos( 10, 10 );
			{
				Gwen::Controls::CollapsibleCategory* cat = pControl->Add( GWEN_T("Category One") );
				cat->Add( GWEN_T("Hello") );
				cat->Add( GWEN_T("Two") );
				cat->Add( GWEN_T("Three") );
				cat->Add( GWEN_T("Four") );
			}
			{
				Gwen::Controls::CollapsibleCategory* cat = pControl->Add( GWEN_T("Shopping") );
				cat->Add( GWEN_T("Special") );
				cat->Add( GWEN_T("Two Noses") );
				cat->Add( GWEN_T("Orange ears") );
				cat->Add( GWEN_T("Beer") );
				cat->Add( GWEN_T("Three Eyes") );
				cat->Add( GWEN_T("Special") );
				cat->Add( GWEN_T("Two Noses") );
				cat->Add( GWEN_T("Orange ears") );
				cat->Add( GWEN_T("Beer") );
				cat->Add( GWEN_T("Three Eyes") );
				cat->Add( GWEN_T("Special") );
				cat->Add( GWEN_T("Two Noses") );
				cat->Add( GWEN_T("Orange ears") );
				cat->Add( GWEN_T("Beer") );
				cat->Add( GWEN_T("Three Eyes") );
			}
			{
				Gwen::Controls::CollapsibleCategory* cat = pControl->Add( GWEN_T("Category One") );
				cat->Add( GWEN_T("Hello") );
				cat->Add( GWEN_T("Two") );
				cat->Add( GWEN_T("Three") );
				cat->Add( GWEN_T("Four") );
			}
		}
};



DEFINE_UNIT_TEST( CollapsibleList, GWEN_T("CollapsibleList") );
