#include "stm32l475xx.h"
#include "system_stm32l4xx.h"
#include <time.h>

#define STK_CTRL (*((unsigned int*)0xE000E010))
#define STK_LOAD (*((unsigned int*)0xE000E014))
#define STK_VAL  (*((unsigned int*)0xE000E018))

#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
uint32_t counter = 0;
void delay(uint32_t delayInMilliseconds) {
    counter = delayInMilliseconds;
    while (counter > 0) {
        // keep checking counter until the ISR has decremented it to 0;
        // When it has, the function exits.
    }
}

void SysTick_Initialize(void)
{
    // Here I divide the system clock by 1000 so it counts down from 4000
    // instead of 4,000,000 to provide milliseconds instead of seconds
    SysTick->LOAD = SYS_CLOCK_HZ/1000 - 1;  // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    __disable_irq();
    counter = counter - 1;
    __enable_irq();
}

int main()
{
    SysTick_Initialize();
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while (1) {
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(500);
        
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(500);
    }
    
    return 0;
}
