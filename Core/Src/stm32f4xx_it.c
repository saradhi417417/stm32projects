/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

//void HardFault_Handler(void) __attribute__((naked));

/**
  * @brief This function handles Hard fault interrupt.
  */
void hard_fault_handler_c(uint32_t *fault_stack) {
    // Extract useful registers from stack
//    uint32_t r0  = fault_stack[0];
//    uint32_t r1  = fault_stack[1];
//    uint32_t r2  = fault_stack[2];
//    uint32_t r3  = fault_stack[3];
//    uint32_t r12 = fault_stack[4];
//    uint32_t lr  = fault_stack[5];
//    uint32_t pc  = fault_stack[6];  // Address of the instruction that caused the fault
//    uint32_t xpsr = fault_stack[7];
//    printf("Hard Fault Occurred!\n");
//       printf("R0  = 0x%08X\n", r0);
//       printf("R1  = 0x%08X\n", r1);
//       printf("R2  = 0x%08X\n", r2);
//       printf("R3  = 0x%08X\n", r3);
//       printf("R12 = 0x%08X\n", r12);
//       printf("LR  = 0x%08X\n", lr);
//       printf("PC  = 0x%08X\n", pc);   // This helps find the faulting instruction
//       printf("xPSR= 0x%08X\n", xpsr);
//
//       // Read CFSR for more details on the fault
//       uint32_t cfsr = SCB_CFSR;
//       printf("CFSR = 0x%08X\n", cfsr);
//
//       if (cfsr & 0x00000001) printf("MemManage Fault: Instruction access violation\n");
//       if (cfsr & 0x00000002) printf("MemManage Fault: Data access violation\n");
//       if (cfsr & 0x00000008) printf("MemManage Fault: Unstacking fault\n");
//       if (cfsr & 0x00000010) printf("MemManage Fault: Stacking fault\n");
//       if (cfsr & 0x00000080) printf("MemManage Fault: Fault occurred at address 0x%08X\n", SCB_MMAR);
//
//       if (cfsr & 0x00000100) printf("Bus Fault: Instruction bus error\n");
//       if (cfsr & 0x00000200) printf("Bus Fault: Precise data bus error at 0x%08X\n", SCB_BFAR);
//       if (cfsr & 0x00000400) printf("Bus Fault: Imprecise data bus error\n");
//       if (cfsr & 0x00000800) printf("Bus Fault: Unstacking fault\n");
//       if (cfsr & 0x00001000) printf("Bus Fault: Stacking fault\n");
//       if (cfsr & 0x00008000) printf("Bus Fault: Fault address is 0x%08X\n", SCB_BFAR);
//
//       if (cfsr & 0x00010000) printf("Usage Fault: Undefined instruction\n");
//       if (cfsr & 0x00020000) printf("Usage Fault: Invalid state\n");
//       if (cfsr & 0x00040000) printf("Usage Fault: Invalid PC load\n");
//       if (cfsr & 0x00080000) printf("Usage Fault: No coprocessor access\n");
//       if (cfsr & 0x01000000) printf("Usage Fault: Unaligned access\n");
//       if (cfsr & 0x02000000) printf("Usage Fault: Division by zero\n");
//
//       // Check HardFault Status Register
//       if (SCB_HFSR & (1 << 1)) printf("HardFault: Vector table read fault\n");
//       if (SCB_HFSR & (1 << 30)) printf("HardFault: Forced Hard Fault (see CFSR for details)\n");

       // Stop execution to debug
       while (1);
}

void HardFault_Handler(void)
{



	//void HardFault_Handler(void) {
	    __asm volatile (
	        "TST lr, #4 \n"             // Check EXC_RETURN bit 2 (Thread or Handler mode)
	        "ITE EQ \n"
	        "MRSEQ r0, MSP \n"          // Read MSP (Main Stack Pointer)
	        "MRSNE r0, PSP \n"          // Read PSP (Process Stack Pointer)
	        "B hard_fault_handler_c \n" // Branch to C handler
	    );
	//}

  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
//  while (1)
//  {
//    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
//    /* USER CODE END W1_HardFault_IRQn 0 */
//  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}


void UsageFault_Handler_c(uint32_t *fault_stack) {
    // Extract useful registers from stack
    uint32_t r0  = fault_stack[0];
    uint32_t r1  = fault_stack[1];
    uint32_t r2  = fault_stack[2];
    uint32_t r3  = fault_stack[3];
    uint32_t r12 = fault_stack[4];
    uint32_t lr  = fault_stack[5];
    uint32_t pc  = fault_stack[6];  // Address of the instruction that caused the fault
    uint32_t xpsr = fault_stack[7];
//    printf("Hard Fault Occurred!\n");
//       printf("R0  = 0x%08X\n", r0);
//       printf("R1  = 0x%08X\n", r1);
//       printf("R2  = 0x%08X\n", r2);
//       printf("R3  = 0x%08X\n", r3);
//       printf("R12 = 0x%08X\n", r12);
//       printf("LR  = 0x%08X\n", lr);
//       printf("PC  = 0x%08X\n", pc);   // This helps find the faulting instruction
//       printf("xPSR= 0x%08X\n", xpsr);
//
//       // Read CFSR for more details on the fault
//       uint32_t cfsr = SCB_CFSR;
//       printf("CFSR = 0x%08X\n", cfsr);
//
//       if (cfsr & 0x00000001) printf("MemManage Fault: Instruction access violation\n");
//       if (cfsr & 0x00000002) printf("MemManage Fault: Data access violation\n");
//       if (cfsr & 0x00000008) printf("MemManage Fault: Unstacking fault\n");
//       if (cfsr & 0x00000010) printf("MemManage Fault: Stacking fault\n");
//       if (cfsr & 0x00000080) printf("MemManage Fault: Fault occurred at address 0x%08X\n", SCB_MMAR);
//
//       if (cfsr & 0x00000100) printf("Bus Fault: Instruction bus error\n");
//       if (cfsr & 0x00000200) printf("Bus Fault: Precise data bus error at 0x%08X\n", SCB_BFAR);
//       if (cfsr & 0x00000400) printf("Bus Fault: Imprecise data bus error\n");
//       if (cfsr & 0x00000800) printf("Bus Fault: Unstacking fault\n");
//       if (cfsr & 0x00001000) printf("Bus Fault: Stacking fault\n");
//       if (cfsr & 0x00008000) printf("Bus Fault: Fault address is 0x%08X\n", SCB_BFAR);
//
//       if (cfsr & 0x00010000) printf("Usage Fault: Undefined instruction\n");
//       if (cfsr & 0x00020000) printf("Usage Fault: Invalid state\n");
//       if (cfsr & 0x00040000) printf("Usage Fault: Invalid PC load\n");
//       if (cfsr & 0x00080000) printf("Usage Fault: No coprocessor access\n");
//       if (cfsr & 0x01000000) printf("Usage Fault: Unaligned access\n");
//       if (cfsr & 0x02000000) printf("Usage Fault: Division by zero\n");
//
//       // Check HardFault Status Register
//       if (SCB_HFSR & (1 << 1)) printf("HardFault: Vector table read fault\n");
//       if (SCB_HFSR & (1 << 30)) printf("HardFault: Forced Hard Fault (see CFSR for details)\n");

       // Stop execution to debug
       while (1);
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{


	//void HardFault_Handler(void) {
	    __asm volatile (
	        "TST lr, #4 \n"             // Check EXC_RETURN bit 2 (Thread or Handler mode)
	        "ITE EQ \n"
	        "MRSEQ r0, MSP \n"          // Read MSP (Main Stack Pointer)
	        "MRSNE r0, PSP \n"          // Read PSP (Process Stack Pointer)
	        "B UsageFault_Handler_c \n" // Branch to C handler
	    );
	//}


  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

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
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
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
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
