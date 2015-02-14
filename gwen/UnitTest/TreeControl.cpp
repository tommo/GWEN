#include "Gwen/UnitTest/UnitTest.h"
#include "Gwen/Controls/TreeControl.h"

using namespace Gwen;

class TreeControl : public GUnit
{
	public:

		GWEN_CONTROL_INLINE( TreeControl, GUnit )
		{
			{
				Gwen::Controls::TreeControl* ctrl = new Gwen::Controls::TreeControl( this );
				ctrl->AddNode( GWEN_T("Node One") );
				Gwen::Controls::TreeNode* pNode = ctrl->AddNode( GWEN_T("Node Two") );
				pNode->AddNode( GWEN_T("Node Two Inside") );
				pNode->AddNode( GWEN_T("Eyes") );
				pNode->AddNode( GWEN_T("Brown") )->AddNode( GWEN_T("Node Two Inside") )->AddNode( GWEN_T("Eyes") )->AddNode( GWEN_T("Brown") );
				pNode->AddNode( GWEN_T("More") );
				pNode->AddNode( GWEN_T("Nodes") );
				ctrl->AddNode( GWEN_T("Node Three") );
				ctrl->SetBounds( 30, 30, 200, 200 );
				ctrl->ExpandAll();
			}
			{
				Gwen::Controls::TreeControl* ctrl = new Gwen::Controls::TreeControl( this );
				ctrl->AllowMultiSelect( true );
				ctrl->AddNode( GWEN_T("Node One") );
				Gwen::Controls::TreeNode* pNode = ctrl->AddNode( GWEN_T("Node Two") );
				pNode->AddNode( GWEN_T("Node Two Inside") );
				pNode->AddNode( GWEN_T("Eyes") );
				Gwen::Controls::TreeNode* pNodeTwo = pNode->AddNode( GWEN_T("Brown") )->AddNode( GWEN_T("Node Two Inside") )->AddNode( GWEN_T("Eyes") );
				pNodeTwo->AddNode( GWEN_T("Brown") );
				pNodeTwo->AddNode( GWEN_T("Green") );
				pNodeTwo->AddNode( GWEN_T("Slime") );
				pNodeTwo->AddNode( GWEN_T("Grass") );
				pNodeTwo->AddNode( GWEN_T("Pipe") );
				pNode->AddNode( GWEN_T("More") );
				pNode->AddNode( GWEN_T("Nodes") );
				ctrl->AddNode( GWEN_T("Node Three") );
				ctrl->SetBounds( 240, 30, 200, 200 );
				ctrl->ExpandAll();
			}
		}

};



DEFINE_UNIT_TEST( TreeControl, GWEN_T("TreeControl") );
