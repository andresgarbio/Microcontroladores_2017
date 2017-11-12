#include <p18f45k50.h>
#include <xc.h>
#include <htc.h>

#define _XTAL_FREQ 16000000
 

void delay_100ms(void);

char cuenta; 

void interrupt high_priority_ISR(void){
    
    cuenta++;
    INTCONbits.INT0IF = 0;
}

void main(void)                    
{   
    
    RCONbits.IPEN = 1;
    INTCON2bits.INTEDG0 = 1;
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
    
            
    TRISD = 0x00;
    TRISBbits.TRISB0 = 1;
    ANSELBbits.ANSB0 = 0;
    LATD = 0xFF;
    
 while(1){
     cuenta = 0;
     for(int i = 0; i<10; i++){
         delay_100ms();
     }
     LATD = cuenta;
     
 }
 
 
}
 
void delay_100ms(void){
     
     TMR0L = 0x58;
     TMR0H = 0x9E;
     INTCONbits.TMR0IF = 0;
     T0CON = 0b10000011;
     while(INTCONbits.TMR0IF == 0);
     T0CON = 0x00;
 }
