// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

class CTemplateTestMonitor : public CTadMonitor
{
    DECLARE_TADTEST (CTemplateTestMonitor)
    
    public:
        explicit CTemplateTestMonitor (CString strKey);
        virtual ~CTemplateTestMonitor ();

        //  Get the chance to read data from the registry
        virtual void ReadRegistryData (CPeoRegistry& Reg);

        // test step reporting
        /*virtual void FunctionBegin( const long lActionID );
        virtual void FunctionEnd( const long lActionID, const TadSeverity SeverityLevel );
        virtual void FunctionSkipped( const long lActionID );*/

    private:
        // Test specific data/members
        CString m_strParam;
};



