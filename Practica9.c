#include <p18f45k50.h>
#include <xc.h>
#include <htc.h>

#define _XTAL_FREQ 16000000
 

void delay_50ms(void);
void delay_250ms(void);

char cuenta; 

void interrupt high_priority_ISR(void){
    delay_50ms();
    cuenta = cuenta * 2;
    if (cuenta > 8){
         cuenta = 1;
     }
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
    
    cuenta = 1;
    
 while(1){
     
     for(int i = 0; i< cuenta; i++){
         delay_250ms();
     }
     
     LATD = LATD ^ 0x01;
     
     
 }
 
 
}
 
void delay_50ms(void){
     
     TMR0L = 0x2C;
     TMR0H = 0xCF;
     INTCONbits.TMR0IF = 0;
     T0CON = 0b10000011;
     while(INTCONbits.TMR0IF == 0);
     T0CON = 0x00;
 }

void delay_250ms(void){
     
     for(int i = 0; i<5; i++){
         delay_50ms();
     }
 }