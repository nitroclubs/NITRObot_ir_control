/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define LEFT_FOR 9 // PWMB
#define LEFT_BACK 5  // DIRB  ---  left
#define RIGHT_FOR 6  // PWMA
#define RIGHT_BACK 10  // DIRA  ---  right

int Speed =255;


int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
     
  pinMode(LEFT_FOR, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
  pinMode(RIGHT_FOR, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  // stopMoving(); 
} 
void loop() {
 
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

 
if(results.value == 16712445)  {
  Serial.println("moveForward");
  moveForward();
}
//else stopMoving();
  
if(results.value == 16748655)  {
  Serial.println("turnRight");
  turnRight();
}

else if(results.value == 16769055)  {
  Serial.println("turnLeft");
  turnLeft();
}

 if(results.value == 16750695)  {
  Serial.println("moveBackward");
  moveBackward();
 }

  if(results.value == 16754775)  {
  Serial.println("stopMoving");
  stopMoving();
 }



    
    irrecv.resume(); // Receive the next value
  }  
  delay(10);   
}


//------------------------------------------------------------

void moveForward() // Move forward
{
  analogWrite(LEFT_FOR,  Speed);
  analogWrite(LEFT_BACK, LOW);
  analogWrite(RIGHT_FOR,  Speed);
  analogWrite(RIGHT_BACK, LOW);
}

void moveBackward() // Move backward
{
  analogWrite(LEFT_FOR, LOW);
  analogWrite(LEFT_BACK, Speed);
  analogWrite(RIGHT_FOR, LOW);
  analogWrite(RIGHT_BACK,  Speed);
}

void turnLeft() // Turn Left
{
  analogWrite(LEFT_FOR, LOW);
  analogWrite(LEFT_BACK,  Speed);
  analogWrite(RIGHT_FOR,  Speed);
  analogWrite(RIGHT_BACK, LOW);
}

void turnRight() // Turn Right
{
  analogWrite(LEFT_FOR,  Speed);
  analogWrite(LEFT_BACK, LOW);
  analogWrite(RIGHT_FOR, LOW);
  analogWrite(RIGHT_BACK,  Speed);
}

/*void stopMoving() // Stop movement
{
  analogWrite(LEFT_FOR, HIGH);
  analogWrite(LEFT_BACK, HIGH);
  analogWrite(RIGHT_FOR, HIGH);
  analogWrite(RIGHT_BACK, HIGH);
}
*/

void stopMoving() // Stop movement
{
  analogWrite(LEFT_FOR,  0);
  analogWrite(LEFT_BACK, LOW);
  analogWrite(RIGHT_FOR,  0);
  analogWrite(RIGHT_BACK, LOW);
}
