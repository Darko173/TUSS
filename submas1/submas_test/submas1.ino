#include <SPI.h>
#include <nRF24L01.h>
#include <RF24Network.h>
#include <RF24.h>
 
RF24 radio(2,A0); // CE, CSN
RF24Network network(radio); 
const uint16_t this_node = 01;
const uint16_t node00 = 00;
const uint16_t node011 = 011;
const uint16_t node012 = 021;
const uint16_t node017 = 031;
const uint16_t node018 = 041;
//const uint16_t node022 = 08;
//const uint16_t node023 = 09;
String theMessage="";
String ReValue;
void setup() {
  Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
  SPI.begin();
  radio.begin();
 // radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
   network.begin(90, this_node); //(channel, node address)

}
void loop() {
  network.update();
  char Incoming_value[32]="";
  
  //receive
   while(network.available())  {
    RF24NetworkHeader header;
  network.read(header, &Incoming_value, sizeof(Incoming_value));
  theMessage.concat(Incoming_value);
  ReValue.concat(theMessage);
   sendData();
}
   
  theMessage=""; 
  
}
void(* resetFunc) (void) = 0; //declare reset function @ address 0

void sendData(){
  Serial.println("ReValue");
  Serial.println(ReValue);

  if(ReValue.length()>6){
    ReValue="";
    theMessage="";
      resetFunc();  

    
  }
  
  if(ReValue.substring(0,3) == "#11"){
    RF24NetworkHeader header(node011);
    if(ReValue.length()==6){
      
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==3){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
    Serial.println(temp);
     network.write(header, &temp, sizeof(temp)); 
     ReValue="";
     
    }
    }
    SeValue="";
   
   }
   
    }
    
   else if(ReValue.substring(0,3) == "#12"){
    RF24NetworkHeader header(node012);
    while(ReValue.length()>5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==3){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
    Serial.println(temp);
     network.write(header, &temp, sizeof(temp)); 
     ReValue="";
    }
    }
    SeValue="";
   
   }
   
    }
    else if(ReValue.substring(0,3) == "#17"){
    RF24NetworkHeader header(node017);
    while(ReValue.length()>5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==3){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
    Serial.println(temp);
     network.write(header, &temp, sizeof(temp)); 
     ReValue="";
    }
    }
    SeValue="";
   
   }
   
    }
    else if(ReValue.substring(0,3) == "#18"){
    RF24NetworkHeader header(node018);
    while(ReValue.length()>5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==3){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
    Serial.println(temp);
     network.write(header, &temp, sizeof(temp)); 
     ReValue="";
    }
    }
    SeValue="";
   
   }
   
    }
   
}
