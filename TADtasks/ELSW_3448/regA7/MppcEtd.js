// Script for eSPY application version 1.10.6.0
// Script recorded at Tuesday, 10 November 2020 08:25:10
var NewInfraDetectors = 2;
LogMessage('connect: ConnectToSCUViaFeiCommConnector');
ConnectToSCUViaFeiCommConnector( "Detectors" );
Sleep( 200 );
LogMessage('conneceted: ConnectToSCUViaFeiCommConnector');
LogMessage('MppcEtd PT1000')
var v =  GetODValue(NewInfraDetectors, 'MOFE_0_TMeasOut', 3);
v = GetODValue(NewInfraDetectors, 'MOFE_0_MaxTempSensCal', 3);
LogMessage('MppcEtd BiasFlow')
var r = GetODValue(NewInfraDetectors, 'MOFE_0_BiasRange', 3);
var b = GetODValue(NewInfraDetectors, 'MOFE_0_Bias', 3);
var c = GetODValue(NewInfraDetectors, 'MOFE_0_CtrlCheck', 3);
DisconnectSCU();

