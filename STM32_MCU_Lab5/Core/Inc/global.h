/*
 * global.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/* Includes */
#include "main.h"
#include "software_timer.h"

/* Define */

enum CommandType {
	NONE,
	RST,
	OK
};

#define MAX_BUFFER_SIZE	30

/* Variables */
// extern enum UARTCommandState UART_status;
// extern enum CommandParserState CMD_status;
extern enum CommandType command_data;
extern uint8_t command_flag;

#endif /* INC_GLOBAL_H_ */
