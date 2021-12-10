const int pingPin = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
const int outputpin=9;
float sampleArray[6] = {};     //array to store 6 samples of temperature signals
int sampleCounter = 0;        //array pointer
int judge = 0; 
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(8, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = 24-microsecondsToInches(duration);
   cm = 70-microsecondsToCentimeters(duration);

    sampleArray[sampleCounter]=inches;
    sampleCounter++;

    Serial.print(inches);
    Serial.print(" ");
    if (sampleCounter==6){
      for (int i=0;i<6;i++){
        if (sampleArray[i]<2)
           judge=1;
        }
        
    Serial.print("\n");
    Serial.print(judge);
    if (judge==0){
      
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
      delay(100000);}
    Serial.print("\n");
    sampleCounter=0;
    sampleArray[0]=0;
    sampleArray[1]=0;
    sampleArray[2]=0;
    sampleArray[3]=0;
    sampleArray[4]=0;
    sampleArray[5]=0;
    judge=0;
    
    }
    //}
   
   
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(8, LOW);
   delay(3000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
