#include <arduino_gpio.hpp>
#include <hal/gpio.hpp>
#include <gpio.hpp>

//TODO: must be placed in mapping file
#define DEFAULT_GPIO_PORT							GPIOA


namespace arduino
{
	namespace gpio
	{
		void pinMode(int pin, int Pin_Mode)
		{
			switch (Pin_Mode)
			{
			case OUTPUT:
				::gpio::configure_gpio_pin(DEFAULT_GPIO_PORT, pin);
				break;
			default:
				//unsupported
				break;
			}

		}

		void digitalWrite(int pin, int Pin_State)
		{
			switch (Pin_State)
			{
			case HIGH:
				::gpio::set_pin(DEFAULT_GPIO_PORT, pin);
				break;
			case LOW:
				::gpio::reset_pin(DEFAULT_GPIO_PORT, pin);
				break;
			}
		}

	}
}
