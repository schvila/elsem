// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#include "stdafx.h"
#include "TemplateTestAuto.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Use  TAD specialization Instead of the marco IMPLEMENT_CONFIG 
IMPLEMENT_TADTEST( CTemplateTestAuto, CTadTestElementEx )

// Call base class constructor (use the correct template).
CTemplateTestAuto::CTemplateTestAuto( CString strKey ) : CTadTestElementEx( strKey )
{
    // Attention don't forget tot store resource handle of this Test Brick in the TadGroupBase DLL
    // as first action in the constructor:
    SetTestBrickResourceHandle( AfxGetStaticModuleState()->m_hCurrentResourceHandle );
        
    // Set the labels of the action/result list
    SetLabels( StringFromId( IDS_ACTION ), StringFromId( IDS_RESULT ) );
    SetProperty( TAD_TEST_RUNS_REMOTE, TRUE );     // test is allowed remotely (default is local)

    // Add the test step functions that will be called one after the other.
    // USAGE:  --- way of working with test function lists --- 
    //   static behavior (test construction/destruction):
    //      - use AddFunction(...) to register all test steps before test execution
    //        e.g. in the constructor of the test or in ReadRegistryData()
    //      - The default implementation of the test extStep() method will run all registered 
    //        functions. 
    //      - The destructor of the test will cleanup the function list for you
    //   dynamic behavior (test execution):   
    //      - Add more functions in the extInit() call (first action when the test is started)
    //        and/or add them in function already added before.
    //      - During extClose() all additionlly added fucntons are removed automatically!
    //      - It is posible to alter the test flow during the test:
    //         - SetTestStep() can be used to define the index of the next test function
    //           With e.g. FindStepIndexOfAction() the index of a test step can be found
    //         - StopOn() can be used to change the stop condition based on the severity level


    
}

CTemplateTestAuto::~CTemplateTestAuto ()
{
    
}

//
//  Get the chance to read data from the registry 
//

void CTemplateTestAuto::ReadRegistryData( CPeoRegistry& Reg )
{
    //  Example on Reading your own registry data using 'ReadReg()'
    CTadTestElementEx::ReadRegistryData( Reg );
    
    //BOOL bEventLog;
    //bEventLog = Reg.GetEventLog();
    
    // mandatory keys
    //Reg.SetEventLog(TRUE);
   
    // optional keys
    //Reg.SetEventLog(FALSE);
    
    //ReadReg ( Reg, _T("registryName"), m_myparameter );
    
    // restore original setting
    //Reg.SetEventLog(bEventLog);

    AddFunction( IDS_TOOLID, &CTemplateTestAuto::DoTesttoolID, 1000 );
}

// These functions are used to provide automatic action result reporting for every test step
void CTemplateTestAuto::FunctionBegin( const long lActionID )
{
    // Report to TAD that the teststep is starting.
    AddResult( lActionID, IDS_START, TAD_INFO );
}

void CTemplateTestAuto::FunctionEnd( const long lActionID, const TadSeverity SeverityLevel )
{
    // Report the end of this teststep.
    long lResultID = IDS_FAILED;
    switch ( SeverityLevel )    
    {
        case TAD_INFO:    lResultID = IDS_OK;       break;
        case TAD_WARNING: lResultID = IDS_WARNING;  break;
        case TAD_ERROR:   lResultID = IDS_FAILED;   break;
        default:  
        lResultID = IDS_FAILED;
        break;
    }
    //TimeOutput();	
    AddResult( lActionID, lResultID, SeverityLevel );
}

void CTemplateTestAuto::FunctionSkipped( const long lActionID )
{
    // Set skipped as error.
    AddResult( lActionID, IDS_SKIPPED, TAD_INFO );
}

HRESULT CTemplateTestAuto::extInit(TadAuthorization authorizationLevel, TadExecMode execMode)
{
    return CTadTestElementEx::extInit(authorizationLevel, execMode);
}

HRESULT CTemplateTestAuto::extClose(TadTestResult *pResult)
{
    CTadTestElementEx::extClose(pResult);
    return S_OK; // not intended to return errors yourself
}

// Export the name of the test.
HRESULT CTemplateTestAuto::extGetDescription( LPOLESTR* descr )
{
  CFeiComSrvString d ( descr );
  d = StringFromId( IDS_TOOLID );    
  return S_OK;
}

void CTemplateTestAuto::DoTesttoolID( TadSeverity* pSeverityLevel )
{
    *pSeverityLevel = TAD_INFO;
}

