#include "setupTimer.h"

void setupTimer0(unsigned int CCR) {
  TA0CCR0 = CCR; // Compare match value
  TA0CCTL0 |= CCIE; // Enable interrupt on compare match
  TA0CCTL1 |= OUTMOD_7; // Set/reset
  TA0CTL |= TASSEL_1 | MC__UP | TACLR; // ACLK, up mode, clear
}

void setupTimer1(unsigned int CCR0, unsigned int CCR1) {
  TA1CCR0 = CCR0; // CCR0 value
  TA1CCR1 = CCR1; // CCR1 value
  TA1CCTL1 |= OUTMOD_7; // Set/reset
  TA1CTL |= TASSEL__ACLK | MC__UP | TACLR; // ACLK, up mode, clear
}