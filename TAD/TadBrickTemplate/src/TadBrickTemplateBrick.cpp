// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//
// Location : TEM_TAD\tad\TadBrickTemplate\src
//
// All rights reserved. This file includes confidential and 
// proprietary information of FEI Company.
//
// History
//
// 2010-12-10 gevens   Creation
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////////
//CTadBrickTemplateBrick

HRESULT CTadBrickTemplateBrick::extCreate()
{
	CString strBrickName = GetName();
	CTadBrickTemplateModule* pModule = new CTadBrickTemplateModule( strBrickName, TRUE );
	// no need to check for NULL-ness of pModule, for in that case
	// an exception (bad_alloc...?) will be thrown!
	// ASSERT( pModule ); // unneccesary!
	SetModule( pModule );
	GetModule()->SetBrick( this );	
	return CMFCBrick::extCreate();
}


CTadBrickTemplateBrick :: ~CTadBrickTemplateBrick( )
{
	RemoveModule();
}

void CTadBrickTemplateBrick::RemoveModule()
{
	if ( m_pMFCModule != NULL )
	{
		delete m_pMFCModule;
		m_pMFCModule = NULL;
	}
}
