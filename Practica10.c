#include <p18f45k50.h>
#include <xc.h>
#include <htc.h>

#define _XTAL_FREQ 16000000
 
void init_analogo(void){
    
    TRISAbits.RA0 = 1;
    ANSELAbits.ANSA0 = 1;
    
    ADCON0 = 0b0000001;
    ADCON1 = 0b0000000;
    ADCON2 = 0b0011110; 
    
}


void init_pwm(void){
    TRISCbits.TRISC2 = 0;
    ANSELCbits.ANSC2 = 0;
    CCP1CON = 0b00001100;
    CCPTMRS = 0X00;
    
    PR2 = 99;
    
    CCPR1L = 0x28;
    
    T2CON = 0b00000101;
   
    
    

}

void main(void)                    
{   
    
    TRISB = 0x00;
    ANSELB = 0x00;

 init_analogo();
 init_pwm();
 while(1){
     ADCON0bits.DONE = 1;
     while(ADCON0bits.DONE == 1);
     PORTB = ADRESH;
     CCPR1L = ADRESH;
         
     
     
 }
 
 
}