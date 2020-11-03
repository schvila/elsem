// Copyright (c) 1995-TEMPLATE_COPYRIGHT by FEI Company. All rights reserved.

#pragma once

//++Module: TadBrickTemplate


// Define a type to map class names to ID's
typedef CMap<CString,LPCTSTR,long,long> CMapNameToID;

//////////////////////////////////////////////////////////////////////////////
//Forward declarations

class CMFCManager;
class CMFCModule;

//////////////////////////////////////////////////////////////////////////////
//CTadBrickTemplateManager

class CTadBrickTemplateManager : public CMFCManager 
{

	DECLARE_CONFIG( CTadBrickTemplateManager)
	
	//++ Construction and destruction
public:
	CTadBrickTemplateManager( const CString& ListGroup, CMFCModule* pModule);
	/*++
	{\b Description}
		constructor; As all CElements, it saves its classtype.
	--*/        

	virtual ~CTadBrickTemplateManager();
	/*++
	{\b Description}
		Destructor; does nothing.
	--*/

	CTadBrickTemplateModule* GetModule();
	/*++
	{\b Description}
		Get the module pointer.
	--*/

	virtual HRESULT Create();
	/*++
	{\b Description}
		Create elements based on registry.
	--*/

protected:
	// enum defines a unique element identifies for element instantiation
	enum ElementIds
	{
		TADFACTORY_ELEMENT
	};
	
	virtual CPeoConfigElement* OnAddElement (const CString& strType, const CString& strKey);
	/*++
	{\b Description}
		This function creates an object of the class and name as given in Key, 
		if not already existing.

	{\b Parameters}
	-	Type: Is the class name of the object to create (without the letter 'C').
	-	Key: Name of the registry key. The key should look like:
			.....\ElementName 	
		where ElementName is the name of the object to create.
	-	Return: 
		-	pointer to the newly created object. It it could be created; otherwise NULL.
	--*/
private:
	CMapNameToID	m_ElementMap;
	/*++
		This CMap data structure is used to map class names to (long)integer identifiers
	--*/

};
