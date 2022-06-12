#include <SPI.h>
#include <nRF24L01.h>
#include <RF24Network.h>
#include <RF24.h>
RF24 radio(2,A0); // CE, CSN
#include <DMD2.h>
#include <fonts/Arial_Black_16.h>
#include <SPI.h>
#include <SoftwareSerial.h>/* you can remove the fonts if unused */
String theMessage;
RF24Network network(radio);      // Include the radio in the network
int16_t this_node = 042;   // Address of this node in Octal

//const uint16_t node01 = 01;
//const uint16_t node03 = 03;
SoftDMD dmd(1,1);
// Number of P10 panels used X, Y
DMD_TextBox box(dmd, 1, 1, 25, 15);
// Set Box (dmd, x, y, Height, Width)
void setup() {
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
  radio.begin();
 // radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
 // radio.startListening();
 network.begin(90, this_node);  //(channel, node address)

 dmd.setBrightness(200); // Set brightness 0 - 255
  dmd.selectFont(Arial_Black_16); // Font used
  dmd.begin();     // Start DMD // Display TEXT SFE
 }
void loop(){
  network.update();
   digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  delay(500);

 String str="";
 char text[32]="";
 //Serial.println();
while(network.available()){
  RF24NetworkHeader header;
//radio.read(&text, sizeof(text));
network.read(header, &text, sizeof(text)); // Read the incoming data
theMessage.concat(text);
printDigit();

Serial.println("theMessage");
Serial.println(theMessage);
}
//box.print(theMessage);
theMessage="";
   }
   void printDigit(){
    dmd.clearScreen();
    Serial.println(theMessage);
    box.print(theMessage);
   }
