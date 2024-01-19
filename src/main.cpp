/*
  This code continues other tasks and does not block the code to get data on serial port.
  The serial data is very slow even at 115200 baudrate. between reception of two symbols ideally (16000000/11520 =) 1388 instructions can be executed.
  The code ignores the serial data until it gets the start packet. After that is keeps on filling the buffer till the time buffer fills or END_MARKER
  is received.
  After that the data is processed.

  PC/CC           : UART0 :Serial    115200
  GPS             : UART1 :Serial1   115200
  INCLINOMETER    : UART2 :Serial2   115200
  COMPASS         : UART3 :Serial3   4800

//TODO
1. BLINK LOCK LED TILL SYSTEM IS READY                                                              -                            DONE
2. CORRECT LAT LONG FORMAT IN SNMP PACKET                                                           -                            DONE
3. STOW ON STEP TRACK (CONTROL CARD)                                                                -                            NOT DONE
4. REAL TIME STATUS OF BUC ON/OFF BASED ON TIMER                                                    -                            NOT DONE 
5. SNMP PRIVATE COMMUNITY STRINGS                                                                   -                            NOT DONE
6. Delay is required when elevation goes to 45 degree to take compass value. (CONTROL CARD)         -                            NOT DONE

*/



#include "misc.h"
#include <Arduino.h>
int main(void)
{
  init_all_peripherals(); // initialisation related tasks


  while (true)
  {
    wdt_reset();  //reset the watchdog timer, this is to make sure the code doesn't get stuck anywhere


  }
  return 0; // never reached
}
