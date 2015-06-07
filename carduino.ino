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
void runMotor(int speedPin, int directionPin, int mSpeed, int mDirection, int mMillis){
  analogWrite(speedPin, mSpeed);
  digitalWrite(directionPin, mDirection);
  //delay(mMillis);
  //analogWrite(speedPin, 0);
}


void stopMovement(){
  analogWrite(_M1PWM, 0); 
  
}

void stopTurn(){
  analogWrite(_M2PWM, 0); 
}


// Turn the drive wheels forward at speed for time milliseconds.
void moveForward(int mSpeed, int mMillis){
    // drive forward
    runMotor(_M1PWM, _M1DIR, mSpeed, LOW, mMillis);
}


// Turn the drive wheels backward at speed for time milliseconds.
void moveBackward(int mSpeed, int mMillis){
    // drive reverse
    runMotor(_M1PWM, _M1DIR, mSpeed, HIGH, mMillis);
}


// Rotate the back wheel left at speed for time milliseconds.
void turnLeft(int mSpeed, int mMillis){
    // turn left
    runMotor(_M2PWM, _M2DIR, mSpeed, HIGH, mMillis);  

}

// Rotate the back wheel right at speed for time milliseconds.
void turnRight(int mSpeed, int mMillis){
    // turn right direction
    runMotor(_M2PWM, _M2DIR, mSpeed, LOW, mMillis); 
}


// Move the Carduino in a circle.
void moveCircle(int driveSpeed, int mMillis){
  turnLeft(150, 1000);
  moveForward(driveSpeed, 1000);
  delay(mMillis);
  stopMovement();
  stopTurn();
}

/*
// move the Carduino in a box.
void moveBox(int iterations){
	printf("\nmoveBox(%i);\n", iterations);	
	printf("move in a box pattern %i times\n", iterations);	

	// TODO not implemented
	printf("TODO not implemented\n");	
	delay(1000);
}

// move the Carduino randomly.
void moveRandom(){
	printf("\nmoveRandom();\n");	
	printf("move in some randomly determined pattern.\n");	
	
	// TODO not implemented
	printf("TODO not implemented\n");
	delay(1000);
			
}
*/

// test the Carduino move methods.
void test(){
  /*
	printf("\ntest();\n");	
	moveForward(150, 2000);
	//moveBackward(255, 1000);
	//turnLeft(15, 60);
	//turnRight(22, 777);
	delay(1000);
*/
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

int current = 0;

// put your main code here, to run repeatedly:
void loop() {
  // run five times
  if(current++ < 3) {
    
    /*
    // drive forward
    runMotor(_M1PWM, _M1DIR, 100, LOW, 1000);
    
    // drive reverse
    runMotor(_M1PWM, _M1DIR, 100, HIGH, 1000);
    
    // turn right direction
    runMotor(_M2PWM, _M2DIR, 150, LOW, 1000); 

    // turn left
    runMotor(_M2PWM, _M2DIR, 150, HIGH, 1000);  
    */
    
    // TODO: add new code  
    /*   
    moveForward(100, 1000);
    turnLeft(150, 1000);
    delay(1000);
    stopMovement();
    stopTurn();
    */
    
    moveCircle(120, 12000);
    
    //moveBackward(100, 1000);
    //turnRight(150, 1000);
    
    //wait
    delay (1000);
  }

   else {
     delay(100000); 
   }
}






