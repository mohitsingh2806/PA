#ifndef MISC_H
#define MISC_H

// #define DEBUG_MODE   //DISABLE FOR SNMP TO WORK
#define SNMP_MODE
#include <Arduino.h>

#include <SPI.h>

#include <Wire.h>


#include <EEPROM.h>

#include <avr/wdt.h>
// #include "WMM_Tinier.h"

#define IP_ADDRESS 10,10,30,31
#define GATEWAY 0,0,0,0
#define SUBNET 255,0,0,0
#define MAC_ADDR   {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}

#define HTTP_PORT 80
#define OPENAMIP_PORT 5000



#define EEPROM_VALID_VALUE_FLAG 1

#define EEPROM_LOC_START 80
#define EEPROM_LOC_END 120


#define FALSE 0
#define TRUE 1
/****************************** BUTTONS****************************/


extern void init_all_peripherals(void);
#endif