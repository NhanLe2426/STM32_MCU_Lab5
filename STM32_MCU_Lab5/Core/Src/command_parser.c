/*
 * command_parser.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ASUS
 */

/* Includes */
#include "command_parser.h"

/* Variables */
enum CommandParserState CMD_status = CMD_WAIT;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t temp = 0;
uint8_t index_buffer = 0;

/* Functions */

/**
 * @brief	Put this function in HAL_UART_RxCpltCallback() in main.c
 * @param
 * @retval	None
 */
void get_message(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {
		buffer[index_buffer++] = temp;
		if (index_buffer == MAX_BUFFER_SIZE) index_buffer = 0;
		buffer_flag = 1;

		HAL_UART_Transmit(&huart2, &temp, 1, HAL_MAX_DELAY);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

/**
 * @brief	FSM for Command Parser
 * @param	None
 * @retval	None
 */
void FSM_Command_Parser(void) {
	switch (CMD_status) {
	case CMD_WAIT:
		// Change state to CMD_GET
		if (temp == '!') {
			index_buffer = 0;
			CMD_status = CMD_GET;
		}
		break;

	case CMD_GET:
		// Change state to CMD_WAIT
		if (temp == '#') {
			if ((buffer[0] == 'R') && (buffer[1] == 'S') && (buffer[2] == 'T') && (buffer[3] == '#')) {
				command_data = RST;
				command_flag = 1;
			}
			if ((buffer[0] == 'O') && (buffer[1] == 'K') && (buffer[2] == '#')) {
				command_data = OK;
				command_flag = 1;
			}
			CMD_status = CMD_WAIT;
		}
		break;

	default:
		break;
	}
}
