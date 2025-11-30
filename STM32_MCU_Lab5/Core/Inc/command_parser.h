/*
 * command_parser.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ASUS
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

/* Includes */
#include "main.h"
#include "software_timer.h"
#include "stdio.h"
#include "string.h"
#include "global.h"

/* Define */
enum CommandParserState {
	CMD_WAIT,
	CMD_GET
};

/* Variables */
extern uint8_t temp;

/* Functions */
void get_message(UART_HandleTypeDef *huart);
void FSM_Command_Parser(void);

#endif /* INC_COMMAND_PARSER_H_ */
