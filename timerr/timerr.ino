
#include <DMD2.h>
#include <fonts/Arial14.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24Network.h>
#include <RF24.h>
RF24 radio(2,A0); // CE, CSN
#include <DMD2.h>
#include <fonts/Arial14.h>
#include <SPI.h>

String theMessage="00";
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 052;

unsigned long startTime = 0;
int counter=0, secs =2;//,centisec=0;hrs = 0, mins

SoftDMD dmd(1,1);  // DMD controls the entire display
DMD_TextBox box(dmd);  // "box" provides a text box to automatically write to/scroll the display

// the setup routine runs once when you press reset:
void setup() {
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
  radio.begin();
 // radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
 // radio.startListening();
 network.begin(90, this_node);  //(channel, node address)
  dmd.setBrightness(255);
  dmd.selectFont(Arial14);
  dmd.begin();
  dmd.clearScreen( );
   dmd.fillScreen(true);
}

// the loop routine runs over and over again forever:
void loop() {
  network.update();
   digitalWrite(A0,HIGH);
  delay(500);
  digitalWrite(A0,LOW);
  delay(500);
  dmd.clearScreen(  );

 char text;
 //Serial.println();
while(network.available()){
  secs=0;
  RF24NetworkHeader header;
//radio.read(&text, sizeof(text));
network.read(header, &text, sizeof(text));// Read the incoming data
theMessage.concat(text);
counter = theMessage.toInt();
}


Serial.println(counter);
theMessage="";
if(counter<=99 && counter >=0)

displayCounter();

}

void cleardigit(int pos) {
  dmd.drawFilledBox(pos, 0, pos + 9, 15, GRAPHICS_OFF);
}

void displayCounter() {
  
  Serial.println(counter);
  if (millis() - startTime > 1000) {
    startTime = millis();  
      
    dmd.clearScreen();
    
    if (counter>=0) {
     /* if (secs == 0) {
        dmd.clearScreen();
      }      else {*/
      
    
        dmd.drawString(1, 1, String(counter/10));
         dmd.drawString(8, 1, String(counter%10));
      
        dmd.drawString(15, 1, ":");
         dmd.drawString(17, 1, String(secs/10));
         dmd.drawString(25,1,String(secs%10));
    }
         else { 
      dmd.drawString(15, 1, ":");
      
      if (secs < 10) {
        dmd.drawString(17, 1, "0");
        cleardigit(25);
        dmd.drawString(25, 1, String(secs));
      } else {
        if (secs % 10 == 9) {
         cleardigit(17);// dmd.drawFilledBox(72, 0, 81, 15, GRAPHICS_OFF);//
          dmd.drawString(17, 1, String(secs / 10)); //clearing 18
      if (counter < 10) {
        dmd.drawString(0, 1, "0");
        cleardigit(8);
        dmd.drawString(8, 1, String(counter));
      }
        else {
        if (counter % 10 == 9) {
          cleardigit(1);//dmd.drawFilledBox(40, 0, 49, 15, GRAPHICS_OFF);//
          dmd.drawString(1, 1, String(counter / 10));
        }
        cleardigit(8);
        dmd.drawString(8,1, String(counter%10));
        }
        }
        cleardigit(25);
        
          dmd.drawString(25, 1 , String(secs%10));
        }
          
        }
         secs--;
    if (secs < 0) {
      counter--;
      secs = 59;
    }
    if(counter<0 && secs==0){
dmd.fillScreen(true);
      
    }
  }
}
