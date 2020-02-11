/*
 * lis2mdl.c
 *
 * Created: 11.02.2020 16:32:11
 *  Author: Blazik
 */ 

#include <lis2mdl.h>
#include <hal_i2c_m_sync.h>
#include <magnetic_sensor.h>
#include <lis2mdl_registers.h>
#include <lis2mdl_config.h>


#define SENSOR_IDENTITY 0x40

static const struct magnetic_sensor_interface lis2mdl_interface = {lis2mdl_read, lis2mdl_config};

struct magnetic_sensor *lis2mdl_construct(struct magnetic_sensor *const me, void *const io)
{
	magnetic_sensor_construct(me, io, &lis2mdl_interface);
	
	struct i2c_m_sync_desc *descr = (struct i2c_m_sync_desc *)(me->io);
	
	i2c_m_sync_set_slaveaddr(descr, CONF_LIS2MDL_SENSOR_ADDRES, I2C_M_SEVEN);
	
	return me;
}

float lis2mdl_read(const struct magnetic_sensor *const me)
{
	
}

int16_t lis2mdl_config(const struct magnetic_sensor *const me, struct magnetic_sensor_settings *mag_set)
{ 

}