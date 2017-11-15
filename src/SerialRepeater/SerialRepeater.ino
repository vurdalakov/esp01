#include <SoftwareSerial.h>

#define PIN_RX 8 // Connect to ESP-01 TX
#define PIN_TX 9 // Connect to ESP-01 RX

SoftwareSerial softSerial(PIN_RX, PIN_TX);

void setup() 
{
    uint32_t baud = 9600; // software serial works on 9600 max

    Serial.begin(baud);
    softSerial.begin(baud);

    Serial.print("Connected at ");
    Serial.println(baud);
}

void loop() 
{
    // process input from ESP-01

    while(softSerial.available() > 0) 
    {
        char c = softSerial.read();

        if ('\0' == c)
        {
            continue;
        }
        
        if ((c != '\r') && (c != '\n') && (c < 32))
        {
            continue;
        }

        Serial.print(c);
    }

    // process input from computer

    while (Serial.available() > 0)
    {
        char c = Serial.read();

        Serial.write(c); // echo

        softSerial.write(c);
    }
}
