/**
  ******************************************************************************
  * @file    stm32f3xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#include "stm32f3xx_it.h"
#include "main.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */


/* External variables --------------------------------------------------------*//*
extern uint32_t timer;		*/
extern volatile uint32_t timer;
extern volatile uint32_t timer1;
extern volatile uint32_t timer2;
extern volatile uint32_t timer3;

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */ 
/******************************************************************************/

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles PVD interrupt through EXTI line16.
*/
void PVD_IRQHandler(void)
{
  /* USER CODE BEGIN PVD_IRQn 0 */

  /* USER CODE END PVD_IRQn 0 */
  HAL_PWR_PVD_IRQHandler();
  /* USER CODE BEGIN PVD_IRQn 1 */

  /* USER CODE END PVD_IRQn 1 */
}

/**
* @brief This function handles EXTI line0 interrupt.
*/
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
	//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);

  DWT->CYCCNT=0;
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)){
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,1);
			timer = (DWT->CYCCNT);  // increase the count as long as the echo signal remains high
	}
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
    /* USER CODE END EXTI0_IRQn 1 */
}

void EXTI1_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
	//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,1);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
  DWT->CYCCNT=0;
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)){
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,1);
			timer1 = (DWT->CYCCNT);  // increase the count as long as the echo signal remains high
			//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
	}
    /* USER CODE END EXTI0_IRQn 1 */
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,0);

}

void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
	//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,1);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  DWT->CYCCNT=0;
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_3)){
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,1);
			timer2 = (DWT->CYCCNT);  // increase the count as long as the echo signal remains high
			//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
	}
    /* USER CODE END EXTI0_IRQn 1 */
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,0);

}


void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
	//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,1);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  DWT->CYCCNT=0;
  /* USER CODE BEGIN EXTI0_IRQn 1 */
	while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)){
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,1);
			timer3 = (DWT->CYCCNT);  // increase the count as long as the echo signal remains high
			//HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,0);
	}
    /* USER CODE END EXTI0_IRQn 1 */
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,0);

}



/*
void EXTI15_10_IRQHandler(void)
{

}
*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
