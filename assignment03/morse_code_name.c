#define RCC_AHB2ENR (*((unsigned int*)0x4002104C))
#define GPIOA_MODER (*((unsigned int*)0x48000000))
#define GPIOA_ODR (*((unsigned int*)0x48000014))
#define ORD5 (1 << 5)

const int shortDelay = 200000;
const int longDelay  = 600000;

void sleep(int delay) {
    int counter = 0;
    while (counter < delay) ++counter;
}

void off() {
    GPIOA_ODR = 0x0;
    sleep(longDelay);
}
    

void dot() {
    GPIOA_ODR |= ORD5;
    sleep(shortDelay);
    
    GPIOA_ODR = 0x0;
    sleep(shortDelay);
}

void dash() {
    GPIOA_ODR |= ORD5;
    sleep(longDelay);
    
    GPIOA_ODR = 0x0;
    sleep(shortDelay);
}

int main()
{
    RCC_AHB2ENR |= 0x1; // RCC_AHB2ENR: Enable clock to GPIOA
    GPIOA_MODER &= 0xFFFFF7FF;  // GPIOA_MODER: Set GPIOA to output
    
    while (1) {
        off();
        
        // J
        dot(); dash(); dash(); dash(); off();
        // A
        dot(); dash(); off();
        // S
        dot(); dot(); dot(); off();
        // O
        dash(); dash(); dash(); off();
        // N
        dash(); dot(); off();
        
        off();
    }
    
    
    
    
}