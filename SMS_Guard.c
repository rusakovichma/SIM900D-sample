#include <avr/io.h>
#include <avr/interrupt.h>
#include "sim900.h"
#include "template.h"

char cmd_buff[80];

int main( void )
{
 init();

 simSetTextInput();
 simSetPhone();
 simSendMessage();

 for(;;){
 }
}

void init(){
  simInit();
  sei();
  simCommInit();
  delay(8000);
  delay(8000);
  delay(8000);
  delay(8000);
}
