// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

// To create an Autotest, derive a class from the class 'CTadTestElementEx'
class CTemplateTestAuto : public CTadTestElementEx 
{
    // NOTE !!!! don't DECLARE_CONFIG (CTemplateTestAuto) but the TAD specialized toolIDion:
    DECLARE_TADTEST( CTemplateTestAuto )
    
    public:
        explicit CTemplateTestAuto( CString strKey );
        virtual ~CTemplateTestAuto();

        //  Read registry setting.
        virtual void ReadRegistryData( CPeoRegistry& Reg );

        //  Basic functionality which can be overruled when required:
        virtual HRESULT extGetDescription( LPOLESTR* descr );
        virtual HRESULT extInit( TadAuthorization authorizationLevel, TadExecMode execMode );
        virtual HRESULT extClose( TadTestResult *pResult );

        // These functions are optional for adding automatic Action/result reporting per test step
        using CTadTestElementEx::FunctionBegin;
        virtual void FunctionBegin( const long lActionID );
        using CTadTestElementEx::FunctionEnd;
        virtual void FunctionEnd( const long lActionID, const TadSeverity SeverityLevel );
        using CTadTestElementEx::FunctionSkipped;
        virtual void FunctionSkipped( const long lActionID );   

  protected:
        // Example Test step Function members.
        void DoTesttoolID( TadSeverity* pSeverityLevel );
};

