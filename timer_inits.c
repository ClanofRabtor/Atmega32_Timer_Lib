#include "Timer_Inits.h"
#include <avr/io.h>


static unsigned char uscTimer0_Prescaler = 0;
static unsigned char uscTimer1_Prescaler = 0;
static unsigned char uscTimer2_Prescaler = 0;

// Timer 0 Implementierungen
void INIT_Timer_0_P_M(unsigned short ussPrescaler, unsigned char uscModus) {
    TCCR0 = 0; // Reset TCCR0
    TCNT0 = 0; // Reset Timer Counter

    // Modus-Auswahl
    switch (uscModus) {
        case 0: // Normal Mode
            TCCR0 |= 0x00;
            break;
        case 1: // PWM, Phase Correct
            TCCR0 |= (1 << WGM00);
            break;
        case 2: // CTC Mode
            TCCR0 |= (1 << WGM01);
            break;
        case 3: // Fast PWM
            TCCR0 |= (1 << WGM00) | (1 << WGM01);
            break;
    }

    // Prescaler-Auswahl
    switch (ussPrescaler) {
        case 1:
            TCCR0 |= (1 << CS00);
            break;
        case 8:
            TCCR0 |= (1 << CS01);
            break;
        case 64:
            TCCR0 |= (1 << CS00) | (1 << CS01);
            break;
        case 256:
            TCCR0 |= (1 << CS02);
            break;
        case 1024:
            TCCR0 |= (1 << CS00) | (1 << CS02);
            break;
    }
}

void INIT_Timer_0_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value) {
    INIT_Timer_0_P_M(ussPrescaler, uscModus);
    OCR0 = uscOCR_Value;
}

void INIT_Timer_0_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode) {
    INIT_Timer_0_P_M_O(ussPrescaler, uscModus, uscOCR_Value);

    // COM-Modus-Auswahl
    switch (uscCOM_Mode) {
        case 1: // Toggle OC0 on compare match
            TCCR0 |= (1 << COM00);
            break;
        case 2: // Clear OC0 on compare match
            TCCR0 |= (1 << COM01);
            break;
        case 3: // Set OC0 on compare match
            TCCR0 |= (1 << COM00) | (1 << COM01);
            break;
    }

    DDRB |= (1 << TIMER0); // Set OC0 pin as output
}

void SET_Timer_0_OCR(unsigned char uscOCR_Value) {
    OCR0 = uscOCR_Value;
}

void STOP_Timer_0(void) {
    uscTimer0_Prescaler = TCCR0 & TIMER0_PRESCALER_MASK;
    TCCR0 &= ~(TIMER0_PRESCALER_MASK);
}

void START_Timer_0(void) {
    TCCR0 |= uscTimer0_Prescaler;
}

// Timer 1 Implementierungen
void INIT_Timer_1_P_M(unsigned short ussPrescaler, unsigned char uscModus) {
    TCCR1A = 0; // Reset TCCR1A
    TCCR1B = 0; // Reset TCCR1B
    TCNT1 = 0; // Reset Timer Counter

    // Modus-Auswahl
    switch (uscModus) {
        case 0: // Normal Mode
            TCCR1B |= 0x00;
            break;
        case 1: // PWM, Phase Correct, 8-bit
            TCCR1A |= (1 << WGM10);
            break;
        case 2: // PWM, Phase Correct, 9-bit
            TCCR1A |= (1 << WGM11);
            break;
        case 3: // PWM, Phase Correct, 10-bit
            TCCR1A |= (1 << WGM10) | (1 << WGM11);
            break;
        case 4: // CTC Mode, OCR1A as TOP
            TCCR1B |= (1 << WGM12);
            break;
        case 5: // Fast PWM, 8-bit
            TCCR1A |= (1 << WGM10);
            TCCR1B |= (1 << WGM12);
            break;
        case 6: // Fast PWM, 9-bit
            TCCR1A |= (1 << WGM11);
            TCCR1B |= (1 << WGM12);
            break;
        case 7: // Fast PWM, 10-bit
            TCCR1A |= (1 << WGM10) | (1 << WGM11);
            TCCR1B |= (1 << WGM12);
            break;
        case 12: // CTC Mode, ICR1 as TOP
            TCCR1B |= (1 << WGM13);
            break;
        case 14: // Fast PWM, ICR1 as TOP
            TCCR1A |= (1 << WGM11);
            TCCR1B |= (1 << WGM13);
            break;
        case 15: // Fast PWM, OCR1A as TOP
            TCCR1A |= (1 << WGM10) | (1 << WGM11);
            TCCR1B |= (1 << WGM13);
            break;
    }

    // Prescaler-Auswahl
    switch (ussPrescaler) {
        case 1:
            TCCR1B |= (1 << CS10);
            break;
        case 8:
            TCCR1B |= (1 << CS11);
            break;
        case 64:
            TCCR1B |= (1 << CS10) | (1 << CS11);
            break;
        case 256:
            TCCR1B |= (1 << CS12);
            break;
        case 1024:
            TCCR1B |= (1 << CS10) | (1 << CS12);
            break;
    }
}

void INIT_Timer_1_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value) {
    INIT_Timer_1_P_M(ussPrescaler, uscModus);
    OCR1A = uscOCR_Value;
}

void INIT_Timer_1_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode) {
    INIT_Timer_1_P_M_O(ussPrescaler, uscModus, uscOCR_Value);

    // COM-Modus-Auswahl für OCR1A
    switch (uscCOM_Mode) {
        case 1: // Toggle OC1A on compare match
            TCCR1A |= (1 << COM1A0);
            break;
        case 2: // Clear OC1A on compare match
            TCCR1A |= (1 << COM1A1);
            break;
        case 3: // Set OC1A on compare match
            TCCR1A |= (1 << COM1A0) | (1 << COM1A1);
            break;
    }

    DDRD |= (1 << TIMER1_A); // Set OC1A pin as output
}

void INIT_Timer_1_P_M_O_C_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value_A, unsigned char uscCOM_Mode_A, unsigned char uscOCR_Value_B, unsigned char uscCOM_Mode_B) {
    INIT_Timer_1_P_M_O_C(ussPrescaler, uscModus, uscOCR_Value_A, uscCOM_Mode_A);
    OCR1B = uscOCR_Value_B;

    // COM-Modus-Auswahl für OCR1B
    switch (uscCOM_Mode_B) {
        case 1: // Toggle OC1B on compare match
            TCCR1A |= (1 << COM1B0);
            break;
        case 2: // Clear OC1B on compare match
            TCCR1A |= (1 << COM1B1);
            break;
        case 3: // Set OC1B on compare match
            TCCR1A |= (1 << COM1B0) | (1 << COM1B1);
            break;
    }

    DDRD |= (1 << TIMER1_B); // Set OC1B pin as output
}

void SET_Timer_1_OCR(unsigned char uscOCR_Value) {
    OCR1A = uscOCR_Value;
}

void SET_Timer_1_OCR_A(unsigned char uscOCR_Value_A) {
    OCR1A = uscOCR_Value_A;
}

void SET_Timer_1_OCR_B(unsigned char uscOCR_Value_B) {
    OCR1B = uscOCR_Value_B;
}

void STOP_Timer_1(void) {
    uscTimer1_Prescaler = TCCR1B & TIMER1_PRESCALER_MASK;
    TCCR1B &= ~(TIMER1_PRESCALER_MASK);
}

void START_Timer_1(void) {
    TCCR1B |= uscTimer1_Prescaler;
}

// Timer 2 Implementierungen
void INIT_Timer_2_P_M(unsigned short ussPrescaler, unsigned char uscModus) {
    TCCR2 = 0; // Reset TCCR2
    TCNT2 = 0; // Reset Timer Counter

    // Modus-Auswahl
    switch (uscModus) {
        case 0: // Normal Mode
            TCCR2 |= 0x00;
            break;
        case 1: // PWM, Phase Correct
            TCCR2 |= (1 << WGM20);
            break;
        case 2: // CTC Mode
            TCCR2 |= (1 << WGM21);
            break;
        case 3: // Fast PWM
            TCCR2 |= (1 << WGM20) | (1 << WGM21);
            break;
    }

    // Prescaler-Auswahl
    switch (ussPrescaler) {
        case 1:
            TCCR2 |= (1 << CS20);
            break;
        case 8:
            TCCR2 |= (1 << CS21);
            break;
        case 32:
            TCCR2 |= (1 << CS20) | (1 << CS21);
            break;
        case 64:
            TCCR2 |= (1 << CS22);
            break;
        case 128:
            TCCR2 |= (1 << CS20) | (1 << CS22);
            break;
        case 256:
            TCCR2 |= (1 << CS21) | (1 << CS22);
            break;
        case 1024:
            TCCR2 |= (1 << CS20) | (1 << CS21) | (1 << CS22);
            break;
    }
}

void INIT_Timer_2_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value) {
    INIT_Timer_2_P_M(ussPrescaler, uscModus);
    OCR2 = uscOCR_Value;
}

void INIT_Timer_2_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode) {
    INIT_Timer_2_P_M_O(ussPrescaler, uscModus, uscOCR_Value);

    // COM-Modus-Auswahl
    switch (uscCOM_Mode) {
        case 1: // Toggle OC2 on compare match
            TCCR2 |= (1 << COM20);
            break;
        case 2: // Clear OC2 on compare match
            TCCR2 |= (1 << COM21);
            break;
        case 3: // Set OC2 on compare match
            TCCR2 |= (1 << COM20) | (1 << COM21);
            break;
    }

    DDRD |= (1 << TIMER2); // Set OC2 pin as output
}

void SET_Timer_2_OCR(unsigned char uscOCR_Value) {
    OCR2 = uscOCR_Value;
}

void STOP_Timer_2(){
    uscTimer2_Prescaler = TCCR2 & TIMER2_PRESCALER_MASK;
    TCCR2 &= ~(TIMER2_PRESCALER_MASK);
}

void START_TIMER_2(void){
    TCCR2 |= uscTimer2_Prescaler;
}
