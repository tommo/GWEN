
#include "Gwen/Util/ControlFactory.h"
#include "Gwen/Controls.h"

namespace Gwen
{
	namespace ControlFactory
	{

		using namespace Gwen;

		namespace Properties
		{
			class ControlName : public Gwen::ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( ControlName,  GWEN_T("The control's name") );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::Format(  GWEN_T("%S"), ctrl->GetName().c_str() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						ctrl->SetName( str  );
					}
			};

			class Position : public Gwen::ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Position,  GWEN_T("Sets the position of the control") );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::Format(  GWEN_T("%i %i"), ctrl->X(), ctrl->Y() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						int x, y;

						if ( GWEN_SSCANF( str.c_str(), GWEN_T("%i %i"), &x, &y ) != 2 ) { return; }

						ctrl->SetPos( x, y );
					}

					int NumCount() { return 2; };

					Gwen::String NumName( int i )
					{
						if ( i == 0 ) { return GWEN_T("x"); }

						return GWEN_T("y");
					}

					float NumGet( Controls::Base* ctrl, int i )
					{
						if ( i == 0 ) { return ctrl->X(); }

						return ctrl->Y();
					}

					void NumSet( Controls::Base* ctrl, int i, float f )
					{
						if ( i == 0 )   { ctrl->SetPos( f, ctrl->Y() ); }
						else            { ctrl->SetPos( ctrl->X(), f ); }
					}
			};

			class Margin : public Gwen::ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Margin, GWEN_T("Sets the margin of a docked control") );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						Gwen::Margin m = ctrl->GetMargin();
						return Utility::Format( GWEN_T("%i %i %i %i"), m.left, m.top, m.right, m.bottom );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						Gwen::Margin m;

						if ( GWEN_SSCANF( str.c_str(), GWEN_T("%i %i %i %i"), &m.left, &m.top, &m.right, &m.bottom ) != 4 ) { return; }

						ctrl->SetMargin( m );
					}

					int NumCount() { return 4; };

					Gwen::String NumName( int i )
					{
						if ( i == 0 ) { return GWEN_T("left"); }

						if ( i == 1 ) { return GWEN_T("top"); }

						if ( i == 2 ) { return GWEN_T("right"); }

						return GWEN_T("bottom");
					}

					float NumGet( Controls::Base* ctrl, int i )
					{
						Gwen::Margin m = ctrl->GetMargin();

						if ( i == 0 ) { return m.left; }

						if ( i == 1 ) { return m.top; }

						if ( i == 2 ) { return m.right; }

						return m.bottom;
					}

					void NumSet( Controls::Base* ctrl, int i, float f )
					{
						Gwen::Margin m = ctrl->GetMargin();

						if ( i == 0 ) { m.left = f; }

						if ( i == 1 ) { m.top = f; }

						if ( i == 2 ) { m.right = f; }

						if ( i == 3 ) { m.bottom = f; }

						ctrl->SetMargin( m );
					}
			};

			class Size: public Gwen::ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Size, GWEN_T("The with and height of the control") );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						return Utility::Format( GWEN_T("%i %i"), ctrl->Width(), ctrl->Height() );
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						int w, h;

						if ( GWEN_SSCANF( str.c_str(), GWEN_T("%i %i"), &w, &h ) != 2 ) { return; }

						ctrl->SetSize( w, h );
					}

					int NumCount() { return 2; };

					Gwen::String NumName( int i )
					{
						if ( i == 0 ) { return GWEN_T("w"); }

						return GWEN_T("h");
					}

					float NumGet( Controls::Base* ctrl, int i )
					{
						if ( i == 0 ) { return ctrl->Width(); }

						return ctrl->Height();
					}

					void NumSet( Controls::Base* ctrl, int i, float f )
					{
						if ( i == 0 )   { ctrl->SetSize( f, ctrl->Height() ); }
						else            { ctrl->SetSize( ctrl->Width(), f ); }
					}
			};

			class Dock : public Gwen::ControlFactory::Property
			{
					GWEN_CONTROL_FACTORY_PROPERTY( Dock, GWEN_T("How the control is to be docked") );

					UnicodeString GetValue( Controls::Base* ctrl )
					{
						switch ( ctrl->GetDock() )
						{
							case Pos::Left:
								return GWEN_T("Left");

							case Pos::Fill:
								return GWEN_T("Fill");

							case Pos::Right:
								return GWEN_T("Right");

							case Pos::Top:
								return GWEN_T("Top");

							case Pos::Bottom:
								return GWEN_T("Bottom");
						}

						return GWEN_T("None");
					}

					void SetValue( Controls::Base* ctrl, const UnicodeString & str )
					{
						if ( str == GWEN_T("Fill") ) { ctrl->Dock( Pos::Fill ); }

						if ( str == GWEN_T("Left") ) { ctrl->Dock( Pos::Left ); }

						if ( str == GWEN_T("Right") ) { ctrl->Dock( Pos::Right ); }

						if ( str == GWEN_T("Top") ) { ctrl->Dock( Pos::Top ); }

						if ( str == GWEN_T("Bottom") ) { ctrl->Dock( Pos::Bottom ); }

						if ( str == GWEN_T("None") ) { ctrl->Dock( Pos::None ); }
					}

					int OptionNum() { return 6; }

					Gwen::UnicodeString OptionGet( int i )
					{
						if ( i == 0 ) { return GWEN_T("None"); }

						if ( i == 1 ) { return GWEN_T("Left"); }

						if ( i == 2 ) { return GWEN_T("Right"); }

						if ( i == 3 ) { return GWEN_T("Top"); }

						if ( i == 4 ) { return GWEN_T("Bottom"); }

						return GWEN_T("Fill");
					}
			};

		} // namespace Properties


		class Base_Factory : public Gwen::ControlFactory::Base
		{
			public:

				GWEN_CONTROL_FACTORY_CONSTRUCTOR( Base_Factory, Gwen::ControlFactory::Base )
				{
					AddProperty( new Properties::ControlName() );
					AddProperty( new Properties::Dock() );
					AddProperty( new Properties::Position() );
					AddProperty( new Properties::Size() );
					AddProperty( new Properties::Margin() );
				}

				virtual Gwen::String Name() { return GWEN_T("Base"); }
				virtual Gwen::String BaseName() { return GWEN_T(""); }

				virtual Gwen::Controls::Base* CreateInstance( Gwen::Controls::Base* parent )
				{
					Gwen::Controls::Base* pControl = new Gwen::Controls::Base( parent );
					pControl->SetSize( 100, 100 );
					return pControl;
				}
		};


		GWEN_CONTROL_FACTORY( Base_Factory );

	}
}
