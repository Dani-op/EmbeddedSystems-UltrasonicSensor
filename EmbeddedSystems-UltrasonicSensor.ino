//https://www.eccircuit.com/2018/01/arduino-code-for-2-way-traffic-light.html
//https://www.youtube.com/watch?v=C8llntDR3fA
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPinGreen = 13;
const int ledPinYellow = 22;
const int ledPinRed = 6; 

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPinGreen, OUTPUT);
pinMode(ledPinYellow, OUTPUT);
pinMode(ledPinRed, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2; //converting distance from points to integers ref:stackoverflow

safetyDistance = distance;
if (safetyDistance <= 7){
  digitalWrite(buzzer, HIGH);
  delay(700);
  digitalWrite(buzzer, LOW);
   digitalWrite(ledPinYellow, LOW);
  digitalWrite(ledPinRed, LOW);
  delay(550);
  digitalWrite(ledPinGreen, HIGH);

}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPinGreen, LOW);
  delay(500);
  digitalWrite(ledPinYellow, HIGH);
  delay(500);
  digitalWrite(ledPinYellow, LOW);  
  digitalWrite(ledPinRed, HIGH);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
