#include "timer.h"

/* Prototypes */
void inc_count(void);

/*  */
uint32_t count = 0;

int main(void)
{
    timer_start_count(509000, &inc_count);         // Start counter with required time in uSec and callback

    while(1)
    {
        // Infinite loop
    }
}

/* Timer Callback */
void inc_count(void)
{
    /* Increament count */
    count++;
}