//------------------------------------------------------------------------------
// <autogenerated>
//
//     Date: 11/18/2020 17:54
//
//     This code was generated by the ODDTool (Runtime Version: 1.9.0.0)
//     from file "DESU_OD.xml".
//     Supported HEP and ODD Primitives specification from 1.7 to 1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
// </autogenerated>
//------------------------------------------------------------------------------

// include required interface
#include "OD_types.h"
#include "OD_ObjectInitStructs.h"

/*-------------------------------------------------------------------------------------------*/
/*---------  OBJECT DICTIONARY ID = GA ------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------*/

#ifndef ODD_RAM_ITEM
#define ODD_RAM_ITEM
#endif

#ifndef ODD_RAM_COLLECTION_ITEM
#define ODD_RAM_COLLECTION_ITEM ODD_RAM_ITEM
#endif

// INDEX 1000 - 

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1000[3];
const T_RomInit_eVersion3_8 pbROM_GA_0x1000 = {(MBUInt8)OD_VERSION3_8, "BaseODVersion", 1, 10, 0};  //TYPE, NAME, X, Y, Z

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1001[3];
const T_RomInit_eVersion3_8 pbROM_GA_0x1001 = {(MBUInt8)OD_VERSION3_8, "AppVersion", 0, 0, 1};  //TYPE, NAME, X, Y, Z

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1002_data[8*4];
ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1002[10];
const T_RomInit_eError pbROM_GA_0x1002 = {(MBUInt8)OD_ERROR, "AppError", 0, //TYPE, NAME, CURRENT_ERROR
                                        {OD_RO_ACCESS, 8*4, MB_NULL, pbRAM_GA_0x1002_data}, //bDataType, dwSizeInBytes, pbROMdata, pbRAMdata
                                        0, 8}; //OLDEST_ERROR_INDEX, MAX_HISTORY_SIZE

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1003[4];
const T_RomInit_eState pbROM_GA_0x1003 = {(MBUInt8)OD_STATE, "AppState", 0}; //TYPE, NAME, STATE

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1004[8];
const T_RomInit_eCommand pbROM_GA_0x1004 = {(MBUInt8)OD_COMMAND, "AppCommand", 0,0};  //TYPE, NAME, COMMAND, PREVIOUS_COMMAND

const MBChar pbROM_GA_0x1005_String[] = "Generic Application";
ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1005[sizeof(pbROM_GA_0x1005_String)];
const T_RomInit_eString pbROM_GA_0x1005 = {(MBUInt8)OD_STRING, "AppName", pbROM_GA_0x1005_String};  //TYPE, NAME, STRING

//ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x1006[0];  // no memory RAM
const T_RomInit_eNullDevice pbROM_GA_0x1006 = {(MBUInt8)OD_NULL_DEVICE, "End of index=1000"}; //TYPE, NAME

// INDEX 2000 - 

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2000[3];
const T_RomInit_eVersion3_8 pbROM_GA_0x2000 = {(MBUInt8)OD_VERSION3_8, "FirmwareVersion", BUILD_APP_VERSION_MAJOR, BUILD_APP_VERSION_MINOR, BUILD_APP_VERSION_PATCH};  //TYPE, NAME, X, Y, Z

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2001[4];
const T_RomInit_eConfiguration pbROM_GA_0x2001 = {(MBUInt8)OD_CONFIGURATION, "FWBuildNr", BUILD_APP_VERSION_BUILD};  //TYPE, NAME, PARAMETER

const MBChar pbROM_GA_0x2002_String[] = "DESU";
ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2002[sizeof(pbROM_GA_0x2002_String)];
const T_RomInit_eString pbROM_GA_0x2002 = {(MBUInt8)OD_STRING, "FWLogicalName", pbROM_GA_0x2002_String};  //TYPE, NAME, STRING

const MBUInt8 pbROM_GA_0x2003_Data[] = {0x0};
ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2003[9];
const T_RomInit_eData pbROM_GA_0x2003 = {(MBUInt8)OD_DATA, "HWIDs", sizeof(pbROM_GA_0x2003_Data), sizeof(pbROM_GA_0x2003_Data), //TYPE, NAME, ACTUAL_SIZE, MAX_SIZE
                                       {OD_CO_ACCESS, sizeof(pbROM_GA_0x2003_Data), pbROM_GA_0x2003_Data, MB_NULL}, //bDataType, dwSizeInBytes, pbROMdata, pbRAMdata
                                       FALSE}; //DATA_CHANGED

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2004[7+5];
const T_RomInit_eApplication pbROM_GA_0x2004 = {(MBUInt8)OD_APPLICATION, "DESU", 1,  //TYPE, NAME, APPL_ID
                                              "FPIP", 0, 0, 0, BUILD_APP_VERSION_MAJOR, BUILD_APP_VERSION_MINOR, BUILD_APP_VERSION_PATCH};  //SUPPORTED_PROTOCOLS, LIFECYCLE_COMMAND, LIFECYCLE_STATUS, LIFECYCLE_ERROR, VERSION_X, VERSION_Y, VERSION_Z

ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2005[4];
const T_RomInit_eConfiguration pbROM_GA_0x2005 = {(MBUInt8)OD_CONFIGURATION, "InstanceID", 0xFFFFFFFF};  //TYPE, NAME, PARAMETER

//ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x2006[0];  // no memory RAM
const T_RomInit_eNullDevice pbROM_GA_0x2006 = {(MBUInt8)OD_NULL_DEVICE, "End of index=2000"}; //TYPE, NAME

// INDEX 8000 - 

//ODD_RAM_ITEM MBUInt8 pbRAM_GA_0x8000[0];  // no memory RAM
const T_RomInit_eNullDevice pbROM_GA_0x8000 = {(MBUInt8)OD_NULL_DEVICE, "End of index=8000"}; //TYPE, NAME

ODD_RAM_COLLECTION_ITEM OD_T_ObjectCollection  pCollectionTable_GA[] =
{
    // INDEX 1000 - 
    {OID_GA_BASEODVERSION                    ,  5,     pVersion38,   pbRAM_GA_0x1000, (MBUInt8*)&pbROM_GA_0x1000, 0, 0},
    {OID_GA_APPVERSION                       ,  5,     pVersion38,   pbRAM_GA_0x1001, (MBUInt8*)&pbROM_GA_0x1001, 0, 0},
    {OID_GA_APPERROR                         ,  6,         pError,   pbRAM_GA_0x1002, (MBUInt8*)&pbROM_GA_0x1002, 0, 0},
    {OID_GA_APPSTATE                         ,  3,         pState,   pbRAM_GA_0x1003, (MBUInt8*)&pbROM_GA_0x1003, 0, 0},
    {OID_GA_APPCOMMAND                       ,  4,       pCommand,   pbRAM_GA_0x1004, (MBUInt8*)&pbROM_GA_0x1004, 0, 0},
    {OID_GA_APPNAME                          ,  3,        pString,   pbRAM_GA_0x1005, (MBUInt8*)&pbROM_GA_0x1005, 0, 0},
    {OID_GA_END_OF_INDEX1000                 ,  2,    pNullDevice,         MB_NULL, (MBUInt8*)&pbROM_GA_0x1006, 0, 0},
    // INDEX 2000 - 
    {OID_GA_FIRMWAREVERSION                  ,  5,     pVersion38,   pbRAM_GA_0x2000, (MBUInt8*)&pbROM_GA_0x2000, 0, 0},
    {OID_GA_FWBUILDNR                        ,  3, pConfiguration,   pbRAM_GA_0x2001, (MBUInt8*)&pbROM_GA_0x2001, 0, 0},
    {OID_GA_FWLOGICALNAME                    ,  3,        pString,   pbRAM_GA_0x2002, (MBUInt8*)&pbROM_GA_0x2002, 0, 0},
    {OID_GA_HWIDS                            ,  6,          pData,   pbRAM_GA_0x2003, (MBUInt8*)&pbROM_GA_0x2003, 0, 0},
    {OID_GA_DESU                             , 10,   pApplication,   pbRAM_GA_0x2004, (MBUInt8*)&pbROM_GA_0x2004, 0, 0},
    {OID_GA_INSTANCEID                       ,  3, pConfiguration,   pbRAM_GA_0x2005, (MBUInt8*)&pbROM_GA_0x2005, 0, 0},
    {OID_GA_END_OF_INDEX2000                 ,  2,    pNullDevice,         MB_NULL, (MBUInt8*)&pbROM_GA_0x2006, 0, 0},
    // INDEX 8000 - 
    {OID_GA_END_OF_INDEX8000                 ,  2,    pNullDevice,         MB_NULL, (MBUInt8*)&pbROM_GA_0x8000, 0, 0},
};

#define OD_NR_OF_COLLECTIONS_GA 15
