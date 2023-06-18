/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "fdcan.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "drv8353.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define BUFF_MAX 10
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t RX_char = 0;

hShell_t hShell;


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* Private user code ---------------------------------------------------------*/
int __io_putchar(int ch){
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 500 );
	return ch;
}

uint8_t SerialTransmit(char * pData, uint16_t Size){
	HAL_UART_Transmit(&huart1, (uint8_t *)pData, Size, 500 );
	return 0;
}

void parseBuffer(char * buffer, int N){

	char cmd = 0, c = 0;
	int value = 0;
	if (sscanf(&buffer[0], "%c %d%c", &cmd, &value, &c) != 2){
		printf("Erreur: mauvais nombre d'arguments \r\n");
		printf("cmd : %c   value : %d   c: %c\r\n", cmd, value, c);
		return;
	}

	if( cmd != 'H' || cmd != 'S') {
		printf("Erreur: fonctions possibles : H,  S \r\n");
		return;
	}

	if( value <-100 || value > 100) {
		printf("Erreur: le rapport cyclique doit etre entre -100 et 100 \r\n");
		return;
	}

	if(cmd == 'S'){
		//DRV_SetPWM(i);
		printf("PWM : %d", value);
	}

	else if(cmd == 'H'){
		printf("H\t\t help\r\nS [-100 : 100]\t set DC\r\n");
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	ShellProcess(&hShell, RX_char);
	HAL_UART_Receive_IT(&huart1, &RX_char, 1);
}

int Set_SetPoint(struct hShellStruct * hShell, int argc, char ** argv){
	if(hShell == NULL || argc != 2)return 1;
	char str[50] = {0};
	sprintf( str, "DRV PWM set at %d\r\n", atoi(argv[1]));
	SerialTransmit(str, sizeof(str));
	DRV_SetPWM(atoi(argv[1]));
	return 0;
}

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

	/* MCU Configuration--------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();
	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_ADC1_Init();
	MX_FDCAN1_Init();
	MX_SPI1_Init();
	MX_TIM1_Init();
	MX_TIM3_Init();
	MX_USART1_UART_Init();
	MX_TIM7_Init();
	MX_TIM6_Init();

	if (HAL_TIM_Base_Start(&htim1) != HAL_OK)
		Error_Handler();

	if( HAL_TIM_PWM_Start(&htim1, 0) != HAL_OK)
		Error_Handler();

	if(DRV_SetMode(DRV_MODE_SLEEP) != HAL_OK)
		Error_Handler();

	HAL_Delay(1000);

	if(DRV_SetMode(DRV_MODE_OPERATING) != HAL_OK)
		Error_Handler();

	HAL_Delay(3000);
	printf("driver started\r\n");

	ShellInit(&hShell, &SerialTransmit);
	ShellAdd(&hShell, 'S', Set_SetPoint, "Set pwm duty cycle [-100 : 100]");

	HAL_UART_Receive_IT(&huart1, &RX_char, 1);
	printf("console started\r\n");

/*	int i = 0;
	int state = 0;
*/

	while (1){

/*
		switch(state){
		case 0:
			i++;
			if(i>90) state = 1;
			break;
		case 1 :
			i--;
			if(i<-90) state = 0;
			break;
		}
		DRV_SetPWM(i);
		printf("PWM : %d", i);
		HAL_Delay(100);
*/

	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	DRV_UpdateHalls();
}


/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	 */
	HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
	RCC_OscInitStruct.PLL.PLLN = 85;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	DRV_SetPWM(0);
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
