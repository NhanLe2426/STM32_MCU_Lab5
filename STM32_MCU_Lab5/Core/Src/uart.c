/*
 * uart.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ASUS
 */

/* Includes */
#include "uart.h"

/* Variables */
enum UARTCommandState UART_status = INIT;
uint32_t ADC_val = 0;
uint8_t str[10];

/* Functions */
void FSM_UART_Communication(void) {
	switch (UART_status) {
	case INIT:
		UART_status = WAITING;

		break;

	case WAITING:
		if (command_flag == 1 && command_data == RST) {
			ADC_val = HAL_ADC_GetValue(&hadc1);
			sprintf((char *)str, "!ADC=%ld#\r\n", ADC_val);

			command_flag = 0;
			UART_status = SENDING;
		}
		break;

	case SENDING:
		HAL_UART_Transmit(&huart2, str, sizeof(str), HAL_MAX_DELAY);

		setTimer(0, 3000);
		UART_status = WAIT_ACK;
		break;

	case WAIT_ACK:
		if (command_flag == 1 && command_data == OK) {
			command_flag = 0;
			UART_status = WAITING;
		}
		if (isTimerExpired(0) == 1) {
			UART_status = SENDING;		// Re-send
		}
		break;

	default:
		break;
	}
}
