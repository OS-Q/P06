/*******************************************************************************
****版本：V1.0.0
****平台：P12
****日期：2021-02-03
****作者：Qitas
****版权：OS-Q
*******************************************************************************/
#include <Arduino.h>
#include "SPI_UART.h"

char buffer[3];

SPISettings spisettings = SPISettings(16000000, MSBFIRST, SPI_MODE0);

void setup()
{
#ifdef __LGT8F__
  // we use the alternate pins D5 and D6, because we also want to use the Serial for debugging
    SPI_UART.useAlternatePins = true;
#endif
    buffer[0] = 0x55;
    buffer[1] = 0;
}


// THIS loop only makes sense on LGT8F with remapped pins ;)
void loop()
{
    buffer[2]++;
    // we do some SPI on D5/D6:
    SPI_UART.begin();
    SPI_UART.beginTransaction(spisettings);
    // now, you would do chip select before sending data
    SPI_UART.transfer(buffer, 3);
    SPI_UART.transfer(buffer, 3);
    // and de-chip-select after sending/receiving data
    SPI_UART.endTransaction();
    SPI_UART.end();

    // and then do some Serial debugging output at D0/D1:
    if ((buffer[2] % 40) == 0)
    {
        Serial.begin(115200);
        Serial.println(buffer[2], DEC);
        Serial.end();
    }
    else
    {
        delay(5);
    }
}

/*---------------------------(C) COPYRIGHT 2021 OS-Q -------------------------*/
