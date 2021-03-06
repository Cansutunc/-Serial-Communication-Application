#include<16F877A.h>
#include<stdlib.h>
#FUSES XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOLVP,NOPUT,NODEBUG,NOCPD
#use delay(crystal=4000000)
#include <lcd.c>

#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7,parity=N,stop=1)  //configuration for serial communication
int counter = 0;    //counter to be used
char strlnput[3];  //string array for  input characters
char j=0;
unsigned long Kp=0 , Ki=0 , Kd=0 ;
void main()
{
lcd_init();
delay_ms(10);
while(1)
{
  if(kbhit())   //if data has been received
    {
       char j=getc();  //UART read
       if(j=='P')    //speacial character for serial input. If the received char is P then this condition is called 
       {      
        Kp=atol(strlnput);  //change string array to long variable
        printf("Kp= %lu" ,Kp);  //print inputstring value to the screen
        printf(LCD_PUTC,"\fKp=%lu",Kp);  //print PID  values to the lcd
        memset(strlnput,0,3); //clear the string array
        counter=0;   // counter to be zero again
       }
       else if(j=='I')  //speacial character for serial input. If the received char is I the this condition is called 
       {
        Ki=atol(strlnput); //change string array to long variable
        printf(" Ki=%lu" ,Ki);  //print inputstring value to the screen
        printf(LCD_PUTC,"\fKi=%lu",Ki);  //print PID  values to the lcd
        memset(strlnput,0,3); //clear the string array
        counter=0;   // counter to be zero again
       }
       else if(j=='D')  //speacial character for serial input. If the received char is D the this condition is called 
       {
        Kd=atol(strlnput);  //change string array to long variable
        printf(" Kd=%lu" ,Kd);  //print inputstring value to the screen
        printf(LCD_PUTC,"\fKd=%lu",Kd);  //print PID  values to the lcd
        memset(strlnput,0,3); //clear the string array
        counter=0;   // counter to be zero again             
       }
       else
       {
       strlnput[counter]=j;  //attend input character to the string array
       counter++; //increase the counter by 1.
       }
   }
 }
}

