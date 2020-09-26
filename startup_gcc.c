#include "stdint.h"

#define SRAM_START 0x20000000
#define SRAM_SIZE (32U * 1024) // 32KB
#define SRAM_END SRAM_START + SRAM_SIZE

void reset_handler(void);
static void nmi_handler(void);
static void hard_fault_handler(void);
static void default_handler(void);

/**
  The entry point for the application.
*/
extern int main(void);

/**
 * The vector table. Note that the proper constructs must be placed on this to
 * ensure that it ends up at physical address 0x0000 0000.
*/
uint32_t vectors[] __attribute__ ((section(".isr_vector"))) =
{
    SRAM_END,                               // The initial stack pointer
    (uint32_t)&reset_handler,                    // The reset handler
    (uint32_t)&nmi_handler,                       // The NMI handler
    (uint32_t)&hard_fault_handler,                    // The hard fault handler
    (uint32_t)&default_handler,           // The MPU fault handler
    (uint32_t)&default_handler,           // The bus fault handler
    (uint32_t)&default_handler,           // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    (uint32_t)&default_handler,           // SVCall handler
    (uint32_t)&default_handler,           // Debug monitor handler
    0,                                      // Reserved
    (uint32_t)&default_handler,           // The PendSV handler
    (uint32_t)&default_handler,           // The SysTick handler
    (uint32_t)&default_handler,           // GPIO Port A
    (uint32_t)&default_handler,           // GPIO Port B
    (uint32_t)&default_handler,           // GPIO Port C
    (uint32_t)&default_handler,           // GPIO Port D
    (uint32_t)&default_handler,           // GPIO Port E
    (uint32_t)&default_handler,           // UART0 Rx and Tx
    (uint32_t)&default_handler,           // UART1 Rx and Tx
    (uint32_t)&default_handler,           // SSI0 Rx and Tx
    (uint32_t)&default_handler,           // I2C0 Master and Slave
    (uint32_t)&default_handler,           // PWM Fault
    (uint32_t)&default_handler,           // PWM Generator 0
    (uint32_t)&default_handler,           // PWM Generator 1
    (uint32_t)&default_handler,           // PWM Generator 2
    (uint32_t)&default_handler,           // Quadrature Encoder 0
    (uint32_t)&default_handler,           // ADC Sequence 0
    (uint32_t)&default_handler,           // ADC Sequence 1
    (uint32_t)&default_handler,           // ADC Sequence 2
    (uint32_t)&default_handler,           // ADC Sequence 3
    (uint32_t)&default_handler,           // Watchdog timer
    (uint32_t)&default_handler,           // Timer 0 subtimer A
    (uint32_t)&default_handler,           // Timer 0 subtimer B
    (uint32_t)&default_handler,           // Timer 1 subtimer A
    (uint32_t)&default_handler,           // Timer 1 subtimer B
    (uint32_t)&default_handler,           // Timer 2 subtimer A
    (uint32_t)&default_handler,           // Timer 2 subtimer B
    (uint32_t)&default_handler,           // Analog Comparator 0
    (uint32_t)&default_handler,           // Analog Comparator 1
    (uint32_t)&default_handler,           // Analog Comparator 2
    (uint32_t)&default_handler,           // System Control (PLL, OSC, BO)
    (uint32_t)&default_handler,           // FLASH Control
    (uint32_t)&default_handler,           // GPIO Port F
    (uint32_t)&default_handler,           // GPIO Port G
    (uint32_t)&default_handler,           // GPIO Port H
    (uint32_t)&default_handler,           // UART2 Rx and Tx
    (uint32_t)&default_handler,           // SSI1 Rx and Tx
    (uint32_t)&default_handler,           // Timer 3 subtimer A
    (uint32_t)&default_handler,           // Timer 3 subtimer B
    (uint32_t)&default_handler,           // I2C1 Master and Slave
    (uint32_t)&default_handler,           // Quadrature Encoder 1
    (uint32_t)&default_handler,           // CAN0
    (uint32_t)&default_handler,           // CAN1
    (uint32_t)&default_handler,           // CAN2
    (uint32_t)&default_handler,           // Ethernet
    (uint32_t)&default_handler,           // Hibernate
    (uint32_t)&default_handler,           // USB0
    (uint32_t)&default_handler,           // PWM Generator 3
    (uint32_t)&default_handler,           // uDMA Software Transfer
    (uint32_t)&default_handler,           // uDMA Error
    (uint32_t)&default_handler,           // ADC1 Sequence 0
    (uint32_t)&default_handler,           // ADC1 Sequence 1
    (uint32_t)&default_handler,           // ADC1 Sequence 2
    (uint32_t)&default_handler,           // ADC1 Sequence 3
    (uint32_t)&default_handler,           // I2S0
    (uint32_t)&default_handler,           // External Bus Interface 0
    (uint32_t)&default_handler,           // GPIO Port J
    (uint32_t)&default_handler,           // GPIO Port K
    (uint32_t)&default_handler,           // GPIO Port L
    (uint32_t)&default_handler,           // SSI2 Rx and Tx
    (uint32_t)&default_handler,           // SSI3 Rx and Tx
    (uint32_t)&default_handler,           // UART3 Rx and Tx
    (uint32_t)&default_handler,           // UART4 Rx and Tx
    (uint32_t)&default_handler,           // UART5 Rx and Tx
    (uint32_t)&default_handler,           // UART6 Rx and Tx
    (uint32_t)&default_handler,           // UART7 Rx and Tx
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    (uint32_t)&default_handler,           // I2C2 Master and Slave
    (uint32_t)&default_handler,           // I2C3 Master and Slave
    (uint32_t)&default_handler,           // Timer 4 subtimer A
    (uint32_t)&default_handler,           // Timer 4 subtimer B
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    (uint32_t)&default_handler,           // Timer 5 subtimer A
    (uint32_t)&default_handler,           // Timer 5 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 0 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 0 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 1 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 1 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 2 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 2 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 3 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 3 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 4 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 4 subtimer B
    (uint32_t)&default_handler,           // Wide Timer 5 subtimer A
    (uint32_t)&default_handler,           // Wide Timer 5 subtimer B
    (uint32_t)&default_handler,           // FPU
    (uint32_t)&default_handler,           // PECI 0
    (uint32_t)&default_handler,           // LPC 0
    (uint32_t)&default_handler,           // I2C4 Master and Slave
    (uint32_t)&default_handler,           // I2C5 Master and Slave
    (uint32_t)&default_handler,           // GPIO Port M
    (uint32_t)&default_handler,           // GPIO Port N
    (uint32_t)&default_handler,           // Quadrature Encoder 2
    (uint32_t)&default_handler,           // Fan 0
    0,                                      // Reserved
    (uint32_t)&default_handler,           // GPIO Port P (Summary or P0)
    (uint32_t)&default_handler,           // GPIO Port P1
    (uint32_t)&default_handler,           // GPIO Port P2
    (uint32_t)&default_handler,           // GPIO Port P3
    (uint32_t)&default_handler,           // GPIO Port P4
    (uint32_t)&default_handler,           // GPIO Port P5
    (uint32_t)&default_handler,           // GPIO Port P6
    (uint32_t)&default_handler,           // GPIO Port P7
    (uint32_t)&default_handler,           // GPIO Port Q (Summary or Q0)
    (uint32_t)&default_handler,           // GPIO Port Q1
    (uint32_t)&default_handler,           // GPIO Port Q2
    (uint32_t)&default_handler,           // GPIO Port Q3
    (uint32_t)&default_handler,           // GPIO Port Q4
    (uint32_t)&default_handler,           // GPIO Port Q5
    (uint32_t)&default_handler,           // GPIO Port Q6
    (uint32_t)&default_handler,           // GPIO Port Q7
    (uint32_t)&default_handler,           // GPIO Port R
    (uint32_t)&default_handler,           // GPIO Port S
    (uint32_t)&default_handler,           // PWM 1 Generator 0
    (uint32_t)&default_handler,           // PWM 1 Generator 1
    (uint32_t)&default_handler,           // PWM 1 Generator 2
    (uint32_t)&default_handler,           // PWM 1 Generator 3
    (uint32_t)&default_handler            // PWM 1 Fault
};

/**
 * The following are constructs created by the linker, indicating where the
 * the "data" and "bss" segments reside in memory.  The initializers for the
 * "data" segment resides immediately following the "text" segment.
 */
extern unsigned long _etext;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

/**
 * This is the first function to be called after cpu initialization.
 * Copy the initialized global and static data from flash to ram
 * Zeroes the non-initializes data
 * Call the application entry point (main)
 */
void reset_handler(void)
{
    // Copy initialized data from Flash to Ram
    uint32_t size = &_edata - &_sdata;

    uint8_t *pDst = (uint8_t *)&_sdata;
    uint8_t *pSrc = (uint8_t *)&_etext;

    for (uint32_t i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }
    
    // Clear the zero segment
    size = &_ebss - &_sbss;
    pDst = (uint8_t *)&_sbss;
    
    for (uint32_t i = 0; i < size; i++) 
    {
        *pDst++ = 0;
    }

    // Call the application's entry point.
    main();
}

/**
 * This is the code that gets called when the processor receives a NMI.  
 */
static void nmi_handler(void)
{
    while(1)
        ;
}

/**
 * This is the code that gets called when the processor receives a fault
 * interrupt.  
 */
static void hard_fault_handler(void)
{
    while(1)
        ;
}

/**
 * This is the code that gets called when the processor receives an unexpected
 * interrupt. 
 */
static void default_handler(void)
{
    while(1)
        ;
}
