#include <p18f45k50.h>
#include <xc.h>
#include <htc.h>

#define _XTAL_FREQ 16000000

void interrupt high_isr(void){ // funcion de interrupciones de alta prioridad
}

void interrupt low_priority low_isr(void){ // funcion de interrupciones de baja prioridad
}

unsigned char Read_Key(unsigned char row, unsigned char column);

delay5mseg(){
    for(int i=0;i<1;i++){
        __delay_ms(10);
    }
}

delay10mseg(){
    for(int i=0;i<1;i++){
        __delay_ms(10);
    }
}

delay100mseg(){
    for(int i=0;i<10;i++){
        __delay_ms(10);
    }
}

delay1000mseg(){
    for(int i=0;i<100;i++){
        __delay_ms(10);
    }
}

void main()
{
    
    ANSELB=0; 
    ANSELD=0;//PortB digital
    TRISB=0xF0;
    TRISD=0x00;
    LATB= 0x0F;
    LATD= 0x00;
    while(1)
    {
        LATD= 0x00;
        LATBbits.LB3=1;
        LATBbits.LB0=0;
        __delay_ms(1);
        

        
        if(PORTBbits.RB4 == 0){
            LATD= 1;
            delay10mseg();
        }if(PORTBbits.RB5 == 0){
            LATD= 4;
            delay10mseg();
        }if(PORTBbits.RB6 == 0){
            LATD= 7;
            delay10mseg();
        }if(PORTBbits.RB7 == 0){
            LATD= 14;
            delay10mseg();
        }
       
        LATBbits.LB0=1;
        LATBbits.LB1=0;
        __delay_ms(1);
        
        if(PORTBbits.RB4 == 0){
            LATD= 2;
            delay10mseg();
        }if(PORTBbits.RB5 == 0){
            LATD= 5;
            delay10mseg();
        }if(PORTBbits.RB6 == 0){
            LATD= 8;
            delay10mseg();
        }if(PORTBbits.RB7 == 0){
            LATD= 0;
            delay10mseg();
        }
       
        LATBbits.LB1=1;
        LATBbits.LB2=0;
        __delay_ms(1);
        
        
        if(PORTBbits.RB4 == 0){
            LATD= 3;
            delay10mseg();
        }if(PORTBbits.RB5 == 0){
            LATD= 6;
            delay10mseg();
        }if(PORTBbits.RB6 == 0){
            LATD= 9;
            delay10mseg();
        }if(PORTBbits.RB7 == 0){
            LATD= 15;
            delay10mseg();
        }
       
        
        LATBbits.LB2=1;
        LATBbits.LB3=0;
        __delay_ms(1);
        
        
        if(PORTBbits.RB4 == 0){
            LATD= 10;
            delay10mseg();
        }if(PORTBbits.RB5 == 0){
            LATD= 11;
            delay10mseg();
        }if(PORTBbits.RB6 == 0){
            LATD= 12;
            delay10mseg();
        }if(PORTBbits.RB7 == 0){
            LATD= 13;
            delay10mseg();
        }
       
        
        
    }
}
