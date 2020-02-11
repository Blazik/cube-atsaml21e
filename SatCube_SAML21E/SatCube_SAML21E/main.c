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
	
	temperature_sensors_init();

	while (1) {
		
	}
}
