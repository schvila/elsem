// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

/*
    This file implements the dll support for your brick.
    This DLL is special in that is both supports ATL (for
    registration etc.) and MFC.
    
    If your brick is a DLL your brick will be loaded by
    brickbox.exe. Brickbox has been implemented using ATL,
    without MFC support. Therefore it is not possible to 
    implement this DLL as an extension DLL. 
    To this DLL a CWinApp object has been added, which 
    supports MFC.

    If you need access to the resources located in this DLL
    and they cannot be found by the application add the 
    following line of code just prior to the call which 
    needs the resource:
        
    AfxSetResourceHandle( AfxGetStaticModuleState() -> m_hCurrentResourceHandle );
*/

#include "stdafx.h"
#include "TadBrickTemplate_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ATL support

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_CoTadBrickTemplateBrick, CTadBrickTemplateBrick )
END_OBJECT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Create an instance of CWinApp object this holds
// all the code we need for resource managment.

CTadBrickTemplateDLLApp theTadBrickTemplateApp;

/////////////////////////////////////////////////////////////////////////////

BOOL CTadBrickTemplateDLLApp::InitInstance()
{
    BOOL bOK = FALSE;

    _Module.Init( ObjectMap, m_hInstance );		// Initialize COM interface map
    CEventLog::RegisterEventSource( _T( "FEI TadBrickTemplate Brick" ), _Module.m_hInst, NULL, FACILITY, FACILITY );
    bOK = CWinApp::InitInstance();				// Call initinstance of CWinApp,
                                                // probably initializes some MFC.
    return bOK;
}

/////////////////////////////////////////////////////////////////////////////

int CTadBrickTemplateDLLApp::ExitInstance( )
{
    _Module.Term();

    return CWinApp::ExitInstance();
}

////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE
// and if MFC doesn't need anything from this DLL anymore

STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return ( (AfxDllCanUnloadNow() == S_OK ) && ( _Module.GetLockCount()==0)) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID* ppv )
{
    return _Module.GetClassObject( rclsid, riid, ppv );
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    CEventLog::RegisterEventSource( _T( "FEI TadBrickTemplate Brick" ), _Module.m_hInst, NULL, FACILITY, FACILITY );

    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    CEventLog::UnregisterEventSource( _T( "FEI TadBrickTemplate Brick" ), FACILITY, FACILITY );
    _Module.UnregisterServer(TRUE);
    return S_OK;
}
