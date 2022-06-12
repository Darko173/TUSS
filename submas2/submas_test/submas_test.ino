#include <SPI.h>
#include <nRF24L01.h>
#include <RF24Network.h>
#include <RF24.h>
 
RF24 radio(2,A0); // CE, CSN
RF24Network network(radio); 
const uint16_t this_node = 02;
const uint16_t node013 = 012;
const uint16_t node014 = 022;
const uint16_t node019 = 032;
const uint16_t node020 = 042;
const uint16_t node021 = 052;
const uint16_t node00 = 00;
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

   if(ReValue.length()>5){
    ReValue="";
    theMessage="";
      resetFunc();  

    
  }
   else if(ReValue.substring(0,3) == "#13"){
      
    RF24NetworkHeader header(node013);
   
   while(ReValue.length()==5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==2){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
     network.write(header, &temp, sizeof(temp)); 
     Serial.println(temp);
     
    }
    }
    ReValue="";
    SeValue="";
   
   }
   
    }
    else if(ReValue.substring(0,3) == "#14"){
      
    RF24NetworkHeader header(node014);
   
   while(ReValue.length()==5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==2){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
     network.write(header, &temp, sizeof(temp)); 
     Serial.println(temp);
     
    }
    }
    ReValue="";
    SeValue="";
   
   }
   
    }
    else if(ReValue.substring(0,3) == "#19"){
      
    RF24NetworkHeader header(node019);
   
   while(ReValue.length()==5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==2){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
     network.write(header, &temp, sizeof(temp)); 
     Serial.println(temp);
     
    }
    }
    ReValue="";
    SeValue="";
   
   }
   
    }
   else if(ReValue.substring(0,3) == "#20"){
      
    RF24NetworkHeader header(node020);
   
   while(ReValue.length()==5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==2){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
     network.write(header, &temp, sizeof(temp)); 
     Serial.println(temp);
     
    }
    }
    ReValue="";
    SeValue="";
   
   }
   
    }
  else  if(ReValue.substring(0,3) == "#21"){
      
    RF24NetworkHeader header(node021);
   
   while(ReValue.length()==5){
     String SeValue= ReValue.substring(3); 
    Serial.println("SeValue");
    Serial.println(SeValue);
    if(SeValue.length()==2){
     for(int i=0;i<SeValue.length();i++){
     char temp = SeValue[i];
     Serial.println("temp");
     network.write(header, &temp, sizeof(temp)); 
     Serial.println(temp);
     
    }
    }
    ReValue="";
    SeValue="";
   
   }
   
    }
   
}
