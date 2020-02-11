/*
 * magnetic_sensor.h
 *
 * Created: 11.02.2020 16:31:41
 *  Author: Blazik
 */ 


#ifndef MAGNETIC_SENSOR_H_
#define MAGNETIC_SENSOR_H_

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif
	
struct magnetic_sensor_settings 
{
	struct lis2mdl_settings *lis2mdl; 
};


/** FORWARD declaration of magnetic sensor structure. */
struct magnetic_sensor;

/**
 * \brief Interface of abstract magnetic sensor
 */
struct magnetic_sensor_interface {
	float    (*read)(const struct magnetic_sensor *const me);
	int16_t (*setup)(const struct magnetic_sensor *const me, struct magnetic_sensor_settings *mag_set);
};

/**
 * \brief Abstract magnetic sensor definition
 */
struct magnetic_sensor {
	/** The pointer to interface used to communicate with magnetic sensor */
	void *io;
	
	/** The interface of abstract temperature sensor */
	const struct magnetic_sensor_interface *interface;
};

struct magnetic_sensor *magnetic_sensor_construct(
	struct magnetic_sensor *const me, 
	void *const io,
	const struct magnetic_sensor_interface *const interface
);

/**
 * \brief Read from the given sensor
 */
float magnetic_sensor_read(const struct magnetic_sensor *const me);

/*
 * \brief Setup magnetic sensor by setup struct 
 *
 * \param[in] me The pointer to magnetic sensor to setup
 * \param[in] temp_set The pointer to set up struct
 */
int16_t magnetic_sensor_setup(const struct magnetic_sensor *const me, struct magnetic_sensor_settings *mag_set);

#ifdef __cplusplus
}
#endif

#endif /* MAGNETIC_SENSOR_H_ */