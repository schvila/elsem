// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////////
//CMFCModule implementation

//needed to be able to use REPORTEX macro
CPeoModule* theModule = NULL;

IMPLEMENT_CONFIG( CTadBrickTemplateModule, CMFCModule );

CTadBrickTemplateModule::CTadBrickTemplateModule( const CString& strName, BOOL bExposeManagerInterface) : CMFCModule( strName, bExposeManagerInterface, _Module.m_hInst )
{

    InitializeOLE(FALSE);		// FALSE indicates that OLE does not need to be initialized
                                // However this method also creates (access to) the ROT ):
                                // and that is what we need.
    
    theModule = this;
} 


HRESULT CTadBrickTemplateModule::Create()
{
    HRESULT hr = CMFCModule::Create();

    if ( hr == S_OK )
    {
        CString strCurrentRegistryKey;
        CString strManagerName;
        
        CFeiBrick* pBrick = GetBrick();
        ASSERT( pBrick );
        if ( pBrick == NULL )
        {
            return E_UNEXPECTED;
        }
        
        strManagerName = pBrick->GetName();
        strManagerName += _T( "Mgr" );
        
        //Get the registry root
        strCurrentRegistryKey = pBrick->GetRegistryKey();
        CString strRegKey = strCurrentRegistryKey + "\\" + strManagerName;

        CTadBrickTemplateManager *pManager = new CTadBrickTemplateManager( strRegKey, this );

        // Add the manager to the module.
        AddManager( pManager, strManagerName );
        SetFunctionalElementManager( pManager ) ;

        if ( ManagerExists( strManagerName ) )
        {
            pManager->SetParent( this );		// Link to the manager
            hr = pManager->Create();
        } 
        else 
        {
            hr = E_UNEXPECTED;
        }
    }

    return hr;
}

