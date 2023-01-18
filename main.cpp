#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

//Var14
//Output B13
//t = 5
//T=10

void delay(int millis) {
	for(int i=0;i< millis*0x010000;i++);
}

int main(void)
{  
  GPIO_InitTypeDef  GPIO_InitStructure;

  // Enable PORTB Clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	
	GPIO_SetBits(GPIOB, GPIO_Pin_13);
	
	// use driver functions 
	
  while (1) {
		
		  //Turn on pin
		  GPIO_SetBits(GPIOB, GPIO_Pin_13);  		  
		  //wait 5 carrots
		  delay(5);
		  //Turn off pin
		  GPIO_ResetBits(GPIOB, GPIO_Pin_13);     
		  //wait 10-5 carrots
		  delay(5);
  }
		
}