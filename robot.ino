#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

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
   
}

void loop() {
  //digitalWrite(enA, HIGH);
    //digitalWrite(enB, HIGH);
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
    
delay(1000);
}
