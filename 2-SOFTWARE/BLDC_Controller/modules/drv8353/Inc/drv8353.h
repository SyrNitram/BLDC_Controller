/*
 * drv8353.h
 *
 *  Created on: 19 août 2022
 *      Author: martin
 */

#ifndef DRV8353_INC_DRV8353_H_
#define DRV8353_INC_DRV8353_H_

#include <stdbool.h>
#include <main.h>

typedef enum {
	DRV_MODE_SLEEP = 0	,
	DRV_MODE_STOP 		,
	DRV_MODE_ALIGN		,
	DRV_MODE_BRAKE		,
	DRV_MODE_OPERATING
}DRV8353_MODE_t;

void
DRV_SetPWM (int32_t dc);

HAL_StatusTypeDef
DRV_SetMode(DRV8353_MODE_t mode);

void
DRV_UpdateHalls();

void
DRV_FaultResolution();

#endif /* DRV8353_INC_DRV8353_H_ */
