#include "setupADC.h"

// *** SETUP ADC WITH TIMER 1 TIRGGER *** //
void setupTimerTriggerADC() {
  SYSCFG2 |= ADCPCTL9; // Enable analogue input A9
  ADCCTL0 |= ADCON; // ADC on
  ADCCTL1 |= ADCSHS_2 | ADCCONSEQ_2; // repeat single channel, start on timer trigger
  ADCCTL2 |= ADCRES; // 10-bit conversion
  ADCMCTL0 |= ADCINCH_9; // ADC input A9
  ADCIE |= ADCIE0; // Enable conversion complete interrupt
  
  ADCCTL0 |= ADCENC; // Enable ADC
}

// *** SETUP ADC WITH 1.5V REFERENCE AND TIMER 1 TRIGGER *** //
void setupRefADC() {
  SYSCFG2 |= ADCPCTL9; // Enable analogue input A8
  ADCCTL0 |= ADCON; // ADC on
  ADCCTL1 |= ADCSHS_2 | ADCCONSEQ_2; // repeat single channel, start on timer trigger
  ADCCTL2 |= ADCRES; // 10-bit conversion
  ADCMCTL0 |= ADCSREF_1 | ADCINCH_9; // 1.5V reference, ADC input A8
  ADCIE |= ADCIE0; // Enable conversion complete interrupt
  
  ADCCTL0 |= ADCENC; // Enable ADC
}

// *** SETUP STANDARD ADC *** //
void setupADC() {
  SYSCFG2 |= ADCPCTL9; // Enable analogue input A9
  ADCCTL0 |= ADCMSC | ADCON; // ADC on
  ADCCTL1 |= ADCSHP | ADCCONSEQ_2 | ADCSSEL_1; // repeat single channel, start on timer trigger
  ADCCTL2 |= ADCRES; // 10-bit conversion
  ADCMCTL0 |= ADCINCH_9; // ADC input A9
  ADCIE |= ADCIE0; // Enable conversion complete interrupt
  
  ADCCTL0 |= ADCENC; // Enable ADC
}

// *** INTERNAL VOLTAGE REFERENCE SETUP *** //
void setupIntRef() {
  PMMCTL0_H = PMMPW_H; // Unlock PMM registers
  PMMCTL2 |= INTREFEN; // Enable internal 1.5V reference
  while(!REFGENRDY) { // Wait until reference has stabilised
    ; // Do nothing
  }
}