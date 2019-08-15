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
const int LEDSTANDBY = 3;                // standby LED
const int LEDREADY =  4;                 // ready LED
const int BUTTONSAVE = 5;                // button to save motor positions
const int BUTTONACTIVE = 6;              // button to start machine, can replace with BT module eventually?
const int SHOOT = 7;                     // motor relay/transistor switch
const int stepPin = 9; 
const int dirPin = 10; 
const int enPin = 11;

// variables will change:


void setup() {
  // motor
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
  // LEDs
  pinMode(LEDPOW,OUTPUT);
  pinMode(LEDSTANDY,OUTPUT);
  pinMode(LEDREADY,OUTPUT);
  
  // Buttons
  pinMode(BUTTONSAVE, INPUT);
  pinMode(BUTTONACTIVE,INPUT);
  
  

}

void loop() {
  digitalWrite(LEDPOW, HIGH); // keep power light on
  
  
  
  
}
