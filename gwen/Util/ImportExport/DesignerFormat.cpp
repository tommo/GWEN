
#include "Gwen/Util/ImportExport.h"
#include "Bootil/Bootil.h"


class DesignerFormat : public Gwen::ImportExport::Base
{
	public:

		DesignerFormat();

		virtual Gwen::String Name() { return GWEN_T("Designer"); }

		virtual bool CanImport() { return true; }
		virtual void Import( Gwen::Controls::Base* pRoot, const Gwen::String & strFilename );

		virtual bool CanExport() { return true; }
		virtual void Export( Gwen::Controls::Base* pRoot, const Gwen::String & strFilename );

		void ExportToTree( Gwen::Controls::Base* pRoot, Bootil::Data::Tree & tree );
		void ImportFromTree( Gwen::Controls::Base* pRoot, Bootil::Data::Tree & tree );

};

GWEN_IMPORTEXPORT( DesignerFormat );


DesignerFormat::DesignerFormat()
{
}

void DesignerFormat::Import( Gwen::Controls::Base* pRoot, const Gwen::String & strFilename )
{
	Bootil::BString strContents;

	if ( !Bootil::File::Read( strFilename, strContents ) )
	{ return; }

	Bootil::Data::Tree tree;
	Bootil::Data::Json::Import( tree, strContents );

	if ( !tree.HasChild( GWEN_T("Controls") ) ) { return; }  // false

	ImportFromTree( pRoot, tree.GetChild( "Controls" ) );
}

void DesignerFormat::ImportFromTree( Gwen::Controls::Base* pRoot, Bootil::Data::Tree & tree )
{
	ControlFactory::Base* pRootFactory = ControlFactory::Find( "Base" );

	if ( pRoot->UserData.Exists( "ControlFactory" ) )
	{ pRootFactory = pRoot->UserData.Get<ControlFactory::Base*> ( GWEN_T("ControlFactory") ); }

	if ( tree.HasChild( "Properties" ) )
	{
		Bootil::Data::Tree & Properties = tree.GetChild( "Properties" );
		BOOTIL_FOREACH( p, Properties.Children(), Bootil::Data::Tree::List )
		{
			ControlFactory::Property* prop = pRootFactory->GetProperty( p->Name() );

			if ( !prop ) { continue; }

			if ( p->HasChildren() )
			{
				BOOTIL_FOREACH( pc, p->Children(), Bootil::Data::Tree::List )
				{
					prop->NumSet( pRoot, pc->Name(), pc->Var<float>() );
				}
			}
			else
			{
				pRootFactory->SetControlValue( pRoot, p->Name(), Bootil::String::Convert::ToWide( p->Value() ) );
			}
		}
	}

	if ( tree.HasChild( GWEN_T("Children") ) )
	{
		Bootil::Data::Tree & ChildrenObject = tree.GetChild( GWEN_T("Children") );
		BOOTIL_FOREACH( c, ChildrenObject.Children(), Bootil::Data::Tree::List )
		{
			Bootil::BString strType = c->ChildValue( GWEN_T("Type") );
			ControlFactory::Base* pFactory = ControlFactory::Find( strType );

			if ( !pFactory ) { continue; }

			Gwen::Controls::Base* pControl = pFactory->CreateInstance( pRoot );

			if ( !pControl ) { continue; }

			// Tell the control we're here and we're queer
			{
				int iPage = c->ChildVar<int> ( GWEN_T("Page"), 0 );
				pRootFactory->AddChild( pRoot, pControl, iPage );
			}
			pControl->SetMouseInputEnabled( true );
			pControl->UserData.Set( GWEN_T("ControlFactory"), pFactory );
			ImportFromTree( pControl, *c );
		}
	}
}

void DesignerFormat::Export( Gwen::Controls::Base* pRoot, const Gwen::String & strFilename )
{
	Bootil::Data::Tree tree;
	ExportToTree( pRoot, tree );
	Bootil::BString strOutput;

	if ( Bootil::Data::Json::Export( tree, strOutput, true ) )
	{
		Bootil::File::Write( strFilename, strOutput );
	}
}

void DesignerFormat::ExportToTree( Gwen::Controls::Base* pRoot, Bootil::Data::Tree & tree )
{
	Bootil::Data::Tree* me = &tree;

	if ( pRoot->GetTypeName() == GWEN_T("DocumentCanvas") )
	{
		me = &tree.AddChild( GWEN_T("Controls") );
	}
	else
	{
		me = &tree.AddChild();
	}

	me->SetChild( GWEN_T("Type"), pRoot->GetTypeName() );

	//
	// Set properties from the control factory
	//
	if ( pRoot->UserData.Exists( GWEN_T("ControlFactory") ) )
	{
		Bootil::Data::Tree & props = me->AddChild( GWEN_T("Properties") );
		ControlFactory::Base* pCF = pRoot->UserData.Get<ControlFactory::Base*> ( GWEN_T("ControlFactory") );
		// Save the ParentPage
		{
			int iParentPage = pCF->GetParentPage( pRoot );

			if ( iParentPage != 0 )
			{
				me->SetChildVar( GWEN_T("Page"), iParentPage );
			}
		}

		while ( pCF )
		{
			for ( ControlFactory::Property::List::const_iterator
					it = pCF->Properties().begin(), itEnd = pCF->Properties().end();
					it != itEnd; ++it )
			{
				if ( ( *it )->NumCount() > 0 )
				{
					Bootil::Data::Tree & prop = props.AddChild( ( *it )->Name() );

					for ( int i = 0; i < ( *it )->NumCount(); i++ )
					{
						prop.SetChildVar<float> ( ( *it )->NumName( i ), ( *it )->NumGet( pRoot, i ) );
					}

					continue;
				}

				props.SetChild( ( *it )->Name(), Gwen::Utility::UnicodeToString( ( *it )->GetValue( pRoot ) ).c_str() );
			}

			pCF = pCF->GetBaseFactory();
		}
	}

	ControlList list = ImportExport::Tools::GetExportableChildren( pRoot );

	if ( !list.list.empty() )
	{
		Bootil::Data::Tree & children = me->AddChild( GWEN_T("Children") );
		ControlList::List::iterator it = list.list.begin();
		ControlList::List::iterator itEnd = list.list.end();

		while ( it != itEnd )
		{
			ExportToTree( *it, children );
			++it;
		}
	}
}
