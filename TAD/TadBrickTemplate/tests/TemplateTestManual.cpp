// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

// Purpose  : Performs the logging of notes to the output terminal

#include "stdafx.h"

#include "TemplateTestManual.h"

// se the constructor for explanation
//#include "TemplateTestManual_ui2test.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Automatic registration of this test.
IMPLEMENT_TADTEST (CTemplateTestManual, CTadTestManual)

// Call base class constructor (use the correct template).
CTemplateTestManual::CTemplateTestManual(CString strKey) : CTadTestManual(strKey)
{
    // Set resource handle.
    SetTestBrickResourceHandle(AfxGetStaticModuleState()->m_hCurrentResourceHandle); 


    // The following TEM_TAD\tad\shared\include\TemplateTestManual_ui2test.h file should be defined
    // and its content should be something like:
    /*// Copyright (c) 1995-2013 by FEI Company. All rights reserved.
      // Purpose  : interface UI - test
      //            This interface is used to pass notes ( strings ) 
      //            from the UI ( NotesInOutputTerminal.ocx ) 
      //            to the server ( class CNotesInOutput in AOTadDataLogging.dll ).
      //            These notes are meant for the output terminal.          

      #pragma once

      // Name of the variable
      #define VAR_NOTE_IN_OUTPUT     _T("NoteInOutputVar")
    */
    /* The following lines initializes the shared variable.
    // Create the TAD user interface <--> TAD test variable.
    CreateVariable(VAR_NOTE_IN_OUTPUT);
    SetVariable(VAR_NOTE_IN_OUTPUT, _T(""));*/
}

// Destructor.
CTemplateTestManual::~CTemplateTestManual()
{
}

//
//  Get the chance to read data from the registry 
//
void CTemplateTestManual::ReadRegistryData (CPeoRegistry& Reg)
{
    CTadTestManual::ReadRegistryData ( Reg );

    AddFunction(&CTemplateTestManual::DoMonitorTest, 0);
}


// Monitor updates of notes to insert to log.
void CTemplateTestManual::DoMonitorTest ( TadSeverity* pSeverityLevel )
{
  *pSeverityLevel = TAD_INFO;
  
  /*
  long VarNoteInOutputIndex = VariableNameToIndex (VAR_NOTE_IN_OUTPUT);

  long lWaitResult=0xFF; //just an initialization value ( 0 == WAIT_VARIABLE )

  while ( WAIT_ABORT != lWaitResult )
  { 
      CString textToDisplay;

      if (lWaitResult == VarNoteInOutputIndex)
      {
          GetVariable(VAR_NOTE_IN_OUTPUT, textToDisplay);

          // String is parsed on the presence of carriage returns.
          // Strings are split up and logged separately, 
          // codes for carriage return and line feed are removed.
          int position = 0 ;
          // 0xd is the ascii code for carriage return.
          while((position = textToDisplay.Find(0xd)) >= 0)
          {
              CString cstr_temp = textToDisplay.Left(position);
              AddReportItem ( TAD_INFO, CAT_ALL, cstr_temp);

              //amount of characters is index of last character + 1 
              textToDisplay.Delete(0,position+1);
              
              //0xa is code for line feed.
              if ( textToDisplay[0] == 0xa )
                  textToDisplay.Delete(0,1);
          }
          AddReportItem ( TAD_INFO, CAT_ALL, textToDisplay);
      }
      lWaitResult = Wait ( INFINITE );
  }
  */
  
  // The user pressed the 'stop' button to stop this test. To prevent
  // getting the Aborted state in the TAD-UI (for this test), the aborted flag
  // is reset.
  SetTestAborted ( false );
}
