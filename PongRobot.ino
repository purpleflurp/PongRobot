// Code for ping pong robot in game room
// To start machine:
// Turn on power, tell machine to either be stationairy, or to use rotation plate (shown by light activating/turning off light).
// Once the setting is chosen, machine will either go into standby or 


// Machine Functions
// Reload balls -------------------------------------------------------- stepper motor
// Control ball frequency ---------------------------------------------- relay/transistor as switch, blink light each time
// Bluetooth control --------------------------------------------------- BT module
// Signal lights(x4) ------------------------------------------------------- power supply ON/OFF, standby light, ready, active
// Button Controls (x1) ----------------------------------------------------- Save location buttons


//Constants
const int FEED = 2;       // FEED pin
const int RESET = 3;      // RESET pin
const int LEDG =  4;      // green led pin



// variables will change:
int FEEDSTATE = 0;         // variable for reading the FEED button state
int RESETSTATE = 0;        // variable for reading the RESET button state
int FEEDCYCLE;
unsigned long TIMER;
unsigned long PREVFEED;

void setup() {
  // initialize the LED pins as an output:
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(LEDG, OUTPUT);
  pinMode(LEDR, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(FEED, INPUT);
  pinMode(RESET, INPUT);
  servo.attach(SERVOPIN);
  servo.write(STARTPOS);
  Serial.begin(9600);
}

void loop() {
  // keep green light on, write potentiometer to 1-10 scale, set timers and button states.
  digitalWrite(LEDG, HIGH);
    FEEDCYCLE = analogRead(POTPIN);                   // reads the value of the potentiometer (value between 0 and 1023)
    FEEDCYCLE = map(FEEDCYCLE, 0, 1023, 1, 11);       // map value of potentiometer to between 1 and 10
    FEEDSTATE = digitalRead(FEED);
    RESETSTATE = digitalRead(RESET);
    if (FEEDCYCLE >=10){
      FEEDCYCLE = 10;
    }
    TIMER = millis();
    float hours = ((FEEDDELAY/43200000)-((TIMER-PREVFEED)/43200000))*12;
  // Create and Load LCD Interface

  lcd.setCursor(0,0); //Setting the cursor at the start of the LCD
  lcd.print("Next: ");
  lcd.print(hours);
  lcd.print(" hrs.");
  lcd.setCursor(0,1);
  lcd.print(" Servings:   ");
  lcd.print(FEEDCYCLE);
  lcd.print(" ");
  delay(150);
      Serial.println(hours);
      Serial.println(FEEDCYCLE);
      Serial.println(TIMER);
      Serial.println(RESETSTATE);
  

  // Feed Button
      if (FEEDSTATE == HIGH & RESETSTATE == LOW || TIMER - PREVFEED > FEEDDELAY) {
        delay(100);
        PREVFEED = TIMER;
        for (int i = FEEDCYCLE; i > 0; i=i-1){
        servo.write(FEEDPOS);
        delay(2000);
        servo.write(STARTPOS);
        delay(2000);
      }
      }
      else{}
  // Reset Button
      if (RESETSTATE == HIGH & FEEDSTATE == LOW) {
           //blink LEDs twice
               digitalWrite(LEDG, LOW); 
            delay(100);
               digitalWrite(LEDR, HIGH);
               digitalWrite(LEDG, HIGH);
            delay(100);
              digitalWrite(LEDR, LOW);
              digitalWrite(LEDG, LOW);
            delay(100);
              digitalWrite(LEDR, HIGH);
              digitalWrite(LEDG, HIGH);
            delay(100);
              digitalWrite(LEDR, LOW);
              digitalWrite(LEDG, LOW);
            delay(100);
            PREVFEED = TIMER;
            servo.write(STARTPOS);
            FEEDDELAY = 86400000;
  }
  // Double buttons for different feeding time
    if(RESETSTATE == HIGH & FEEDSTATE == HIGH){
        FEEDDELAY = 86400000/2;
      }
}
