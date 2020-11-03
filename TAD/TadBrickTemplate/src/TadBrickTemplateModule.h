// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

//++Module: TadBrickTemplate

//////////////////////////////////////////////////////////////////////
//Forward definitions

class CMFCModule;
class CMFCManager;
class CTadBrickTemplateManager;
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//CTadBrickTemplateModule

class CTadBrickTemplateModule : public CMFCModule
	/*++
	{\b Description}
		The TadBrickTemplate module class.
	--*/
{
	DECLARE_CONFIG(CTadBrickTemplateModule)

public:

	CTadBrickTemplateModule(const CString& strName, BOOL bExposeManagerInterface = FALSE );
	/*++
		{\b Description}
		Constructor, takes care of storing the name.
	--*/

	virtual HRESULT Create();
	/*++
	{\b Description}
		This function checks whether the TadBrickTemplate module is in the
		correct {\uldb Module startup phase}{\v HelpEntryModuleStartupPhase} by
		calling the corresponding CMFCModule function.

		If not, the function does nothing but return E_FAIL.
	--*/
};
