
#include "Gwen/Util/ControlFactory.h"
#include "Gwen/Controls.h"

namespace Gwen
{
	namespace ControlFactory
	{

		class Button_Factory : public Gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( Button_Factory, Gwen::ControlFactory::Base )
				{
				}

				virtual Gwen::String Name() { return GWEN_T("Button"); }
				virtual Gwen::String BaseName() { return GWEN_T("Label"); }

				virtual Gwen::Controls::Base* CreateInstance( Gwen::Controls::Base* parent )
				{
					Gwen::Controls::Button* pControl = new Gwen::Controls::Button( parent );
					pControl->SetSize( 100, 20 );
					pControl->SetText( GWEN_T("New Button") );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( Button_Factory );

	}
}
