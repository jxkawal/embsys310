#if 1

#define RCC_AHB2ENR (*((unsigned int*)0x4002104C))
#define GPIOA_MODER (*((unsigned int*)0x48000000))
#define GPIOA_ODR (*((unsigned int*)0x48000014))
#define ORD5 (1 << 5)

volatile int counter = 0;
int main()
{
    RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA
    GPIOA_MODER &= 0xFFFFF7FF;  // GPIOA_MODER: Set GPIOA to output
    
    GPIOA_ODR |= ORD5;
    while (1) {
      counter = 0;
      while (counter < 100000) ++counter;
      GPIOA_ODR ^= ORD5;
    }
}
#endif