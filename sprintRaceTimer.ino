//
//PINS: TrigPin on 9, EchoPin on 10, Buzzer on 13, starting button is on 7.
//
//
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 13;
const int startButton = 7;
unsigned int initMilli;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output | trigPin: Pin that emits the beam of 40 khz sound
pinMode(echoPin, INPUT); // Sets the echoPin as an Input | echoPin: Pin that recieves the beam 
pinMode(buzzer, OUTPUT); //Sets buzzer as output
pinMode(startButton, OUTPUT); // Sets starting button as an ouput

while(!checkStart()){
  checkStart();
  }

Serial.begin(9600); // Starts the serial communication
int initMilli = millis();
}

void loop() {
  
unsigned int prevdistance;
unsigned static const int threshold = 30;
unsigned int distanceInCm;


distanceInCm = measureDistance();

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distanceInCm);

distanceInCm = prevdistance;

if(prevdistance - distanceInCm > threshold){
  tone(buzzer, 261);
  delay(1000);
  Serial.println("TIME RECORDED IN SECONDS: ");
  Serial.print((millis() - initMilli)/1000 );
  }
  
}


int measureDistance(){
  // defines variables - duration of 
long duration; //Used to measure how long the beam takes to come back
int distance; //Distance the object is

  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance (in cm)
distance= duration*0.034/2;

return distance;
  }

 bool checkStart(){
  bool isStarted = digitalRead(startButton);
    return isStarted;
    }
