#ifndef TIMER_INITS_H
#define TIMER_INITS_H

#define TIMER0 PD3 
#define TIMER1_A PD5
#define TIMER1_B PD4 
#define TIMER2 PD7

#define TIMER0_PRESCALER_MASK ((1 << CS00) | (1 << CS01) | (1 << CS02))
#define TIMER1_PRESCALER_MASK ((1 << CS10) | (1 << CS11) | (1 << CS12))
#define TIMER2_PRESCALER_MASK ((1 << CS20) | (1 << CS21) | (1 << CS22))

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

#endif