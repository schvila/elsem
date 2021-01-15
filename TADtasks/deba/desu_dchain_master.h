#ifndef _DESU_DCHAIN_MASTER_H_
#define _DESU_DCHAIN_MASTER_H_

#include "psff/os/mutex.h"
#include "dchain/slave_board.h"
#include "dchain/master.h"
#include "dchain/board_ids.h"

#include "psff/utils/callback.h"
#include "psff/utils/logger.h"

class DesuDChainMaster
{
public:

    typedef ::psff::Callback<void(bool isConnected)> ConnectionChangeCallback;

    typedef ::psff::Callback<void(uint8_t status0, uint8_t flags)> SrqReceivedCallback;

    DesuDChainMaster(::dchain::Master& master, ::dchain::Address slaveAddr = (DCHAIN_BOARD_ID_DESU << 4));

    void SetConnectionChangeCallback(ConnectionChangeCallback callback);

    void SetSrqReceivedCallback(SrqReceivedCallback callback);

	bool IsSlaveConnected() const;

    ::dchain::Error ResetBoard();

	::dchain::Error GetHvGenState(uint8_t& value);

	bool HvGenStateHasChanged(bool clear = false);

	uint8_t GetHvGenStateLastValue();

	::dchain::Error GetHvGenCommand(uint8_t& value);

	::dchain::Error SetHvGenCommand(uint8_t value);

	::dchain::Error GetAdcHvGen(uint16_t& value);

	::dchain::Error GetAdc4kV(uint16_t& value);

	::dchain::Error GetSup90VState(uint8_t& value);

	bool Sup90VStateHasChanged(bool clear = false);

	uint8_t GetSup90VStateLastValue();

	::dchain::Error GetSup90VCommand(uint8_t& value);

	::dchain::Error SetSup90VCommand(uint8_t value);

	::dchain::Error GetCblDet90V1(uint8_t& value);

    bool CblDet90V1HasChanged(bool clear = false);

    uint8_t GetCblDet90V1LastValue();

	::dchain::Error GetCblDet90V2(uint8_t& value);

    bool CblDet90V2HasChanged(bool clear = false);

    uint8_t GetCblDet90V2LastValue();

	::dchain::Error GetAdc90V(uint16_t& value);

    ::dchain::Error GetSupLvdfeState(uint8_t& value);

    bool SupLvdfeStateHasChanged(bool clear = false);

    uint8_t GetSupLvdfeStateLastValue();

    ::dchain::Error GetSupLvdfeCommand(uint8_t& value);

    ::dchain::Error SetSupLvdfeCommand(uint8_t value);

    ::dchain::Error GetAdcFSupTest(uint16_t& value);

	::dchain::Error GetSup800V250VState(uint8_t& value);

	bool Sup800V250VStateHasChanged(bool clear = false);

	uint8_t GetSup800V250VStateLastValue();

	::dchain::Error GetSup800V250VCommand(uint8_t& value);

	::dchain::Error SetSup800V250VCommand(uint8_t value);

	::dchain::Error GetDACSup800VRegulate(uint16_t& value);

	::dchain::Error SetDACSup800VRegulate(uint16_t value);

	::dchain::Error GetAdc800V(uint16_t& value);

	::dchain::Error GetRel10kVState(uint8_t& value);

	bool Rel10kVStateHasChanged(bool clear = false);

	uint8_t GetRel10kVStateLastValue();

	::dchain::Error GetRel10kVCommand(uint8_t& value);

	::dchain::Error SetRel10kVCommand(uint8_t value);

	::dchain::Error GetAdc10kV(uint16_t& value);

	::dchain::Error GetRelStageState(uint8_t& value);

	bool RelStageStateHasChanged(bool clear = false);

	uint8_t GetRelStageStateLastValue();

	::dchain::Error GetRelStageCommand(uint8_t& value);

	::dchain::Error SetRelStageCommand(uint8_t value);

	::dchain::Error GetAdcStageCurrentMeas(uint16_t& value);

	::dchain::Error GetCblDetStage(uint8_t& value);

    bool CblDetStageHasChanged(bool clear = false);

    uint8_t GetCblDetStageLastValue();

	::dchain::Error GetCblDetTaMotion(uint8_t& value);

    bool CblDetTaMotionHasChanged(bool clear = false);

    uint8_t GetCblDetTaMotionLastValue();

	::dchain::Error GetTaActive(uint8_t& value);

    bool TaActiveHasChanged(bool clear = false);

    uint8_t GetTaActiveLastValue();

	::dchain::Error GetTaDetected(uint8_t& value);

    bool TaDetectedHasChanged(bool clear = false);

    uint8_t GetTaDetectedLastValue();

    //::dchain::Error GetTaDetectedRaw(uint8_t& value);

    //bool TaDetectedRawHasChanged(bool clear = false);

    //uint8_t GetTaDetectedRawLastValue();

	::dchain::Error GetFirmwareVersion(uint8_t index, uint8_t& value);

    ::dchain::Error GetHardwareRevision(uint8_t& value);

	::dchain::Error GetAdc5vrefTest(uint16_t& value);

	::dchain::Error GetAdc24vTest(uint16_t& value);

	::dchain::Error GetPowerCheck(uint16_t& value);

    bool PowerCheckHasChanged(bool clear = false);

    uint16_t GetPowerCheckLastValue();

    ::dchain::Error GetHvInterlock(uint8_t& value);

    bool HvInterlockHasChanged(bool clear = false);

    uint16_t GetHvInterlockLastValue();

    ::dchain::Error GetLvInterlock(uint8_t& value);

    bool LvInterlockHasChanged(bool clear = false);

    uint16_t GetLvInterlockLastValue();

    ::dchain::Error SetDAC4kV(uint16_t value);

    ::dchain::Error GetDAC4kV(uint16_t& value);

	::dchain::Error GetNfueFirst(uint32_t& value);

    bool NfueFirstHasChanged(bool clear = false);

    uint32_t GetNfueFirstLastValue();

	::dchain::Error GetNfueLast(uint32_t& value);

    bool NfueLastHasChanged(bool clear = false);

    uint32_t GetNfueLastLastValue();

	::dchain::Error GetNfueCount(uint32_t& value);

    bool NfueCountHasChanged(bool clear = false);

    uint32_t GetNfueCountLastValue();

    ::dchain::Error GetAliveCount(uint32_t& value);

    ::dchain::Error GetProtectionState(uint8_t& value);

    bool ProtectionStateHasChanged(bool clear);

    uint8_t GetProtectionStateLastValue();

    ::dchain::Error GetProtectionCommand(uint8_t& value);

    ::dchain::Error SetProtectionCommand(uint8_t value);

    ::dchain::Error GetAdcStageCurrentMeasAverage(uint16_t& value);

    ::dchain::Error GetAdcStageCurrentMeasMovingAverage(uint16_t& value);

    ::dchain::Error GetDesuUniqueID(uint8_t* destination, size_t maxSize);

    ::dchain::Error GetErrorString(::std::string& value);

private:

	void ReconnectToSlave();

	void ServiceRequestCallback(::dchain::Address address, uint8_t flags);
	void BoardDiscoveredCallback(::dchain::Address address);
	void BoardDisconnectedCallback(::dchain::Address address);
	void FrameOrderErrorCallback(::dchain::Address address);
	void SlaveResetDetectedCallback(::dchain::Address address);

    
    ::psff::Mutex m_mutex;
    
    ::dchain::Master& m_master; 

	::dchain::Address m_slaveAddr;
    
    ::psff::Logger m_logger;

	bool m_isConnected;

	uint8_t m_lastHvGenState;

	bool m_changedHvGenState;

	uint8_t m_lastSup90VState;

	bool m_changedSup90VState;

    uint8_t m_lastCblDet90V1;

    bool m_changedCblDet90V1;

    uint8_t m_lastCblDet90V2;

    bool m_changedCblDet90V2;

    uint8_t m_lastSupLvdfeState;

    bool m_changedSupLvdfeState;

	uint8_t m_lastSup800V250VState;

	bool m_changedSup800V250VState;

	uint8_t m_lastRel10kVState;

	bool m_changedRel10kVState;

	uint8_t m_lastRelStageState;

	bool m_changedRelStageState;

    uint8_t m_lastCblDetStage;

    bool m_changedCblDetStage;

    uint8_t m_lastCblDetTaMotion;

    bool m_changedCblDetTaMotion;

    uint8_t m_lastTaActive;

    bool m_changedTaActive;

    uint8_t m_lastTaDetected;

    bool m_changedTaDetected;

    //uint8_t m_lastTaDetectedRaw;

    //bool m_changedTaDetectedRaw;

	uint16_t m_lastPowerCheck;

	bool m_changedPowerCheck;

    uint8_t m_lastHvInterlock;

    bool m_changedHvInterlock;

    uint8_t m_lastLvInterlock;

    bool m_changedLvInterlock;

    uint32_t m_lastNfueFirst;

    bool m_changedNfueFirst;

    uint32_t m_lastNfueLast;

    bool m_changedNfueLast;

    uint32_t m_lastNfueCount;

    bool m_changedNfueCount;

    ConnectionChangeCallback m_connCallback;
    
    bool m_lastReportedState;

    uint8_t m_lastProtectionState;

    bool m_changedProtectionState;

    SrqReceivedCallback m_srqCallback;
};


#endif // _DESU_DCHAIN_MASTER_H_ 
