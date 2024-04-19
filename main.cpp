/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdint>
#include <cstdio>





int main()
{
    // Initialise the digital pin LED1 as an output
    AnalogIn LichtIn(A0);
    DigitalOut led1(LED1);

    float f_light_in=0;
    uint16_t light_in=0;
    char buffer[200];
    while (true) {

       f_light_in=LichtIn.read();
       light_in=LichtIn.read_u16();
       sprintf(buffer,"Helligkeit float = %.3f uint = %d \n\r",f_light_in,light_in);
       printf(buffer);
       
       if(f_light_in>= 0.45){

           led1=0;
       }   else{
           led1=1;
       }
       
       
        ThisThread::sleep_for(100ms);
    }
}
