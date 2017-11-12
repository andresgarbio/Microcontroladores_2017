#include <p18f45k50.h>
#include <xc.h>
#include <htc.h>

#define _XTAL_FREQ 16000000
 
/*************************************************************************
                       FUNCTION DECLARATIONS
**************************************************************************/
void Delay_us(char Delay);
void Delay_100us(unsigned long int Delay); 
void Data(int Value);          
void Cmd(int Value);            
void Send2LCD(const char Adr, const char *Lcd);

delay1seg(){
    for(int i=0;i<100;i++){
        __delay_ms(10);
    }
}

 
/*************************************************************************
                           MAIN FUNCTION
**************************************************************************/
void main()                    
{

char *strs[80] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79"};
TRISC = 0X00;                /* PORTC(control lines) configured as o/p  */
 TRISD = 0X00;                /* PORTD(data lines) configured as o/p     */
 TRISB = 0xFF;
 Delay_us(30);                     
 Cmd(0X30);                   /* LCD Specification Cmds                  */
 Delay_us(30);
 Cmd(0X30);                   /* LCD Specification Cmds                  */
 Delay_us(30);
 Cmd(0X30);                   /* LCD Specification Cmds                  */
 Delay_us(30);
 Cmd(0X38);                   /* Double Line Display Command             */
 Cmd(0X06);                   /* Auto Increment Location Address Command */
 Cmd(0X0C);                   /* LCD Display ON Command                  */
 Cmd(0X01);                   /* Clear Display Command                   */
 Delay_100us(100);
 
 
 Send2LCD(0x80,"practica 7");  /*Displays string in the first line        */
 Send2LCD(0xc0,"micros");     /* Displays string in the second line      */
 
 while(1){
     
     
      if(PORTBbits.RB7 == 0){
          for(int j = 0; j<80; j++){
             Send2LCD(0x80,"                ");
             Send2LCD(0xc0,"                "); 
             Send2LCD(0x80,strs[j]); 
             delay1seg();   
             if(PORTBbits.RB6 == 0){
                 j = 80;
             }
          }
        }
     
     if(PORTBbits.RB6 == 0){
          for(int j = 45; j>0; j--){
             Send2LCD(0x80,"                ");
             Send2LCD(0xc0,"                "); 
             Send2LCD(0x80,strs[j]); 
             delay1seg();   
             if(PORTBbits.RB7 == 0){
                 j = 0;
             }
          }
        }
      
       Send2LCD(0x80,"practica 7");  /*Displays string in the first line        */
       Send2LCD(0xc0,"micros");     /* Displays string in the second line      */
 }
}
 
/*************************************************************************
* Function    : Cmd                                                      *
*                                                                        *
* Description : Function to send a command to LCD                        *
*                                                                        *
* Parameters  : Value - command to be sent                               *
**************************************************************************/
void Cmd(int Value)
{
 PORTD = Value;               /* Write the command to data lines         */
 LATCbits.LC0=0   ;                   /* RS-0(command register)                  */
 LATCbits.LC1   = 1;                   /* E-1(enable)                             */
 Delay_us(100);              
 LATCbits.LC1   = 0;                   /* E-0(enable)                             */
}
 
/*************************************************************************
* Function    : Data                                                     *
*                                                                        *
* Description : Function to display single character on LCD              *
*                                                                        *
* Parameters  : Value - character to be displayed                        *
**************************************************************************/
void Data(int Value)
{
 PORTD = Value;               /* Write the character to data lines       */
 LATCbits.LC0   = 1;                   /* RS-1(data register)                     */
 LATCbits.LC1   = 1;                   /* E-1(enable)                             */
 Delay_us(100);              
 LATCbits.LC1   = 0;                   /* E-0(enable)                             */
}
 
/*************************************************************************
* Function    : Send2LCD                                                 *
*                                                                        *
* Description : Function to display string on LCD                        *
*                                                                        *
* Parameters  : Adr - location                                           *
*               String to be displayed                                   *
**************************************************************************/
void Send2LCD(const char Adr, const char *Lcd)
{
 Cmd(Adr);                    /* Address of location to display string   */
 while(*Lcd!='\0')            /* Check for termination character         */
 {
  Data(*Lcd);                 /* Display the character on LCD            */
  Lcd++;                      /* Increment the pointer                   */
 }
}
 
/*************************************************************************
* Function    : Delay_us                                                 *
*                                                                        *
* Description : Function for 1 microsecond delay                         *
*                                                                        *
* Parameter   : Delay - delay in microseconds                            *
**************************************************************************/
void Delay_us(char Delay)    
{        
 while((--Delay)!=0);    
}
 
/*************************************************************************
* Function    : Delay_100us                                              *
*                                                                        *
* Description : Function for delay                                       *
*                                                                        *
* Parameter   : Delay - delay in microseconds                            *
**************************************************************************/
void Delay_100us(unsigned long int Delay)
{
 Delay = Delay*15;
 while((--Delay)!=0);
}
 

