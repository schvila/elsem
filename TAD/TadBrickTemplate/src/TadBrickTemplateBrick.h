// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

//////////////////////////////////////////////////////////////////////////////
//CTadBrickTemplateBrick

class CTadBrickTemplateBrick: 
	public CMFCBrick,
	public CComCoClass<CTadBrickTemplateBrick, &CLSID_CoTadBrickTemplateBrick>
	// class needs to inherit from CComCoClass in order to easily support the
	// COM interface
{
	/*++
	{\b Description}
		TadBrickTemplateBrick class.
	--*/

public:
	BEGIN_COM_MAP( CTadBrickTemplateBrick )
		COM_INTERFACE_ENTRY(ILifecycle)
		COM_INTERFACE_ENTRY_CHAIN(CFeiBrick)
		COM_INTERFACE_ENTRY_CHAIN(CMFCBrick)
	END_COM_MAP( )

	/*
	The COM map is the mechanism that exposes interfaces on an object to a client through 
	QueryInterface. CComObjectRootEx::InternalQueryInterface only returns pointers for 
	interfaces in the COM map. Start your interface map with the BEGIN_COM_MAP macro, 
	add entries for each of your interfaces with the COM_INTERFACE_ENTRY macro or one of 
	its variants, and complete the map with the END_COM_MAP macro.
	*/


	virtual ~CTadBrickTemplateBrick( );
	/*++
	{\b Description}
		Specific brick destructor, destroys the associated module and clears the
		association to it.
	--*/

	virtual HRESULT extCreate();
	/*++
	{\b Description}
		creates the specific module and fills the association to the module.
	--*/
	

	DECLARE_REGISTRY_RESOURCEID( IDR_REGISTRY1 )
	
protected:
	void RemoveModule();
	/*++
	{\b Description}
		Removes the associated module
	--*/

	/* PUT YOUR BRICK SPECIFIC STUFF HERE */

};
