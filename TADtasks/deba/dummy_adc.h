#ifndef _DUMMY_ADC_H_
#define _DUMMY_ADC_H_

#include <string>
#include "psff/drivers/adc.h"
#include "psff/utils/logger.h"

class DummyAdc : public ::psff::Adc
{
public:
    /*! Default constructor
     */
    DummyAdc(::std::string name, uint8_t resolution = 10, uint8_t channelCount = 1, Adc::Channel channelMask = CH_0);
    
    /*! Destructor
     */
    ~DummyAdc();

	void SetValue(Channel channelMask, Value value);
    
    /*! Check if driver is busy (conversion pending) 
     */
    bool IsBusy() override;
    
    /*! Get ADC resolution
     *  \return Number of bits
     */
    uint8_t GetResolution() const override;
    
    /*! Get number of available channels
     *  \return Number of available channels
     */
    uint8_t GetChannelCount() const override;
    
    /*! Get available channel mask
     *  \return Mask of available channels
     */
    Channel GetAvailableChannels() const override;
    
    /*! Multiple channel synchronous (blocking) conversion
     *  \param channelMask Channel mask to be converted
     *  \param adcResults Pointer to array of ValueDesc for storing conversion results
     *  \return RES_OK on success
     */
    Result ConvertSync(Channel channelMask, ValueDesc* adcResults) override;

    /*! Multiple channel synchronous (blocking) conversion
     *  \param channelMask Channel mask to be converted
     *  \param adcResults Pointer to array of ValueDesc for storing conversion results
     *  \param callback Callback to be called after conversion finishes
     *  \return RES_OK on success
     */
    Result ConvertAsync(Channel channelMask, ValueDesc* adcResults, AsyncCallback callback) override;

	//********** Derived from Peripheral class

	/*! Enable all peripheral interrupts
	*/
	void EnableInterrupts() override;

	/*! Disable all peripheral interrupts
	*/
	void DisableInterrupts() override;

private:
    
    //! Copy constructor
    DummyAdc(const DummyAdc&);

    //! Assign operator
    DummyAdc& operator = (const DummyAdc&);

	::std::string m_name;
    
    uint8_t m_resolution;
    
    uint8_t m_chanCount;
    
    Channel m_chanMask;

	::psff::Logger m_logger;

	Value m_values[32];

};
    
#endif // _DUMMY_ADC_H_