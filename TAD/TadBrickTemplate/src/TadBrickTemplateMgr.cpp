// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////////
//CTadBrickTemplateManager

IMPLEMENT_CONFIG( CTadBrickTemplateManager, CMFCManager )

CTadBrickTemplateManager::CTadBrickTemplateManager( const CString& ListGroup, CMFCModule* pModule ) : 
    CMFCManager( ListGroup )
{
    
    SetParent( pModule );

    // BEGIN TAD SPECIFIC:    
    // NOTE: For TAD only the factory element is required !!!
    //       All test elements based on AuxTadGroupExtension.Dll are automatically created 
    //       at run time
    m_ElementMap.SetAt( CTadGroupFactory::GetClassType(), TADFACTORY_ELEMENT );
    // END TAD SPECIFIC  
}

CTadBrickTemplateManager::~CTadBrickTemplateManager()
{
    // empty
}

CTadBrickTemplateModule* CTadBrickTemplateManager::GetModule()
{ 
    return dynamic_cast<CTadBrickTemplateModule*>(GetParent()); 
}

HRESULT CTadBrickTemplateManager::Create()
{
    HRESULT hr = CMFCManager::Create(); 
    if ( SUCCEEDED(hr) )
    {	// Create elements based on registry.
        long lResult = GetRegistryData( );
        if ( lResult != ERROR_SUCCESS )
        {
            hr = E_UNEXPECTED;
        }
    }
    return hr;
}


///////////////////////////////////////////////////////////////////////////////
// OnAddElement
CPeoConfigElement* CTadBrickTemplateManager :: OnAddElement( const CString& strType, const CString& strKey ) {
    CPeoConfigElement* pElement = NULL;


    pElement = CMFCManager::OnAddElement( strType, strKey ); // first call the parent
    if ( pElement == NULL ) 
    {
        long nElementType;
        if ( m_ElementMap.Lookup( strType, nElementType ) )
        {
            // TODO:
            // Add a case for each Element type your manager supports

            switch( nElementType ) 
            {
            
            // BEGIN TAD SPECIFIC:    
            case TADFACTORY_ELEMENT:
                // factory that can automatically create test elements based on
                // AuxTadGroupExtension.Dll (contains a runtime replacement of a factory like this)
                pElement = new CTadGroupFactory( strKey );
                break;

            default:
                // Type is not recognized
                REPORT ( E_TadBrickTemplate_Factory, strType, SEV_ERROR, CAT_INITIALIZATION );
                break;
                // END TAD SPECIFIC
            }

            if ( pElement ) 
            {
                // The parent of the element is this manager.
                CMFCModule *pMod = static_cast<CMFCModule*>(GetParent());
                pElement->SetModule( pMod );
                pElement->SetParent( this );

                // recursively call the create of the element
                // someone has to do it and our manager's Create is never called!!!! (yet)
                HRESULT hr = pElement->Create( ); 

                if ( hr != S_OK ) 
                {

                    delete pElement;
                    pElement = NULL;
                }
            }
            //We should have an elemented created at this point
            ASSERT( pElement );
        }
    }
    return pElement;
}
