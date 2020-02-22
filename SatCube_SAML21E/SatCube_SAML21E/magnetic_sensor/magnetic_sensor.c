/*
 * magnetic_sensor.c
 *
 * Created: 11.02.2020 16:31:29
 *  Author: Blazik
 */ 

#include <magnetic_sensor.h>

/**
 * \brief Construct abstract magnetic sensor
 */
struct magnetic_sensor *magnetic_sensor_construct(
	struct magnetic_sensor *const me, 
	void *const io,
	const struct magnetic_sensor_interface *const interface
)
{
	me->io        = io;
	me->interface = interface;

	return me;
}

/**
 * \brief Read from the given sensor
 */
float magnetic_sensor_read_temperature(const struct magnetic_sensor *const me)
{
	return me->interface->read_temp(me);
}

/*
 * \brief Setup magnetic sensor by setup struct 
 *
 * \param[in] me The pointer to magnetic sensor to setup
 * \param[in] temp_set The pointer to set up struct
 */
int16_t magnetic_sensor_setup(const struct magnetic_sensor *const me, struct magnetic_sensor_settings *mag_set)
{
	return me->interface->setup(me, mag_set); 
}