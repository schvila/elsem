#ifndef _DUMMY_GPIO_PIN_H_
#define _DUMMY_GPIO_PIN_H_

#include <string>
#include "psff/drivers/gpio.h"
#include "psff/utils/logger.h"

/*! Dummy GPIO pin
*/
class DummyGpioPin : public psff::GpioPin
{
public:
	DummyGpioPin(std::string pinName);

	//! Destructor
	~DummyGpioPin();

	//! Get port
	psff::GpioPort& GetPort();

	//! Get underlying port handle
	psff::PeripheralHandle GetPortHandle();

	psff::GpioPinMask GetMask() const;

	//! Set pin to log. H
	void Set();

	//! Set pin to log. L
	void Clear();

	//! Invert pin
	void Invert();

	/*! Raw write pin value
	*  \param mask Value to be written
	*/
	void Write(bool value);

	/*! Raw read pin value
	*  \return pin raw value
	*/
	bool Read();

	/*! Check whether pin is in log. H
	*  \return true when in log. H
	*/
	bool IsSet();

	/*! Check whether pin is in log. L
	*  \return true when in log. L
	*/
	bool IsCleared();

	//! Configure pin as output
	void Output();

	//! Configure pin as input
	void Input();

	/*! Check whether pin is configured as output
	*  \return true when pin is configured as output
	*/
	bool IsOutput();

	/*! Check whether pin is configured as input
	*  \return true when pin is configured as input
	*/
	bool IsInput();

	/*! Configure pin function
	*  \param function Function to be configured
	*/
	int SetFunction(const psff::GpioPinFunction function);

	/*! Set pin speed
	*  \param mask Pin mask of affected pins
	*  \param speed Pin speed to be set
	*/
	void SetSpeed(const psff::GpioPinSpeed speed);

	/*! Configure pin pull resistor
	*  \param pull Pull mode to be set
	*/
	void SetPullResistor(const psff::GpioPullResistor pull);

private:

    ::psff::GpioPortT<::psff::GpioPortDummy> m_port;

	void PrintState();

	bool m_isSet;

	std::string m_name;

	::psff::Logger m_logger;

};

#endif // _DUMMY_GPIO_PIN_H_