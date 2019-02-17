#include<SPI.h>
#include<RF24.h>
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

// ce, csn pins
RF24 radio(0, 13)
 
void setup() {
 pinMode(enA, OUTPUT);
 pinMode(enB, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 Serial.begin(9600);
 Serial.print("hi");
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 while (!Serial);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  const uint64_t pipe = 0xE8E8F0F0E1LL;
  radio.openReadingPipe(1, pipe);
  radio.enableDynamicPayloads();
  radio.powerUp();
}

void loop() {
  //digitalWrite(enA, HIGH);
  //digitalWrite(enB, HIGH);
 radio.startListening() ;
  Serial.println("Starting loop. Radio on.") ;
  char receivedMessage[32] = {0} ;
  if (radio.available()){
    radio.read(receivedMessage, sizeof(receivedMessage));
    Serial.println(receivedMessage + '0') ;
    Serial.println("Turning off the radio.") ;
    radio.stopListening() ;
   Serial.print("driving?");

  digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    
   // digitalWrite(in1, HIGH);
   // digitalWrite(in2, LOW);
    // Set Motor B backward
   // digitalWrite(in3, HIGH);
    //digitalWrite(in4, LOW);
  }  
delay(1000);
}
