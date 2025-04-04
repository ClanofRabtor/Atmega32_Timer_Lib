Bibliotheksname: timer_inits.h / timer_inits.c
________________________________________________________________________________________

Beschreibung: 
    Diese Bibliothek stellt Funktionen zur Verfügung, um die Timer 0, 1 und 2 des ATmega32 Mikrocontrollers zu initialisieren und zu steuern. 
    Sie ermöglicht die Konfiguration von Prescalern, Modi (Normal, CTC, PWM) und Ausgangsverhaltensweisen (COM-Modi).
________________________________________________________________________________________

Implementierungsdatei (timer_inits.c)

    Die Implementierungsdatei enthält den Code für die in der Header-Datei deklarierten Funktionen. 
    (Den Code aus meiner ersten Antwort habe ich hier nicht mit eingefügt um Redundanz zu vermeiden)
________________________________________________________________________________________

Funktionsbeschreibungen:

    INIT_Timer_X(ussPrescaler, uscModus, ...):
    Initialisiert den angegebenen Timer (0, 1 oder 2) mit den angegebenen Parametern.
    Parameter:
    ussPrescaler: Prescaler-Wert (z. B. 1, 8, 64, 256, 1024).
    uscModus: Timer-Modus (Normal, CTC, PWM).
    uscOCR_Value: OCR-Wert für den Compare Match.
    uscCOM_Mode: COM-Modus für das Ausgangsverhalten.
    uscOCR_Value_A/B: OCR-Werte für Timer 1 A und B.
    uscCOM_Mode_A/B: COM-Modi für Timer 1 A und B.
    SET_Timer_X_OCR(uscOCR_Value):
    Setzt den OCR-Wert des angegebenen Timers (0, 1 oder 2) zur Laufzeit.
    Parameter:
    uscOCR_Value: Der neue OCR-Wert.
    SET_Timer_1_OCR_A/B(uscOCR_Value_A/B):
    Setzt die OCR-Werte für Timer 1 A und B einzeln.

________________________________________________________________________________________

Wichtige Hinweise:

    Prescaler-Werte: 
        Die verfügbaren Prescaler-Werte hängen vom jeweiligen Timer ab. Sie bestimmen, wie oft der Timer-Zähler inkrementiert wird.

    Timer-Modi:

        Normal Mode: Der Timer zählt bis zum Überlauf und beginnt von 0.
        CTC Mode: Der Timer zählt bis zum OCR-Wert und wird zurückgesetzt.
        PWM Mode: Der Timer erzeugt ein PWM-Signal am Ausgangspin.

    COM-Modi: 
        Die COM-Modi steuern das Verhalten des Ausgangspins (OCx) bei einem Compare Match.

    Pin-Konfiguration: 
        Stelle sicher, dass du die entsprechenden Pins als Ausgänge konfigurierst, wenn du die COM-Modi verwendest.
        
    Interrupts:
        Wenn du Interrupts verwenden möchtest, musst du die entsprechenden Interrupt-Enable-Bits setzen und die Interrupt-Service-Routinen (ISRs) implementieren.

    Fehlerbehandlung:   
        Es wird empfohlen, Fehlerbehandlungsmechanismen hinzuzufügen, um ungültige Eingabewerte zu überprüfen.
        
    Dokumentation: 
        Dokumentiere deinen Code gut, um die Wartung und Wiederverwendung zu erleichtern.

________________________________________________________________________________________        

Verwendung der Bibliothek

    Füge die Dateien timer_inits.h und timer_inits.c zu deinem Projekt hinzu.
    Binde die Header-Datei in deine Hauptdatei ein: #include "timer_inits.h"
    Rufe die gewünschten Timer-Initialisierungs- und Steuerfunktionen auf.

Beispiel: 
->  // Timer 0 im CTC-Modus mit Prescaler 64 und OCR-Wert 128 initialisieren
    INIT_Timer_0(64, 2, 128, 2);

->  // Timer 1 im Fast-PWM-Modus mit Prescaler 8 und OCR-Werten initialisieren
    INIT_Timer_1(8, 7, 256, 3, 128, 2);

->  // Timer 1 im 8-Bit-Fast-PWM-Modus konfigurieren
    // Prescaler: 8
    // OCR1A: 128 (50 % Duty Cycle)
    // OCR1B: 64 (25 % Duty Cycle)
    // COM1A: Clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode)
    // COM1B: Clear OC1B on compare match, set OC1B at BOTTOM (non-inverting mode)
    INIT_Timer_1(8, 5, 128, 3, 64, 3);
________________________________________________________________________________________

Funktionen der Lib:

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