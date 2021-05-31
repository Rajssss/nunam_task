/* Timer0 Base Address */
#define TIMER0_BASE_ADDR    0x40008000UL

#define __VOL volatile


/**********************************************************************************
 * Timer Peripheral Registers Structure
***********************************************************************************/
typedef struct
{
    __VOL uint32_t TASKS_START;                 // Start Timer
    __VOL uint32_t TASKS_STOP;                  // Stop Timer
    __VOL uint32_t TASKS_COUNT;                 // Increment Timer (Counter mode only)
    __VOL uint32_t TASKS_CLEAR;                 // Clear Timer
    __VOL uint32_t TASKS_SHUTDOWN;              // Shut down TImer
          uint32_t RESERVED1[11];               // Reserved Region
    __VOL uint32_t TASKS_CAPTURE[6];            // Capture Timer value to CC Registers
          uint32_t RESERVED2[58];               // Reserved Region
    __VOL uint32_t EVENTS_COMPARE[6]            // Compare event on CC[x] match
          uint32_t RESERVED3[42];               // Reserved Region
    __VOL uint32_t SHORTS;                      // Shortcut Register
          uint32_t RESERVED4[64];               // Reserved Region
    __VOL uint32_t INTENSET;                    // Enable interrupt
    __VOL uint32_t INTENCLR;                    // Disable Interrupt
          uint32_t RESERVED5[126];              // Reserved Region
    __VOL uint32_t MODE;                        // Timer mode selection
    __VOL uint32_t BITMODE;                     // No of bits used by timer
          uint32_t RESERVED6;                   // Reserved Region
    __VOL uint32_t PRESCALER;                   // Timer prescalar Register
          uint32_t RESERVED7[11];               // Reserved Region
    __VOL uint32_t CC[6];                       // Capture/Compare Register

}TIMERx_RegDef_ty;

/* Assing & Map TIMER0 Peripheral Registers */
#define TIMER0  ((TIMERx_RegDef_ty*) TIMER0_BASE_ADDR)

