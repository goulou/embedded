#include <pinout.hpp>



namespace pinout
{


	unsigned int NumPin()
	{
		return PinDescription().size();
	}
	
	const std::vector<Pin_Description>& PinDescription()
	{
		static std::vector<Pin_Description> pin_desc = {
															{1,  0, USART, 2, Cts},			// PA0
															{1,  1, USART, 2, Rts},			// PA1
															{1,  2, USART, 2, Tx},			// PA2
															{1,  3, USART, 2, Rx}, 			// PA3
															{1,  4, USART, 2, Clk}, 		// PA4
															{1,  5, SPI, 1, Clk}, 			// PA5
															{1,  6, SPI, 1, Miso}, 			// PA6
															{1,  7, SPI, 1, Mosi}, 			// PA7
															{1,  8, USART, 1, Clk}, 		// PA8
															{1,  9, USART, 1, Tx}, 			// PA9
															{1, 10, USART, 1, Rx}, 			// PA10
															{1, 11, USART, 1, Cts}, 		// PA11
															{1, 12, USART, 1, Rts}, 		// PA12
														};	

		return pin_desc;

	}

}
