// values:
// minimum: 0
// maximum: 1023
int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int maxval = 1023;
float percent;
int output_pwm;
const int transistorPin = 9;

void setup() {
   pinMode(transistorPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("init.");
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  percent = 100*((float)val / (float)maxval);
  output_pwm = ((percent / 100)*255);
  Serial.println(val);
  Serial.print(percent);
  Serial.println("%");
  Serial.println(output_pwm);
  
  analogWrite(transistorPin, output_pwm);
  delay(10);                  // stop the program for some time
}
