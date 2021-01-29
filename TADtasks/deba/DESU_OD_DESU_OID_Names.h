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

// INDEX 1000 - 
#define OID_DESU_BASEODVERSION                      0x1000
#define OID_DESU_APPVERSION                         0x1001
#define OID_DESU_APPERROR                           0x1002
#define OID_DESU_APPSTATE                           0x1003
#define OID_DESU_APPCOMMAND                         0x1004
#define OID_DESU_APPNAME                            0x1005
#define OID_DESU_END_OF_INDEX1000                   0x1006
// INDEX 2000 - 
// DESU (detector supplies) block diagram
/* [image:file:DESU_BLOCK_DIAGRAM.png]
 */
// 
// DESU power supply control
// DESU HV_GEN (High Voltage Generator) Control
/* [image:file:DESU_SUP_HV_GEN_STATEMACHINE.png]
 */
#define OID_DESU_HVGENSTATE                         0x2000
#define OID_DESU_HVGENCOMMAND                       0x2001
#define OID_DESU_ADCHVGEN                           0x2002
#define OID_DESU_ADC4KV                             0x2003
#define OID_DESU_DAC4KV                             0x2004
// DESU SUP_90V Control
/* [image:file:DESU_SUP_90V_STATEMACHINE.png]
 */
#define OID_DESU_SUP90VSTATE                        0x2005
#define OID_DESU_SUP90VCOMMAND                      0x2006
#define OID_DESU_CBLDET90V1                         0x2007
#define OID_DESU_CBLDET90V2                         0x2008
#define OID_DESU_ADC90V                             0x2009
// DESU SUP_LVDFE Control
#define OID_DESU_SUPLVDFESTATE                      0x200A
#define OID_DESU_SUPLVDFECOMMAND                    0x200B
#define OID_DESU_ADCFSUPTEST                        0x200C
// DESU SUP_800V/250V Control
/* [image:file:DESU_SUP_REG_STATEMACHINE.png]
 */
#define OID_DESU_SUP800V250VSTATE                   0x200D
#define OID_DESU_SUP800V250VCOMMAND                 0x200E
#define OID_DESU_DACSUP800VREGULATE                 0x200F
#define OID_DESU_ADC800V                            0x2010
// DESU relay control
// DESU REL_10KV Control
/* [image:file:DESU_REL_10KV_STATEMACHINE.png]
 */
#define OID_DESU_REL10KVSTATE                       0x2011
#define OID_DESU_REL10KVCOMMAND                     0x2012
#define OID_DESU_ADC10KV                            0x2013
// DESU REL_STAGE Control
/* [image:file:DESU_REL_STAGE_STATEMACHINE.png]
 */
#define OID_DESU_RELSTAGESTATE                      0x2014
#define OID_DESU_RELSTAGECOMMAND                    0x2015
#define OID_DESU_ADCSTAGECURRENTMEAS                0x2016
#define OID_DESU_ADCSTAGECURRENTMEASAVERAGE         0x2017
#define OID_DESU_ADCSTAGECURRENTMEASMOVINGAVERAGE    0x2018
#define OID_DESU_STAGECURRENTOFFSET                 0x2019
#define OID_DESU_STAGECURRENTMULTIPLIER             0x201A
// touch alarm
#define OID_DESU_CBLDETSTAGE                        0x201B
#define OID_DESU_CBLDETTAMOTION                     0x201C
#define OID_DESU_TAACTIVE                           0x201D
#define OID_DESU_TADETECTED                         0x201E
// overvoltage/undervoltage protection
#define OID_DESU_PROTECTIONSTATE                    0x201F
#define OID_DESU_PROTECTIONCOMMAND                  0x2020
#define OID_DESU_END_OF_INDEX2000                   0x2021
// INDEX 8000 - 
// TAD
#define OID_DESU_BOARDREVISION                      0x8000
#define OID_DESU_FIRMWAREVERSION                    0x8001
#define OID_DESU_ADC5VREFTEST                       0x8002
#define OID_DESU_ADC24VTEST                         0x8003
#define OID_DESU_POWEROK                            0x8004
#define OID_DESU_HVINTERLOCK                        0x8005
#define OID_DESU_LVINTERLOCK                        0x8006
#define OID_DESU_TADETECTEDRAW                      0x8007
#define OID_DESU_NFUEFIRST                          0x8008
#define OID_DESU_NFUELAST                           0x8009
#define OID_DESU_NFUECOUNT                          0x800A
#define OID_DESU_NFUEODFIRST                        0x800B
#define OID_DESU_NFUEODLAST                         0x800C
#define OID_DESU_NFUEODCOUNT                        0x800D
#define OID_DESU_ALIVECOUNT                         0x800E
#define OID_DESU_UNIQUEID                           0x800F
#define OID_DESU_ERRORSTRING                        0x8010
#define OID_DESU_END_OF_INDEX8000                   0x8011