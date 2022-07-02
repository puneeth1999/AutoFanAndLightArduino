const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int relay1 = 2;
const int relay2 = 8;
long startTime = millis();
int timer=0;
bool state=0;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(relay1, OUTPUT);
   pinMode(relay2, OUTPUT);
}

void loop() {
   Serial.println(millis() - startTime);
   if((millis()- startTime) <= 43200000){ // replace this with 43200000 => 12 hrs
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(relay2, LOW);
   }
   else if((millis()- startTime) <= 86400000){ // 86400000
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relay2, HIGH);
   }
   else{
    startTime = millis();
    //digitalWrite(LED_BUILTIN, LOW);
   }
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if(cm < 70){
    //digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(relay1, LOW);
    Serial.println("Trigger active");
    
    delay(25000);
    Serial.println("Trigger INacitve");
   }
   else{
    //digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relay1, HIGH);
   }
   delay(400);

}


 
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
