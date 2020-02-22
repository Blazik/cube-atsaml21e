/*
 * lis2mdl.h
 *
 * Created: 11.02.2020 16:32:21
 *  Author: Blazik
 */ 


#ifndef LIS2MDL_H_
#define LIS2MDL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <magnetic_sensor.h>
#include <lis2mdl_registers.h>

const struct lis2mdl_settings {
	// todo
};

struct lis2mdl {
	/** The parent abstract temperature sensor */
	struct magnetic_sensor parent;
};

struct magnetic_sensor *lis2mdl_construct(struct magnetic_sensor *const me, void *const io);

float lis2mdl_read_temperature(const struct magnetic_sensor *const me);

int16_t lis2mdl_config(const struct magnetic_sensor *const me, struct magnetic_sensor_settings *mag_set);

#ifdef __cplusplus
}
#endif

#endif /* LIS2MDL_H_ */