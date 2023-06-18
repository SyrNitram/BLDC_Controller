/*
 * shell.h
 *
 *  Created on: 7 juin 2019
 *      Author: laurent
 */

#ifndef INC_LIB_SHELL_SHELL_H_
#define INC_LIB_SHELL_SHELL_H_

#include <stdint.h>

#define UART_DEVICE huart1

#define _SHELL_FUNC_LIST_MAX_SIZE 40

#define _ARGV_SIZE 20
#define _COMMAND_LINE_SIZE 42
#define _PRINT_BUFFER_SIZE 42

#define _ARROW_FIRST 0x1B
#define _ARROW_SECOND 0x5B
#define _ARROW_THIRD_UP 0x41
#define _ARROW_THIRD_DOWN 0x42
#define _ARROW_THIRD_RIGHT 0x43
#define _ARROW_THIRD_LEFT 0x44

struct hShellStruct;

typedef uint8_t (* ShellTransmitCb_t)(char * pData, uint16_t Size);
typedef int (* ShellFuncPtr_t)(struct hShellStruct * hShell, int argc, char ** argv);

/**
 * @brief Structure to connect a function pointer to a character and a description
 *
 * Contains 3 informations : a character, a function pointer and a description
 * It allows to find a function thanks to its registered character.
 */
typedef struct ShellFunc{
	char c;
	ShellFuncPtr_t func;
	char * description;
} ShellFunc_t;

typedef struct hShellStruct{
	uint16_t funcListSize;
	ShellFunc_t funcList[_SHELL_FUNC_LIST_MAX_SIZE];
	char cmdLineBuffer[_COMMAND_LINE_SIZE];
	char printBuffer[_PRINT_BUFFER_SIZE];
	ShellTransmitCb_t transmitCb;
	uint16_t cmdLinePosition;
	uint8_t arrowPending;
} hShell_t;

uint8_t ShellInit(hShell_t * hShell, ShellTransmitCb_t transmitCb);
uint8_t ShellAdd(hShell_t * hShell, char c, ShellFuncPtr_t pFunc, char * description);
uint8_t ShellProcess(hShell_t * hShell, char c);

#endif /* INC_LIB_SHELL_SHELL_H_ */
