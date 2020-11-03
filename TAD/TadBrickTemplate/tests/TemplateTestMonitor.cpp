// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

// Purpose: Describe the purpose of this test

#include "stdafx.h"
#include "TemplateTestMonitor.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Use TAD specialization instead of the marco IMPLEMENT_CONFIG 
IMPLEMENT_TADTEST(CTemplateTestMonitor, CTadMonitor)

// Call base class constructor (use the correct template).
CTemplateTestMonitor::CTemplateTestMonitor(CString strKey) : CTadMonitor(strKey)
{
    // Attention don't forget to store resource handle of this Test Brick in the TadGroupBase DLL
    // as first action in the constructor:
    SetTestBrickResourceHandle (AfxGetStaticModuleState () -> m_hCurrentResourceHandle);

    // Set the labels of the action/result list
    // tab creates new column; digits determine % of screen width used by column. 
    // Total does not add up to 100% to allow for vertical scroll bar
    SetLabels (_T("Action|50"), _T("Result|46"));
}

CTemplateTestMonitor::~CTemplateTestMonitor()
{

}

//
// Read the data that is needed by the test from the registry. This function will be called by
// the TAD framework. The function will first read the system's networkcard-configuration. It will
// then read the test's configuration data from registry and use the networkcard data to determine
// the test parameters.
// - Reg: reference to part of the registry, provided by framework
//
void CTemplateTestMonitor::ReadRegistryData (CPeoRegistry& Reg)
{
    // Have the base class read its registry data.
    CTadTestElementEx::ReadRegistryData( Reg );

    // Now read the 'own' registry settings.
    ReadReg(Reg, "ParamName", m_strParam );
    // Reg.Read("ParamName", m_strParam );
}