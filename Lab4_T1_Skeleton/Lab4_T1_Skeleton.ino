#define IN1        18      // GPIO connected to L298N IN1
#define IN2        19      // GPIO connected to L298N IN2
#define TOUCH_PIN  T6      
#define THRESHOLD  30      

int touch_reading;

void setup() {
  // IN1 and IN2 as output pins
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);  
  pinMode(14, INPUT);   // 14 corresponds to T6 
}

void loop() {
  // Read the touch sensor
  touch_reading = touchRead(TOUCH_PIN); 
  
  /* if TOUCH_PIN is touched, shaft rotates clockwise
     else TOUCH_PIN is not touched, shaft rotates counterclockwise */

  if (touch_reading < THRESHOLD) {
    // Touched → forward (clockwise)
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);  
  } else {
    // Not touched → backward (counterclockwise)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);  
  }
}
