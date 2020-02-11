/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file or main.c
 * to avoid loosing it when reconfiguring.
 */
#include "driver_init.h"
#include "temperature_sensor_main.h"

static struct mcp980x    TEMPERATURE_SENSOR_descr_mcp; 

struct temperature_sensor *TEMPERATURE_SENSOR;
struct temperature_sensor *TEMPERATURE_mcp980x;

int8_t i2c_m_scan(struct i2c_m_sync_desc *const i2c, uint8_t *buffer){
	
	int32_t ret;
	uint8_t address_counter = 0;
	uint8_t address = 0;
	uint8_t data_buf [2] = {0x00, 0x00};
	
	struct i2c_m_sync_desc *descr = i2c;

	struct _i2c_m_msg msg;
	msg.len    = 1;
	msg.flags  = 0;
	msg.buffer = &data_buf;
	
	memset(buffer, 250, sizeof(buffer));
	
	while (address < 125)
	{
		address++;
		msg.addr = address;
		ret = i2c_m_sync_transfer(descr, &msg);
		if (!ret)
		{
			if (address_counter > sizeof(buffer))
			{
				return -1;
			}
			
			buffer[address_counter] = address;
			address_counter++;
		}
	}
	
	
	return address_counter;
}

void read() {
	gpio_set_pin_level(POWER_BLOCK_1, true);
	gpio_set_pin_level(BLOCK_1_EN, true);
	
	
	gpio_set_pin_level(POWER_BLOCK_2, true);
	gpio_set_pin_level(BLOCK_2_EN, true);
	
	int buf[128];
	i2c_m_scan(&I2C_OUT, &buf);

	float x = temperature_sensor_read(TEMPERATURE_mcp980x);
	delay_ms(1000);
}

/**
 * \brief Initialize Temperature Sensors
 */
void temperature_sensors_init(void)
{
	i2c_m_sync_enable(&I2C_OUT);
	TEMPERATURE_mcp980x = mcp980X_construct(&TEMPERATURE_SENSOR_descr_mcp.parent, &I2C_OUT, CONF_MCP980X_SENSOR_RESOLUTION);
	//read();
}