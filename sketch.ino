// values:
// minimum: 0
// maximum: 1023
int potPinR = 3;
int potPinG = 4;
int potPinB = 5;

int transPinR = 11;
int transPinG = 10;
int transPinB = 9;
int valR = 0;
int valG = 0;
int valB = 0;
int maxvalR = 1023;
int maxvalG = 1023;
int maxvalB = 1023;

float percentR;
float percentG;
float percentB;

int output_pwmR;
int output_pwmG;
int output_pwmB;

void setup() {
   pinMode(transPinR, OUTPUT);
   pinMode(transPinG, OUTPUT);
   pinMode(transPinB, OUTPUT);

   

  Serial.begin(9600);
  Serial.println("init.");
}

void loop() {

  Serial.write(27);   //Print "esc"
  Serial.write("[2J");
  
  valR = analogRead(potPinR);    // read the value from the sensor
  percentR = 100*((float)valR / (float)maxvalR);
  output_pwmR = ((percentR / 100)*255);
  Serial.print("Red: ");
  Serial.print(percentR);
  Serial.println("%");  
  analogWrite(transPinR, output_pwmR);
  
  valG = analogRead(potPinG);    // read the value from the sensor
  percentG = 100*((float)valG / (float)maxvalG);
  output_pwmG = ((percentG / 100)*255);
  Serial.print("Green: ");
  Serial.print(percentG);
  Serial.println("%");  
  analogWrite(transPinG, output_pwmG);
  
  valB = analogRead(potPinB);    // read the value from the sensor
  percentB = 100*((float)valB / (float)maxvalB);
  output_pwmB = ((percentB / 100)*255);
  Serial.print("Blue: ");
  Serial.print(percentB);
  Serial.println("%");  
  analogWrite(transPinB, output_pwmB);
  
  delay(10);                  // stop the program for some time
}
