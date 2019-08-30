//The goal is to use the HC-06 module for controlling Arduino via Bluetooth communication
//sending text commands from the the HC-06 module, and also sending text from the Arduino back to the the HC-06 module.


// SoftwareSerial.h creates a "virtual" serial port/UART
#include <SoftwareSerial.h>

// Connect the Bluetooth module TX pin to the digital pin 10 of the Atmega328 of the Arduino (D0)
#define BT_SERIAL_TX_DIO 0

// Connect the Bluetooth module TX pin to the digital pin 10 of the Atmega328 of the Arduino (D1)
#define BT_SERIAL_RX_DIO 1


// Inicialization Serial Port
SoftwareSerial BluetoothSerial (BT_SERIAL_TX_DIO, BT_SERIAL_RX_DIO);




void setup() 
{
// Set The Baud Rate For The Hardware Serial Port
Serial.begin(9600);

// Set The Baud Rate For The Software Serial Port
BluetoothSerial.begin(9600);

}


// Main Loop that will pass any data to and from the Bluetooth mode to the Host PC
  
void loop() 

{
  
// If the data is available from the Bluetooth Module then pass it on to the hardware serial port
if(BluetoothSerial.available()) {

// The data from the Bluetooth Module is printed on the Serial Monitor of the Arduino
  Serial.write(BluetoothSerial.read());
  }


// If the Data is available from the Hardware Serial Port the pass it on to the Bluetooth Module
if (Serial.available()) {

// The data from the Serial Monitor is printed on the software terminal "Cool Term"
  BluetoothSerial.write(Serial.read());
}
    
}
