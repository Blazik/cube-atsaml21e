#include <atmel_start.h>
#include "temperature_sensor_main.h"

const enum mcu_status {
	DEAD,
	RESET,
	SLEEP,
	SAT_READ,
	BLOCK_1_READ,
	BLOCK_2_READ,
	BLOCK_1_ERROR,
	BLOCK_2_ERROR,
};

int main(void)
{
	
	atmel_start_init();
	
 		gpio_set_pin_level(POWER_BLOCK_1, true);
 		gpio_set_pin_level(BLOCK_1_EN, true);
		 
 	temperature_sensors_init();
// 		
// 		
// 		gpio_set_pin_level(MCU_1_STATUS_1, true);
// 		gpio_set_pin_level(BLOCK_2_EN, true);

	while (1) {
		
	}
}
