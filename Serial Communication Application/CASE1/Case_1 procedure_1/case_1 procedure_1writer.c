#include <16F877A.h>
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NODEBUG, NOCPD
#use delay(crystal=4000000)

#use rs232 (baud=9600,xmit=PIN_C6,rcv=PIN_C7,parity=N,stop=1) //configuration for serial communication

void main()
{
 while(1)
 {
   printf("1");
   delay_ms(1000); 
   printf("2");  
   delay_ms(1000);
   printf("3");  
   delay_ms(1000); 
   printf("4"); 
   delay_ms(1000); 
   printf("*");  
   delay_ms(5000);
  }
 }
