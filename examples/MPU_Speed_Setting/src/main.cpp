/*******************************************************************************
****版本：V1.0.1
****平台：P117
****日期：2021-05-13
****作者：Qitas
****版权：OS-Q
*******************************************************************************/

#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    #if ((F_CPU) == 1000000)
    #warning F_CPU = 1MHz
    Serial.println("1MHz");
    #elif ((F_CPU) == 2000000)
    #warning F_CPU = 2MHz
    Serial.println("2MHz");
    #elif ((F_CPU) == 4000000)
    #warning F_CPU = 4MHz
    Serial.println("4MHz");
    #elif ((F_CPU) == 8000000)
    #warning F_CPU = 8MHz
    Serial.println("8MHz");
    #elif ((F_CPU) == 16000000)
    #warning F_CPU = 16MHz
    Serial.println("16MHz");
    #elif ((F_CPU) == 32000000)
    #warning F_CPU = 32MHz
    Serial.println("32MHz");
    #endif
    #if ((CLOCK_SOURCE) == 1)
    Serial.println("internal clock");
    #elif ((CLOCK_SOURCE) == 2)
    Serial.println("external clock");
    #endif

    while(1);
}


void loop()
{

}

/*---------------------------(C) COPYRIGHT 2021 OS-Q -------------------------*/
