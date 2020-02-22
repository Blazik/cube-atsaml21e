/*
 * magnetic_sensor.h
 *
 * Created: 22.02.2020 13:01:10
 *  Author: Blazik
 */ 


#ifndef MAGNETIC_SENSOR_H_
#define MAGNETIC_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <magnetic_sensor.h>

extern struct magnetic_sensor *MAGNETIC_lis2mld;

void magnetic_sensor_init();

#ifdef __cplusplus
}
#endif

#endif /* MAGNETIC_SENSOR_H_ */