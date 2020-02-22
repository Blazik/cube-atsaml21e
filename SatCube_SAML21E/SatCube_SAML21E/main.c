#include <atmel_start.h>
#include <lis2mdl_registers.h>
#include "temperature_sensor_main.h"
#include "magnetic_sensor_main.h"

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

// i2c_m_sync_enable(&I2C_OUT);
// i2c_m_sync_set_slaveaddr(&I2C_OUT, 0x1e, I2C_M_SEVEN);

	magnetic_sensor_init();
	  
	  magnetic_sensor_read_temperature(&MAGNETIC_lis2mld);

	while (1) {
		
	}
}
