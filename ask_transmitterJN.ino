// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
//COM4
#include <RHDatagram.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
RHDatagram RHD = RHDatagram(driver, 0);
// RH_ASK driver(2000, 2, 4, 5); // ESP8266: do not use pin 11

void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("Transmitter initializing");
    if (!RHD.init())
         Serial.println("init failed");
    Serial.print("This address is: ");
    Serial.println(RHD.thisAddress());
}

void loop()
{
    const char *msg = "hello";

    RHD.sendto((uint8_t *)msg, strlen(msg), 1);
    if(RHD.waitPacketSent())
      Serial.println("Package Sent");
    delay(200);
}
