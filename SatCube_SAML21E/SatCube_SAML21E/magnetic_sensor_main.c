/*
 * magnetic_sensor.c
 *
 * Created: 22.02.2020 13:00:55
 *  Author: Blazik
 */ 
#include "driver_init.h"
#include "magnetic_sensor_main.h"

struct magnetic_sensor *MAGNETIC_lis2mld;

void magnetic_sensor_init() {
	i2c_m_sync_enable(&I2C_OUT);
	MAGNETIC_lis2mld = lis2mdl_construct(&MAGNETIC_lis2mld, &I2C_OUT);
}