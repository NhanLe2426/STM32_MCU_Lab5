/*
 * uart.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ASUS
 */

#ifndef INC_UART_H_
#define INC_UART_H_

/* Includes */
#include "main.h"
#include "software_timer.h"
#include "stdio.h"
#include "string.h"
#include "global.h"

/* Define */
enum UARTCommandState {
	INIT,
	WAITING,
	SENDING,
	WAIT_ACK
};

/* Variables */

/* Functions */
void FSM_UART_Communication(void);

#endif /* INC_UART_H_ */
