// Script for eSPY application version 1.10.6.0
// Script recorded at Tuesday, 10 November 2020 08:25:10
LogMessage('connect: ConnectToSCUViaFeiCommConnector');
ConnectToSCUViaFeiCommConnector( "DESU" );
Sleep( 200 );
LogMessage('conneceted: ConnectToSCUViaFeiCommConnector');
SetODValue( 'DESU', 'RelStageCommand', 3, 2 );
SetODValue( 'DESU', 'RelStageCommand', 3, 4 );
SetODValue( 'DESU', 'RelStageCommand', 3, 5 );
LogMessage('***RelStageCommands DONE');
Sleep( 1000 );
// Using Espy objects 0x8044 (SSFE_0_TADConfig) and 0x8045 (SSFE_0_TADRead
LogMessage('***GET AdcStageCurrentMeas');
var tadRead =  GetODValue(1, 'AdcStageCurrentMeas', 3);
Sleep( 300 );
LogMessage('***GET AdcStageCurrentMeas');
tadRead =  GetODValue(1, 'AdcStageCurrentMeas', 3);
Sleep( 300 );
LogMessage('***GET AdcStageCurrentMeas');
tadRead =  GetODValue(1, 'AdcStageCurrentMeas', 3);
Sleep( 300 );
DisconnectSCU();

