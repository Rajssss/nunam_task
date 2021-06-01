#include "timer.h"

#define 	__UNUSED	__attribute__((unused))

uint32_t *timer_event_callback;



/***********************************************************************************
 * 					 	Timer Start Count
 *
 * @fn: 		- 	timer_start_count
 *
 * @brief		-	This function will configure the TIMER0 peripheral, 
 *                  start the counting and call the callback upon each interval.
 *
 * @param[1]	-	Time in micro seconds.
 *
 * @param[2]	-	Pointer to the callback function.
 *
 * @return		-	void
 *
 * @Note		-	
 *
 */
void timer_start_count(uint32_t time, void *callback)
{
    timer_event_callback = callback;    // registewr the callback

    TIMER0->TASKS_STOP = 1              // STOP Timer0
    TIMER0->TASKS_CLEAR = 1             // Clear Timer0
    TIMER0->BITMODE = 3;                // Set BITMODE to 32Bit
    TIMER0->PRESCALER = 4;              // 1uS timer period
    TIMER0->INTENSET = 1 << 16;         // Enable COMPARE0 Interrupt
    TIMER0->CC[0] = time;               // Set time
    TIMER0->SHORTS |= 1;                // Clear the timer when COMPARE0 event triggered
    TIMER0->TASKS_START = 1;            // Start the timer
}


/***********************************************************************************
 * 					 	Timer Stop Handler
 *
 * @fn: 		- 	timer_stop_count
 *
 * @brief		-	This function will Stop the Timer operation.
 *
 * @return		-	void
 *
 * @Note		-	
 *
 */
void timer_stop_count(void)
{
    TIMER0->
}


/***********************************************************************************
 * 					 	Timer0 Interrupt Handler
 *
 * @fn: 		- 	TIMER0_IRQHandler
 *
 * @brief		-	This function will be called whenever Timer0 triggers an interrupt.
 *
 * @return		-	void
 *
 * @Note		-	It is defined in Startup code, of the MCU.
 *
 */
void TIMER0_IRQHandler(void)
{
  if (NRF_TIMER0->EVENTS_COMPARE[0] == 1)
  {
    NRF_TIMER0->EVENTS_COMPARE[0] = 0;
    *(timer_event_callback)();
  }
}
