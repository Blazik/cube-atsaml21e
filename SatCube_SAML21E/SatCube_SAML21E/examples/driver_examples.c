/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using CALENDAR_0.
 */
static struct calendar_alarm alarm;

static void alarm_cb(struct calendar_descriptor *const descr)
{
	/* alarm expired */
}

void CALENDAR_0_example(void)
{
	struct calendar_date date;
	struct calendar_time time;

	calendar_enable(&CALENDAR_0);

	date.year  = 2000;
	date.month = 12;
	date.day   = 31;

	time.hour = 12;
	time.min  = 59;
	time.sec  = 59;

	calendar_set_date(&CALENDAR_0, &date);
	calendar_set_time(&CALENDAR_0, &time);

	alarm.cal_alarm.datetime.time.sec = 4;
	alarm.cal_alarm.option            = CALENDAR_ALARM_MATCH_SEC;
	alarm.cal_alarm.mode              = REPEAT;

	calendar_set_alarm(&CALENDAR_0, &alarm, alarm_cb);
}

/**
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_0[12] = "Hello World!";

static void tx_cb_USART_0(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_0_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_0, USART_ASYNC_TXC_CB, tx_cb_USART_0);
	/*usart_async_register_callback(&USART_0, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_0, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_0, &io);
	usart_async_enable(&USART_0);

	io_write(io, example_USART_0, 12);
}

static struct io_descriptor *io;

static void I2C_IN_rx_complete(const struct i2c_s_async_descriptor *const descr)
{
	uint8_t c;

	io_read(io, &c, 1);
}

void I2C_IN_example(void)
{
	i2c_s_async_get_io_descriptor(&I2C_IN, &io);
	i2c_s_async_register_callback(&I2C_IN, I2C_S_RX_COMPLETE, I2C_IN_rx_complete);
	i2c_s_async_enable(&I2C_IN);
}

static uint8_t I2C_OUT_example_str[12] = "Hello World!";

void I2C_OUT_tx_complete(struct i2c_m_async_desc *const i2c)
{
}

void I2C_OUT_example(void)
{
	struct io_descriptor *I2C_OUT_io;

	i2c_m_async_get_io_descriptor(&I2C_OUT, &I2C_OUT_io);
	i2c_m_async_enable(&I2C_OUT);
	i2c_m_async_register_callback(&I2C_OUT, I2C_M_ASYNC_TX_COMPLETE, (FUNC_PTR)I2C_OUT_tx_complete);
	i2c_m_async_set_slaveaddr(&I2C_OUT, 0x12, I2C_M_SEVEN);

	io_write(I2C_OUT_io, I2C_OUT_example_str, 12);
}

void delay_example(void)
{
	delay_ms(5000);
}

static struct timer_task TIMER_0_task1, TIMER_0_task2;

/**
 * Example of using TIMER_0.
 */
static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
}

static void TIMER_0_task2_cb(const struct timer_task *const timer_task)
{
}

void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 100;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	TIMER_0_task2.interval = 200;
	TIMER_0_task2.cb       = TIMER_0_task2_cb;
	TIMER_0_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_add_task(&TIMER_0, &TIMER_0_task2);
	timer_start(&TIMER_0);
}

/**
 * Example of using WDT_0.
 */
void WDT_0_example(void)
{
	uint32_t clk_rate;
	uint16_t timeout_period;

	clk_rate       = 1000;
	timeout_period = 4096;
	wdt_set_timeout_period(&WDT_0, clk_rate, timeout_period);
	wdt_enable(&WDT_0);
}
