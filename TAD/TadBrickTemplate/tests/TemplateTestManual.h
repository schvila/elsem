// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

// Forward declarations.
//class CPeoRegistry;

// Class implementing the functionality to add notes to the output.
// This class derives from CXTManualTest : 
// It is a manual test because :
//       - A monitor test cannot write/log in the output. The advantage of
//         a monitor test should be that this kind of test is automatically 
//         without using the start button.
//       - Manual action is needed to use the functionality 
// Drawback of manual test : Test has to be started using the start button 
//                           just to add a note.
class CTemplateTestManual : public CTadTestManual
{
  DECLARE_TADTEST (CTemplateTestManual)
    
  public:
    explicit CTemplateTestManual ( CString strKey );
    virtual ~CTemplateTestManual ();

  protected:
    // Standard methods for TAD-execution.   
    virtual void ReadRegistryData (CPeoRegistry& Reg);  

    // Test steps.
    void DoMonitorTest (TadSeverity* pSeverityLevel);
};
