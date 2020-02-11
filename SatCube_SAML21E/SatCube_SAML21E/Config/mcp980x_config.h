/*
 * mcp980x_config.h
 *
 * Created: 07.07.2018 9:00:07
 *  Author: David
 */ 


#ifndef MCP980X_CONFIG_H_
#define MCP980X_CONFIG_H_

/*
000 = 0x18
001 = 0x19
010 = 0x1A
011 = 0x1B
100 = 0x1C
*/

#ifndef CONF_MCP980X_SENSOR_ADDRES
#define CONF_MCP980X_SENSOR_ADDRES 0x18
#endif

/*
1 = +0.5°C         30 ms typical
2 = +0.25°C        65 ms typical
3 = +0.125°C       130 ms typical
4 = +0.0625°C      power-up default 250 ms typical
*/
#ifndef CONF_MCP980X_SENSOR_RESOLUTION
#define CONF_MCP980X_SENSOR_RESOLUTION 2
#endif
/*
0 = Continuous conversion (power-up default)
1 = Shutdown (Low-Power mode)
*/
#ifndef CONF_MCP980X_SENSOR_MODE
#define CONF_MCP980X_SENSOR_MODE 2
#endif
/*

*/
#ifndef CONF_MCP980X_SENSOR_ALERT_MODE
#define CONF_MCP980X_SENSOR_ALERT_MODE 2
#endif

#endif /* MCP980X_CONFIG_H_ */