#include <SPI.h>
#include <nRF24L01.h>
#include <RF24Network.h>
#include <RF24.h>
String Incoming_value ;  
RF24 radio(7, 8); // CE, CSN
RF24Network network(radio); 
//const byte address[6] = "00001";
const uint16_t this_node = 00; 
const uint16_t node01 = 01;
const uint16_t node02 = 02;
void setup() {
  Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
  SPI.begin();
  radio.begin();
 // radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
   network.begin(90, this_node); //(channel, node address)
 // radio.stopListening();

}
void loop() {
  network.update();
   while(Serial.available() == 0)  
  {
    }
     Incoming_value = Serial.readString();
     
    if((Incoming_value.substring(0,3) == "#11")||(Incoming_value.substring(0,3) == "#12")||(Incoming_value.substring(0,3) == "#17")
    ||(Incoming_value.substring(0,3) == "#18")
    ){
    RF24NetworkHeader header(node01);
    
  for(int i=0;i<=Incoming_value.length();i++){
   char temp = Incoming_value[i];
     network.write(header, &temp, sizeof(temp));
   }
   
  Serial.println(Incoming_value.length());
  Serial.println(Incoming_value);
  
 }

 else 
       if((Incoming_value.substring(0,3) == "#21")||(Incoming_value.substring(0,3) == "#13")|| (Incoming_value.substring(0,3) == "#19")||(Incoming_value.substring(0,3) == "#14") ||(Incoming_value.substring(0,3) == "#20")){
    RF24NetworkHeader header(node02);
    
  for(int i=0;i<=Incoming_value.length();i++){
   char temp = Incoming_value[i];
     network.write(header, &temp, sizeof(temp));
   }
   
  Serial.println(Incoming_value.length());
  Serial.println(Incoming_value);
 
 }
 
}
