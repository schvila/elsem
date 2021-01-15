#ifndef APPL_CONTROLLER_MODULE_INCLUDED_H
#define APPL_CONTROLLER_MODULE_INCLUDED_H

#include "mbus/APPB/CAppl.h"
#include "mbus/HEPP/CCommand.h"
#include "mbus/HEPP/CError.h"
#include "mbus/HEPP/CState.h"
#include "mbus/HEPP/CConfiguration.h"
#include "mbus/HEPP/CString.h"
#include "mbus/HEPP/CData.h"

#include "psff/utils/callback.h"
#include "psff/utils/logger.h"
#include "psff/utils/system_time.h"

#include "dchain/master.h"
#include "desu_dchain_master.h"

#define DESU_APP_ID			(1)

namespace Desu
{

class Application : public CAppl
{
public:

    static const uint32_t DESU_FIRST_CONN_TIMEOUT_MS = 5000;

    enum SpecificAppError
    {
        SAERR_DESU_DISCONNECTED = 0x01000000,            //!< DESU board was disconnected (no power, no connection, etc.)
        SAERR_DESU_VER_MISMATCH = 0x01000001             //!< DESU board FW version does not match SCU app version
    };

    enum AppCommand
    {
        ACMD_NONE = 0,
        ACMD_RESET_DESU_BOARD = 10
    };

    enum NFUEError
    {
        NERR_REL10KVSTAT_RANGE = 1,
        NERR_REL10KVSTAT_WRITE,
        NERR_POWEROK_RANGE,
        NERR_POWEROK_WRITE,
        NERR_HVINTERLOCK_RANGE,
        NERR_LVINTERLOCK_RANGE
    };

	Application(DesuDChainMaster& master);

	::psff::Logger& GetLogger();

    void ResetDesuBoard();

    CError m_AppError;

    CCommand m_AppCommand;

	CCommand m_HvGenCommand;

	CCommand m_Sup90VCommand;

    CCommand m_SupLvdfeCommand;

	CCommand m_Sup800V250VCommand;

	CCommand m_Rel10kVCommand;

	CCommand m_RelStageCommand;

    CState m_TaActive;

    CState m_TaDetected;

	CError   m_NfueLast;

    CConfiguration m_NfueOdFirst;

    CError m_NfueOdLast;

    CConfiguration m_NfueOdCount;

    CCommand m_ProtectionCommand;

    CData m_UniqueId;

    CString m_ErrorString;

    void LogNFUE(uint32_t uiErrorNumber);

private:

    void DesuBoardConnectedCallback(bool isConnected);

	static void ReadCallback(MBUInt16 wIndex, MBUInt8 bSubindex, MBUInt8* pbData);
	static void WriteCallback(MBUInt16 wIndex, MBUInt8 bSubindex, MBUInt8* pbData);

    // Inherited methods from Appl
    virtual HEPP_E_LifecycleError SpecificCreate( void );

    virtual HEPP_E_LifecycleError SpecificStart( void );

    virtual HEPP_E_LifecycleError SpecificShutdown( void );

    virtual void ExecPeriodicStateUpdate( void );

    void SrqReceivedCallback(uint8_t status8, uint8_t flags);

	void CheckStateChange(bool doRead = false);

	static DesuDChainMaster* s_master;

    ::psff::Logger m_logger;

	::psff::Timestamp m_dchainUpdateTimer;

    bool m_desuWasConnected;

    bool m_initialDesuConnErrReported;

    ::psff::Timestamp m_desuConnTimeout;

};

}

#endif /* APPL_CONTROLLER_MODULE_INCLUDED_H */

