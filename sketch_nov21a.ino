#include <Gamepad.h>

Gamepad gp;

#define SENSOR_PIN A0  // Arduino pin connected to sound sensor's pin
#define CLK 3
#define DT 4
#define SW 2
#define B1 A2

// #define ORG/yellow 7
// #define BLUE/org 7
// #define RED 9
// #define YELLOW 6

int dirDown = 6;
int dirUp = 7;
int dirRight = 9;
int dirLeft = 8;

int counter = 0;
unsigned long lastButtonPress = 0;
unsigned long lastBreakPress = 0;
unsigned long lastBtnOnePress = 0;

int sensorValue; 
int gear = 0;

int lever = 0;
int plever = 0;
unsigned long last_run=0;


void setup() {
  pinMode(CLK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK), shaft_moved, LOW);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(dirDown, INPUT_PULLUP);
  pinMode(dirRight, INPUT_PULLUP);
  pinMode(dirLeft, INPUT_PULLUP);
  pinMode(dirUp, INPUT_PULLUP);

}

void shaft_moved(){
  if(millis()-last_run>5){
    if(digitalRead(DT)==1){
      counter++;
    }
    if(digitalRead(DT)==0){
      counter--;
    }
    if(counter<65 && counter>-65){
        gp.setLeftXaxis(counter*1.95);
    }
    last_run=millis();
  }
}

void loop() {
  sensorValue = analogRead(SENSOR_PIN);  // read new sensor value
  // Serial.println(sensorValue);
  if (sensorValue > 70) { 
    // control microphone arccoding to the toggled state
    gp.setLeftYaxis(-130);
    lastBreakPress = millis();
  }
  else if(millis()-lastBreakPress > 1000){
    // Relase the brake
    gp.setLeftYaxis(130);
  }
  if( digitalRead( dirRight ) == LOW && gear == -2 ){
    // Serial.println("Gear Neutral");
    lever = 0;
  }
  else if( digitalRead( dirUp ) == LOW && gear == -2 ){
    // Serial.println("Gear 1st");
    lever = 1;
  }
  else if( digitalRead( dirDown ) == LOW && gear == -2 ){
    // Serial.println("Gear 2nd");
    lever = 2;
  }
  else if( digitalRead( dirUp ) == LOW && gear == 2 ){
    // Serial.println("Gear 5th");
    lever = 5;
  }
  else if( digitalRead( dirDown ) == LOW && gear == 2 ){
    // Serial.println("Gear Reverse");
    lever = 6;
  }
  else if( digitalRead( dirDown ) == LOW && gear != -1 ){
    gear = -1;
    // Serial.println("Direction: DOWN");
    // Serial.println("Gear 4th");
    lever = 4;
  }
  else if( digitalRead( dirUp ) == LOW && gear != 1 ){
    gear = 1;
    // Serial.println("Direction: UP");
    // Serial.println("Gear 3rd");
    lever = 3;
  }
  else if( digitalRead( dirLeft ) == LOW && gear != -2 ){
    gear = -2;
    // Serial.println("Direction: LEFT");
  }
  else if( digitalRead( dirRight ) == LOW && gear != 2 ){
    gear = 2;
    // Serial.println("Direction: RIGHT");
  }
  else{
    gear = 0;
  }

  if(plever != lever){
    gp.setButtonState(plever+2, false);
    gp.setButtonState(lever+2, true);
    // Serial.println(lever);
    plever = lever;
  }


	int btnState = digitalRead(SW);

	//If we detect LOW signal, button is pressed
	if (btnState == LOW) {
		//if 50ms have passed since last LOW pulse, it means that the
		//button has been pressed, released and pressed again
		if (millis() - lastButtonPress > 50) {
      counter = 0;
		}

		// Remember last button press event
		lastButtonPress = millis();
	}

  int btnOne = analogRead(B1);
  if(btnOne == 0){
    gp.setRightXaxis(-130);
    // gp.setRightYaxis(125);
  }else{
    gp.setRightXaxis(130);
    // gp.setRightYaxis(-125);
  }

	// Put in a slight delay to help debounce the reading
	delay(2);

}