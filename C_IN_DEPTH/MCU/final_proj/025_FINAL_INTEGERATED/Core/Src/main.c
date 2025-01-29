
#include "main.h"





ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi2;
ThermoCouple sensor_th1;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C2_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI2_Init(void);
void InitThermocouple1(void);

MCP4725 myMCP4725;




int main(void)
{


	volatile uint32_t value;
	//char mytext[] = "hello oled";
	//char retval;


  HAL_Init();


  /* Configure the system clock */
  SystemClock_Config();



  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_I2C2_Init();
  MX_I2C1_Init();
  MX_SPI2_Init();

  InitThermocouple1();
  HAL_ADC_Start (&hadc1);



  printf("hello world\n");

  ssd1306_Init();                                           // OLED_INIT

  // Second, initilaize the MCP4725 object:
  myMCP4725 = MCP4725_init(&hi2c2, MCP4725A0_ADDR_A01, 5.0);




  ////////////////////////////// initialisations end

  printf("hello world\n");


  	////////////////////////////////////////////////////////////////
  	//
  	//  SPI2  THERMO COUPLE
  	//
  	///////////////////////////////////////////////////////////////


    float Th1_temp =0;
    int intpart, fracpart;
    //char txt1[11];
    char txt1[12];


  	// Check the connection:
  	if(MCP4725_isConnected(&myMCP4725)){

  		// Print that the DAC is coonected
  		printf("dac is connected -- \n");

  	}
  	else{

  		// Print that the DAC is NOT coonected
  		printf("not connected\n");

  	}

  	HAL_Delay(5000);
  	printf("delay 5sec after dac is connected \n");




  while (1)
  {
	  //////////////////////////////////////////////////////////////
	  //
	  //        SPI THERMOCOUPLE SENSOR
	  //
	  ////////////////////////////////////////////////////////////////

	 		  ReadThermoCouple(&sensor_th1);
	 	 	  if (sensor_th1.connected){
	 	 		  Th1_temp = sensor_th1.Thx_celcius;
	 	 		  intpart = (int)Th1_temp;
	 	 		  fracpart = (int)((Th1_temp - intpart) * 100);
	 	 		  snprintf(txt1, 11, "%3d.%02d", intpart, fracpart);
	 	 		  txt1[11]='\0';
	 	 		  printf("%s\n",txt1);


	 	 		  // PRINT TO OLED Display
	 	 		  // SSD1306_GotoXY (1, 1);
	 	 		  // SSD1306_Puts (txt1, &Font_16x26, 1);
	 	 		  // SSD1306_UpdateScreen(); // update screen*/
	 	 	  }
	 	 	  // else {
	 	 	  // 	 SSD1306_GotoXY (1, 1);
	 	 	  // 	 SSD1306_Puts ("disconnected", &Font_7x10, 1);
	 	 	  // 	 SSD1306_UpdateScreen(); // update screen
	 	 	  // }
	 		  HAL_Delay(300);





           ///////////////////////////////////////////////////////////////
	 	   //
	 	   //     OLED
	 	   //
	 	   //////////////////////////////////////////////////////////////////
	 		 /*
	 		    // ssd1306_Fill(White);
	 		   //printf("ssd1306 fill white \n");

	 		   //ssd1306_UpdateScreen();

	 		   ssd1306_SetCursor(5,5);
	 		   retval = ssd1306_WriteString(mytext,Font_7x10,White);
	 		   ssd1306_UpdateScreen();

	 		  */
	 		  ////////////////////////////////////////////OLED




              ////////////////////////////////////////////////////////////////////////////////
	 		  //
	 		  //
	 		  //
	 		  //     ADC + VALVE + GPIO RELAY	 		  //
	 		  //
	 		  //
	 		  //
	 		  ///////////////////////////////////////////////////////////////////////////


	 	   	  HAL_ADC_PollForConversion (&hadc1, 100);
	 	    	  value = HAL_ADC_GetValue (&hadc1);
	 	    	  // printf("value = %ld\n",value);
	 	    	  float voltage = (value * 5.0f) / 4096.0f;

	 	    	  // Print voltage
	 	    		         // printf("ADC Value: %lu, Voltage: %.2f V\n", value, voltage);
	 	    	  //printf(" adc value == %ld  ---  Voltage: %.2f V\n",value, voltage);
	 	    	  printf(" %ld     %.2f V\n",value, voltage);
	 	    	  //MCP4725_setVoltage(&myMCP4725,voltage, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	    	  HAL_Delay(4000);
	 	    	  ////////////////////////////////////



	 	      	  if(voltage <= 1.0){

	 	      		  	  MCP4725_setVoltage(&myMCP4725,1.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	      		  	  printf("if voltage <=1 --> mcp_setvoltgae(1)\n");

	 	      	  }else if(voltage >1.0 && voltage <=2.0){

	 	      		  	  MCP4725_setVoltage(&myMCP4725,2.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	      		  	  printf("if voltage <=2 --> mcp_setvoltgae(2)\n");

	 	      	  }else if(voltage >2.0 && voltage <=3.0){

	 	      		  	  MCP4725_setVoltage(&myMCP4725,3.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	      		  	  printf("if voltage <=3 --> mcp_setvoltgae(3)\n");

	 	      	  }else if(voltage >3.0 && voltage <=4.0){

	 	      		  	  MCP4725_setVoltage(&myMCP4725,4.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	      		  	  printf("if voltage <=4 --> mcp_setvoltgae(4)\n");

	 	      	  }else if(voltage >4.0 && voltage <=5.0){

	 	      		  	  MCP4725_setVoltage(&myMCP4725,5.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	      		  	  printf("if voltage <=5 --> mcp_setvoltgae(5)\n");

	 	      	  }// VALVE CONTROL


	 	      	  ///////////////////////////////////////////////////////////////////////////////
	 	      	  //
	 	      	  //               GPIO RELAY CONTROL
	 	      	  //                -----------------
	 	      	  //      OUTPUT MODE -- LOW
	 	      	  //               OPEN DRAIN EXTERNAL PULL UP CONFIG  (NO PUSH PULL FROM INSIDE OPEN DRAIN)
	 	      	  //       PC10


	 	      	   /*
	 	      	     if(temperature > 60 && temperature<90){

	 	    	        	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET );
	 	    	        	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
	 	    	        }
	 	    	        else{
	 	    	         	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET );
	 	    	        }

	 	      	    */
	 	       	 ///////////////////////////////////////////////////////////////////////////////


	 	       	  ///////////////////////////////////
	 	       	  /*
	 	       	  //MCP4725_setVoltage(&myMCP4725,5.0f, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	       	  MCP4725_setValue(&myMCP4725, 500, MCP4725_FAST_MODE, MCP4725_POWER_DOWN_OFF);
	 	       	  printf("dac_value= 500\n");
	 	       	  HAL_Delay(10000);
	 	       	  */


                  //////////////////////////////////////////////////////////////////////////////////
	 	      	  //
	 	      	  //
	 	      	  //
	 	      	  //   ADC + VALVE + GPIO    ENDS HERE
	 	      	  //
	 	      	  //
	 	      	  /////////////////////////////////////////////////////////////////



  } // WHILE ENDS HERE



}// MAIN ENDS HERE




///////////////////////////////////////////////////////////////////////////////////////////
//
// ---------------------------------------------------------------------------------------
//		MAIN ENDS HERE
// ---------------------------------------------------------------------------------------
//
///////////////////////////////////////////////////////////////////////////////////////////

















void InitThermocouple1(void)
{
	  sensor_th1.Thx_CS_Pin = GPIO_PIN_6;				// CS Pin
	  sensor_th1.Thx_CS_Port = GPIOC;					// CS GPIO PORT
	  sensor_th1.hspi = &hspi2;							// SPI1
}








///////////////////////////////////////////////////////////////////////////
//
//  	 SYSTEM CLOCK CONFIG
// 		 ADC1_INIT
//		 I2C1_INIT
//		 I2C2_INIT
//		 SPI2_INIT
//		 GPIO_INIT
//
/////////////////////////////////////////////////////////////////////////////





void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES_RXONLY;
  hspi2.Init.DataSize = SPI_DATASIZE_16BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|RELAY_BUTTON_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : RELAY_BUTTON_Pin */
  GPIO_InitStruct.Pin = RELAY_BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RELAY_BUTTON_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
