// ****************************************************************
// CARDUINO INTERFACE
// ****************************************************************
// Direction pins
const unsigned char _M1DIR = 7;
const unsigned char _M2DIR = 8;

// Steering Pins
const unsigned char _M1PWM = 9;
const unsigned char _M2PWM = 10;


// helper method to run motor from pin with speed for millis.
void runMotor(int speedPin, int directionPin, int mSpeed, int mDirection){
  analogWrite(speedPin, mSpeed);
  digitalWrite(directionPin, mDirection);
}


void stopMovement(){
  analogWrite(_M1PWM, 0); 
  
}

void stopTurn(){
  analogWrite(_M2PWM, 0); 
}

// Turn the drive wheels forward at speed for time milliseconds.
void accelerateForward(int initial, int final, int aDelay){
    // drive forward
    for (int i = initial; i <= final; i++){
        runMotor(_M1PWM, _M1DIR, i, HIGH); 
        delay(aDelay);
    } 
}

// Turn the drive wheels forward at speed for time milliseconds.
void decellerateForward(int initial, int final, int aDelay){
    // drive forward
    for (int i = initial; i >= final; i--){
        runMotor(_M1PWM, _M1DIR, i, HIGH);     
        delay(aDelay);
    } 
}

// Turn the drive wheels forward at speed for time milliseconds.
void accelerateBackward(int initial, int final, int aDelay){
    // drive forward
    for (int i = initial; i <= final; i++){
        runMotor(_M1PWM, _M1DIR, i, LOW);     
        delay(aDelay);
    } 
}

// Turn the drive wheels forward at speed for time milliseconds.
void decellerateBackward(int initial, int final, int aDelay){
    // drive forward
    for (int i = initial; i >= final; i--){
        runMotor(_M1PWM, _M1DIR, i, LOW);     
        delay(aDelay);
    } 
}




// Turn the drive wheels forward at speed for time milliseconds.
void moveForward(int mSpeed){
    // drive forward
    runMotor(_M1PWM, _M1DIR, mSpeed, HIGH);
}


// Turn the drive wheels backward at speed for time milliseconds.
void moveBackward(int mSpeed){
    // drive reverse
    runMotor(_M1PWM, _M1DIR, mSpeed, LOW);
}


// Rotate the back wheel left at speed for time milliseconds.
void turnLeft(int mSpeed){
    // turn left
    runMotor(_M2PWM, _M2DIR, mSpeed, HIGH);  

}

// Rotate the back wheel right at speed for time milliseconds.
void turnRight(int mSpeed){
    // turn right direction
    runMotor(_M2PWM, _M2DIR, mSpeed, LOW); 
}


// Move the Carduino in a circle.
void moveCircle(int driveSpeed, int mMillis){
  turnLeft(driveSpeed);
  moveForward(driveSpeed);
  delay(mMillis);
  stopMovement();
  stopTurn();
}

// move the Carduino in a box.
void moveBox(int mDelay){
  int mMinSpeed = 20;
  int mSpeed = 120;
  int tSpeed = 150;
  int tDelay = 1250;
  
  // ********************************
  // leg 1
  // ********************************
  
  // turn
  turnRight(tSpeed);
  moveForward(mSpeed);
  delay(tDelay);
  stopTurn();

  // straight movement  
  delay(mDelay);
  
  // turn again
  turnRight(tSpeed);
  delay(tDelay);  
  stopMovement();

 
  // ********************************
  // leg 2
  // ********************************
  
  // turn
  turnLeft(tSpeed);
  moveBackward(mSpeed);
  delay(tDelay);
  stopTurn();

  // straight movement  
  delay(mDelay);
  
  // turn again
  turnLeft(tSpeed);
  delay(tDelay);  
  stopMovement();

  
  // ********************************
  // leg 3
  // ********************************
  
  // turn
  turnRight(tSpeed);
  moveForward(mSpeed);
  delay(tDelay);
  stopTurn();

  // straight movement  
  delay(mDelay);
  
  // turn again
  turnRight(tSpeed);
  delay(tDelay);  
  stopMovement();
   
  // ********************************
  // leg 4
  // ********************************
  
  // turn
  turnLeft(tSpeed);
  moveBackward(mSpeed);
  delay(tDelay);
  stopTurn();

  // straight movement  
  delay(mDelay);
  
  // turn again
  turnLeft(tSpeed);
  delay(tDelay);
  stopMovement();
}

// move the Carduino in a box.
void moveBoxAcceleration(){
  int aDelay = 6;
  int mMinSpeed = 20;
  int mSpeed = 230;
  int tSpeed = 150;
  int tDelay = 1250;
  
  // ********************************
  // leg 1
  // ********************************
  
  // turn
  turnRight(tSpeed);
  accelerateForward(mMinSpeed, mSpeed, aDelay);
  //delay(tDelay);
  //delay(tDelay);  
  decellerateForward(mSpeed, mMinSpeed, aDelay);
  stopMovement();

 
  // ********************************
  // leg 2
  // ********************************
  
  // turn
  turnLeft(tSpeed);
  accelerateBackward(mMinSpeed, mSpeed, aDelay);
  //delay(tDelay);
  //delay(tDelay);  
  decellerateBackward(mSpeed, mMinSpeed, aDelay);
  stopMovement();

  
  // ********************************
  // leg 3
  // ********************************
  
  // turn
  turnRight(tSpeed);
  accelerateForward(mMinSpeed, mSpeed, aDelay);
  //delay(tDelay);
  //delay(tDelay);  
  decellerateForward(mSpeed, mMinSpeed, aDelay);
  stopMovement();
   
  // ********************************
  // leg 4
  // ********************************
  
  // turn
  turnLeft(tSpeed);
  accelerateBackward(mMinSpeed, mSpeed, aDelay);
  //delay(tDelay);
  //delay(tDelay);  
  decellerateBackward(mSpeed, mMinSpeed, aDelay);
  stopMovement();
}


int current = 0;

// test the Carduino move methods.
void test(){
    if(current++ < 3) {     

      moveCircle(150, 12000);
    //moveBox(2000);

    //wait
    delay (1000);
  }

   else {
     delay(100000); 
   }

}

// move forward and backward, quickly (with acceleration)
void amandaSHANK(){
  int MIN = 15;
 int MAX = 255;
 int DELAY = 1;
 accelerateForward(MIN, MAX, DELAY);
 decellerateForward(MAX, MIN, DELAY);
 accelerateBackward(MIN, MAX, DELAY);
 decellerateBackward(MAX, MIN, DELAY);
 delay(500);
 
}

// ****************************************************************
// SETUP, LOOP
// ****************************************************************
// put your setup code here, to run once:
void setup() {
  // TODO: find pin #'s from https://www.pololu.com/product/2511
  // PWM: http://www.arduino.cc/en/Tutorial/PWM
  // analogWrite http://www.arduino.cc/en/Reference/AnalogWrite

  digitalWrite(_M1PWM, LOW);
  pinMode(_M1PWM, OUTPUT);
  digitalWrite(_M1PWM, LOW);
  digitalWrite(_M2PWM, LOW);
  pinMode(_M2PWM, OUTPUT);
  digitalWrite(_M2PWM, LOW);
  digitalWrite(_M1DIR, LOW);
  pinMode(_M1DIR, OUTPUT);
  digitalWrite(_M1DIR, LOW);
  digitalWrite(_M2DIR, LOW);
  pinMode(_M2DIR, OUTPUT);
  digitalWrite(_M2DIR, LOW);

}


// put your main code here, to run repeatedly:
void loop() {
 // test();
 // moveCircle(150, 12000);
 // moveBox(250);
 // amandaSHANK();
 moveBoxAcceleration();
}
