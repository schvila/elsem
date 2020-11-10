// Script for eSPY application version 1.10.6.0
// Script recorded at Tuesday, 10 November 2020 08:25:10
LogMessage('connect: ConnectToSCUViaFeiCommConnector');
ConnectToSCUViaFeiCommConnector( "Detectors" );
Sleep( 200 );
LogMessage('conneceted: ConnectToSCUViaFeiCommConnector');
SetODValue( 'NewInfraDetectors', 'SSFE_0_TADConfig', 3, 5 );
// Using Espy objects 0x8044 (SSFE_0_TADConfig) and 0x8045 (SSFE_0_TADRead
var tadRead =  GetODValue(2, 'SSFE_0_TADRead', 3);
LogMessage( 'SSFE_0_TADRead '+ tadRead);
DisconnectSCU();

