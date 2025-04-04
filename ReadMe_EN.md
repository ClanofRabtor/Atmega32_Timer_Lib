Library Name: timer_inits.h / timer_inits.c
________________________________________________________________________________________

Description:
    This library provides functions to initialize and control the Timer 0, 1, and 2 of the ATmega32 microcontroller.
    It enables the configuration of prescalers, modes (Normal, CTC, PWM), and output behaviors (COM modes).
________________________________________________________________________________________

Implementation File (timer_inits.c)

    The implementation file contains the code for the functions declared in the header file.
    (The code from my first answer was not included here to avoid redundancy)
________________________________________________________________________________________

Function Descriptions:

    INIT_Timer_X(ussPrescaler, uscModus, ...):
    Initializes the specified timer (0, 1, or 2) with the given parameters.
    Parameters:
    ussPrescaler: Prescaler value (e.g., 1, 8, 64, 256, 1024).
    uscModus: Timer mode (Normal, CTC, PWM).
    uscOCR_Value: OCR value for the Compare Match.
    uscCOM_Mode: COM mode for the output behavior.
    uscOCR_Value_A/B: OCR values for Timer 1 A and B.
    uscCOM_Mode_A/B: COM modes for Timer 1 A and B.
    SET_Timer_X_OCR(uscOCR_Value):
    Sets the OCR value of the specified timer (0, 1, or 2) at runtime.
    Parameter:
    uscOCR_Value: The new OCR value.
    SET_Timer_1_OCR_A/B(uscOCR_Value_A/B):
    Sets the OCR values for Timer 1 A and B individually.

________________________________________________________________________________________

Important Notes:

    Prescaler Values:
        The available prescaler values depend on the respective timer. They determine how often the timer counter is incremented.

    Timer Modes:

        Normal Mode: The timer counts up to the overflow and restarts from 0.
        CTC Mode: The timer counts up to the OCR value and is reset.
        PWM Mode: The timer generates a PWM signal on the output pin.

    COM Modes:
        The COM modes control the behavior of the output pin (OCx) upon a Compare Match.

    Pin Configuration:
        Ensure that you configure the corresponding pins as outputs if you are using the COM modes.

    Interrupts:
        If you want to use interrupts, you need to set the corresponding interrupt enable bits and implement the Interrupt Service Routines (ISRs).

    Error Handling:
        It is recommended to add error handling mechanisms to check for invalid input values.

    Documentation:
        Document your code well to facilitate maintenance and reuse.

________________________________________________________________________________________

Using the Library

    Add the files timer_inits.h and timer_inits.c to your project.
    Include the header file in your main file: #include "timer_inits.h"
    Call the desired timer initialization and control functions.

Example:
->  // Initialize Timer 0 in CTC mode with prescaler 64 and OCR value 128
    INIT_Timer_0(64, 2, 128, 2);

->  // Initialize Timer 1 in Fast PWM mode with prescaler 8 and OCR values
    INIT_Timer_1(8, 7, 256, 3, 128, 2);

->  // Configure Timer 1 in 8-bit Fast PWM mode
    // Prescaler: 8
    // OCR1A: 128 (50% Duty Cycle)
    // OCR1B: 64 (25% Duty Cycle)
    // COM1A: Clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode)
    // COM1B: Clear OC1B on compare match, set OC1B at BOTTOM (non-inverting mode)
    INIT_Timer_1(8, 5, 128, 3, 64, 3);
________________________________________________________________________________________

Library Functions:

    void INIT_Timer_0_P_M(unsigned short ussPrescaler, unsigned char uscModus);
    void INIT_Timer_0_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value);
    void INIT_Timer_0_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode);
    void SET_Timer_0_OCR(unsigned char uscOCR_Value);
    void STOP_TIMER_0(void);
    void START_TIMER_0(void);

    void INIT_Timer_1_P_M(unsigned short ussPrescaler, unsigned char uscModus);
    void INIT_Timer_1_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value);
    void INIT_Timer_1_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode);
    void INIT_Timer_1_P_M_O_C_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value_A, unsigned char uscCOM_Mode_A, unsigned char uscOCR_Value_B, unsigned char uscCOM_Mode_B);
    void SET_Timer_1_OCR(unsigned char uscOCR_Value);
    void SET_Timer_1_OCR_A(unsigned char uscOCR_Value_A);
    void SET_Timer_1_OCR_B(unsigned char uscOCR_Value_B);
    void STOP_TIMER_1(void);
    void START_TIMER_1(void);

    void INIT_Timer_2_P_M(unsigned short ussPrescaler, unsigned char uscModus);
    void INIT_Timer_2_P_M_O(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value);
    void INIT_Timer_2_P_M_O_C(unsigned short ussPrescaler, unsigned char uscModus, unsigned char uscOCR_Value, unsigned char uscCOM_Mode);
    void SET_Timer_2_OCR(unsigned char uscOCR_Value);
    void STOP_TIMER_2(void);
    void START_TIMER_2(void);