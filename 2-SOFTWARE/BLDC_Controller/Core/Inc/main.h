/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SA_Pin 				GPIO_PIN_0
#define SA_GPIO_Port 		GPIOA
#define SB_Pin 				GPIO_PIN_1
#define SB_GPIO_Port 		GPIOA
#define SC_Pin 				GPIO_PIN_2
#define SC_GPIO_Port 		GPIOA
#define VBAT_Pin 			GPIO_PIN_3
#define VBAT_GPIO_Port 		GPIOA
#define SPI_SCK_Pin 		GPIO_PIN_5
#define SPI_SCK_GPIO_Port 	GPIOA
#define SPI_MISO_Pin 		GPIO_PIN_6
#define SPI_MISO_GPIO_Port 	GPIOA
#define SPI_MOSI_Pin 		GPIO_PIN_7
#define SPI_MOSI_GPIO_Port GPIOA
#define SPI_NSS_Pin GPIO_PIN_0
#define SPI_NSS_GPIO_Port GPIOB
#define nFAULT_Pin GPIO_PIN_10
#define nFAULT_GPIO_Port GPIOB
#define CAL_Pin GPIO_PIN_11
#define CAL_GPIO_Port GPIOB
#define ENABLE_Pin GPIO_PIN_12
#define ENABLE_GPIO_Port GPIOB
#define LA_Pin GPIO_PIN_13
#define LA_GPIO_Port GPIOB
#define LB_Pin GPIO_PIN_14
#define LB_GPIO_Port GPIOB
#define LC_Pin GPIO_PIN_15
#define LC_GPIO_Port GPIOB
#define HA_Pin GPIO_PIN_8
#define HA_GPIO_Port GPIOA
#define HB_Pin GPIO_PIN_9
#define HB_GPIO_Port GPIOA
#define HC_Pin GPIO_PIN_10
#define HC_GPIO_Port GPIOA
#define CAN_RX_Pin GPIO_PIN_11
#define CAN_RX_GPIO_Port GPIOA
#define CAN_TX_Pin GPIO_PIN_12
#define CAN_TX_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define HALL_A_Pin GPIO_PIN_15
#define HALL_A_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define ENC_A_Pin GPIO_PIN_4
#define ENC_A_GPIO_Port GPIOB
#define ENC_B_Pin GPIO_PIN_5
#define ENC_B_GPIO_Port GPIOB
#define USART_TX_Pin GPIO_PIN_6
#define USART_TX_GPIO_Port GPIOB
#define USART_RX_Pin GPIO_PIN_7
#define USART_RX_GPIO_Port GPIOB
#define HALL_B_Pin GPIO_PIN_8
#define HALL_B_GPIO_Port GPIOB
#define HALL_C_Pin GPIO_PIN_9
#define HALL_C_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
