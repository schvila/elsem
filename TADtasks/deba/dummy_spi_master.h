#ifndef _DUMMY_SPI_MASTER_
#define _DUMMY_SPI_MASTER_

#include <string>

#include "psff/setup.h"

#include "psff/drivers/spi_master.h"
#include "psff/drivers/gpio.h"
#include "psff/drivers/interrupt_ctrl.h"
#include "psff/utils/logger.h"

class DummySpiMaster : public ::psff::SpiMaster
{
public:

    /*! Constructor
     */
    DummySpiMaster(::std::string name, ::psff::GpioPin* pinMiso = nullptr, ::psff::GpioPin* pinMosi = nullptr, ::psff::GpioPin* pinSck = nullptr, ::psff::GpioPin* pinCs = nullptr,	bool useHwSS = false);

    /*! Destructor
     */
    ~DummySpiMaster();

    /*! Init SPI master
     *  \param clkFrequency SCK signal frequency in Hz
     *  \param cpol CPOL settings
     *  \param cpha CPHA settings
     *  \param msbFirst Most significant bit first
     *  \return 0 on success, error code otherwise
     */
	Result Init(const ::psff::Frequency clkFrequency, Cpol cpol = CPOL_SCK0, Cpha cpha = CPHA_1ST, bool msbFirst = true) override;
    
    /*! Get bit count per transferred word (8 bits typically)
     *  \return Bit count
     */
    uint8_t GetBitCount() const override;

    /*! Change SCK frequency (may not be supported by all platforms)
     *  \param frequency SCK frequency in Hz
     *  \return Result enum
     */
    Result SetSckFrequency(const ::psff::Frequency frequency) override;

    /*! Get current SCK frequency
     *  \return Current SCK frequency in Hz
     */
	::psff::Frequency GetSckFrequency() const override;
    
    /*! Synchronous write (blocking until end of transaction)
     *  \param bufferTx Out data buffer (to be sent), can be null
     *  \param bufferRx In data buffer (to be received), can be null
     *  \param bufferSize Input data buffer size (number of bytes to transceive)
     *  \return Result enum
     */
    Result TransceiveSync(const uint8_t* bufferTx, uint8_t* bufferRx, uint16_t bufferSize) override;

    /*! Synchronous write (blocking until end of transaction)
     *  \param csPin Slave select pin to be driven
     *  \param bufferTx Out data buffer (to be sent), can be null
     *  \param bufferRx In data buffer (to be received), can be null
     *  \param bufferSize Input data buffer size (number of bytes to transceive)
     *  \return Result enum
     */
    Result TransceiveSync(::psff::GpioPin& csPin, const uint8_t* bufferTx, uint8_t* bufferRx, uint16_t bufferSize) override;
    
        /*! Asynchronous write (non-blocking)
     *  \param bufferTx Out data buffer (to be sent), can be null
     *  \param bufferRx In data buffer (to be received), can be null
     *  \param bufferSize Input data buffer size (number of bytes to transceive)
     *  \return Result enum
     */
    Result TransceiveAsync(const uint8_t* bufferTx, uint8_t* bufferRx, uint16_t bufferSize, AsyncCallback callback) override;

    /*! Asynchronous write (non-blocking)
     *  \param csPin Slave select pin to be driven
     *  \param bufferTx Out data buffer (to be sent), can be null
     *  \param bufferRx In data buffer (to be received), can be null
     *  \param bufferSize Input data buffer size (number of bytes to transceive)
     *  \return Result enum
     */
    Result TransceiveAsync(::psff::GpioPin& csPin, const uint8_t* bufferTx, uint8_t* bufferRx, uint16_t bufferSize, AsyncCallback callback) override;
    
    //********** Derived from Peripheral class
    
    /*! Enable all peripheral interrupts
     */
    void EnableInterrupts() override;

    /*! Disable all peripheral interrupts
     */
    void DisableInterrupts() override;

private:

    ::std::string m_name;

	::psff::Frequency m_freq;

	::psff::Logger m_logger;

};

/*! @} */

#endif // _DUMMY_SPI_MASTER_
