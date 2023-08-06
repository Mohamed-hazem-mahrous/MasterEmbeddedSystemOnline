// Unit 3 - Lesson 4 - Lab 3
// Eng.Mohamed Hazem Yahya


#define SYSCTL_RCGC2_R 			(*((volatile unsigned int*)0x400FE108))

#define GPIO_PORTF_DIR_R 		(*((volatile unsigned int*)0x40025400))
#define GPIO_PORTF_DEN_R 		(*((volatile unsigned int*)0x4002551C))
#define GPIO_PORTF_DATA_R 		(*((volatile unsigned int*)0x400253FC))


int main(){
    volatile unsigned int delay_counter;

    SYSCTL_RCGC2_R = 0x20;

    // delay to make sure GPIOF is up and running
    for ( delay_counter = 0; delay_counter < 200; delay_counter++);

    GPIO_PORTF_DIR_R |= 1<<3; // Dir is output for pin 3 port f
    GPIO_PORTF_DEN_R |= 1<<3; // enable pin 3 port f

    while (1)
    {
        GPIO_PORTF_DATA_R |= 1<<3;
        for ( delay_counter = 0; delay_counter < 200000; delay_counter++); // delay to see the led is up

        GPIO_PORTF_DATA_R &= ~(1<<3);
        for ( delay_counter = 0; delay_counter < 200000; delay_counter++); // delay to see the led is down
    }

    return 0;
}

