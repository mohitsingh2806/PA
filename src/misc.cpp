#include "misc.h"
#define BUC_BAUD 9600
#define CC_BAUD 115200

void init_all_peripherals(void)
{

  /************************************* controller initialisation start****************************************/
  init();       // arduino related initialisations
  delay(1000);  // system delay of 1 sec so that compass is powered on properly before we send the start data command
  Wire.begin(); // initialisation of I2C interface
    

  /************************************* controller initialisation end****************************************/
  wdt_enable(WDTO_4S); // 4 sec watchdog timer so that we don't get stuck in processes like compass cal indefinitely
}

// void sendFastPeriodicCommands(void)
// {

//   static unsigned long int timer = millis();
//   unsigned long int currentTime = millis();
//   static boolean connectingBUCFirstTime = true;
//   static boolean sent1 = false;
//   static boolean sent2 = false;
//   static boolean sent3 = false;
//   static boolean sent4 = false;
//   static boolean sent5 = false;
//   static boolean sent6 = false;
//   static boolean sent7 = false;
//   if (connectingBUCFirstTime)
//   {
//     BUCTerseMode();
//     connectingBUCFirstTime = false;
//   }
//   if (currentTime - timer >= 50 && currentTime - timer <= 100 && sent1 == false)
//   {
//     setOrCheckBUCAttVal(255);

//     sent1 = true;
//   }

//   if (currentTime - timer >= 100 && currentTime - timer <= 200 && sent2 == false)
//   {

//     passCustomCmdBUC(BUC_CHECK_INPUT_READING_CMD);

//     sent2 = true;
//   }

//   if (currentTime - timer >= 200 && currentTime - timer <= 300 && sent3 == false)
//   {
//     passCustomCmdBUC(BUC_CHECK_OUTPUT_POWER_CMD);

//     sent3 = true;
//   }

//   if (currentTime - timer >= 400 && currentTime - timer <= 500 && sent4 == false)
//   {

//     passCustomCmdBUC(BUC_CHECK_TX_OUTPUT_STATUS_CMD);
//     sent4 = true;
//   }
//   if (currentTime - timer >= 500 && currentTime - timer <= 600 && sent5 == false)
//   {

//     passCustomCmdBUC(BUC_CHECK_ALARM_CMD);
//     sent5 = true;
//   }
//   if (currentTime - timer >= 600 && currentTime - timer <= 700 && sent6 == false)
//   {
//     passCustomCmdBUC(BUC_CHECK_CURRENT_CONSUMPTION_CMD);

//     sent6 = true;
//   }
//   if (currentTime - timer >= 700 && currentTime - timer <= 800 && sent7 == false)
//   {
//     passCustomCmdBUC(BUC_CHECK_STARTUP_TX_OUTPUT_STATUS_CMD);
//     sent7 = true;
//   }

//   if (currentTime - timer > 700)
//   {
//     timer = currentTime;
//     sent1 = false;
//     sent2 = false;
//     sent3 = false;
//     sent4 = false;
//     sent5 = false;
//     sent6 = false;
//     sent7 = false;
//   }
// }

int searchChar(char *buff, char c, size_t start = 0, size_t end = 50)
{
  for (size_t i = start; i < end; i++)
  {
    if (buff[i] == c)
    {
      return i;
    }
  }
  return -1;
}
