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


//Constants
const int LEDPOW = 2;                    // power LED
const int LEDSTAND = 3;                // standby LED
const int LEDREADY =  4;                 // ready LED
const int BUTTONSAVE = 5;                // button to save motor positions
const int BUTTONACTIVE = 6;              // button to start machine, can replace with BT module eventually?
const int SHOOT = 7;                     // motor relay/transistor switch
const int POT = 0;
const int stepPin = 9; 
const int dirPin = 10; 
const int enPin = 11;

// variables will change:
int step = 1;

void setup() {
  // motor
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
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
  int SAVE = digitalRead(BUTTONSAVE);
    if (SAVE == 1 && step == 1){
        int location1 = analogRead(POT);
      digitalWrite(LEDSTAND,HIGH);
      delay(20)
      digitalWrite(LEDSTAND,HIGH);
      delay(20)
      step = 2;
    }
    else {
        step = 1;
    }
    if(SAVE == 1 && step == 2){
        int location2 = analogRead(POT);
      digitalWrite(LEDSTAND,HIGH);
      delay(20);
      digitalWrite(LEDSTAND,HIGH);
      delay(150);
      digitalWrite(LEDREADY,HIGH);
      step = 3;
    }
    else {
        step = 2;
    }
  

  
      // Create function thing to get the difference between the chosen location.  going to depend on number of steps, rotations in the device.  
      
  
