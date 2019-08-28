// Code for ping pong robot in game room
// To start machine:
// Turn on power, tell machine to either be stationairy, or to use rotation plate (shown by light activating/turning off light).
// Once the setting is chosen, machine will either go into standby or 


// Machine Functions
// Reload balls -------------------------------------------------------- stepper motor
// Control ball frequency ---------------------------------------------- relay/transistor as switch, blink light each time
// Bluetooth control --------------------------------------------------- BT module
// Signal lights(x3) ------------------------------------------------------- power supply ON/OFF, standby light, ready, active
// Button Controls (x2) ----------------------------------------------------- Save location button, activation button
// rotary encoder

//Constants
const int LEDPOW = 2;                    // power LED
const int LEDSTAND = 3;                // standby LED
const int LEDREADY =  4;                 // ready LED
const int BUTTONSAVE = 5;                // button to save motor positions
const int BUTTONACTIVE = 6;              // button to start machine, can replace with BT module eventually?
const int SHOOT = 7;                     // motor relay/transistor switch
const int ROT = 0;
const int stepPin = 9; 
const int dirPin = 10; 
const int enPin = 11;

// variables will change:
int step = 1;
int SAVE;
int ACTIVE;

void setup() {
  // motor
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  // need to add output for relay.
  
  // LEDs
  pinMode(LEDPOW,OUTPUT);
  pinMode(LEDSTAND,OUTPUT);
  pinMode(LEDREADY,OUTPUT);
  
  // Buttons
  pinMode(BUTTONSAVE, INPUT);
  pinMode(BUTTONACTIVE,INPUT);
}

void loop() {
  digitalWrite(LEDPOW, HIGH); // keep power light on
  SAVE = digitalRead(BUTTONSAVE);
  ACTIVE = digitalRead(BUTTONACTIVE)
  //Create potentiometer control of the rotational plate
      potVal = map(analogRead(A0),0,1024,0,500);
      Pval = potVal;
  
  // create different steps of startup
}
    if (SAVE == 1 && step == 1){
        int location1 = analogRead(POT);
      digitalWrite(LEDSTAND,HIGH);
      delay(20)
      digitalWrite(LEDSTAND,HIGH);
      delay(20)
      step = 2;
    }
    if(SAVE == 1 && step == 2){
        int location2 = analogRead(POT);
      digitalWrite(LEDSTAND,HIGH);
      delay(20);
      digitalWrite(LEDSTAND,HIGH);
      delay(150);
      step = 3;
    }
    if(step == 3){
      digitalWrite(LEDREADY,HIGH);
      digitalWrite(LEDSTAND,HIGH);
    }
  if (ACTIVE == 1 && step == 3){
    digitalWrite(LEDREADY,HIGH);
    digitalWrite(LEDSTAND,HIGH);
    delay(150)
    step = 4
    // output for shooter motor
    
  }
  while(step == 4){
    int RANGE = location2 - location1;
  }
  
      // Create function thing to get the difference between the chosen location.  going to depend on number of steps, rotations in the device.  
      
  
///// basic stepper motor program
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  
