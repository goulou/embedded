#pragma once

#include <spi.hpp>

//TODO: must be placed in mapping file
#define DEFAULT_SPI_NUMBER							1

namespace arduino
{
	namespace spi
	{

	class ArduinoSPI
	{
	public:

		void begin();

		uint8_t transfer(uint8_t val);

	}; //class SPI

	typedef ArduinoSPI HardwareSPI;

	} //namespace spi

} //namespace arduino
