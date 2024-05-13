// Initializing libraries
#include "HCPCA9685.h"

// I2C slave address
#define I2CAdd 0x40
 
// Create instance of library
HCPCA9685 HCPCA9685(I2CAdd);

//-------------------------Button Variables-------------------------
const int homeButton = 3;
const int randButton = 4;
const int lampButton = 5; 
const int lampOutput = 6; 
byte homeButtonState;
byte randButtonState;
byte lampButtonState;

//--------------------Homing Variables--------------------
float pos0 = 310;
float pos1 = 370;
float pos2 = 430;
float pos3 = 180;
float pos4 = 0;
float pos5 = 430;

float posSmooth0;
float posSmooth1;
float posSmooth2;
float posSmooth3;
float posSmooth4;
float posSmooth5;

float posPrev0;
float posPrev1;
float posPrev2;
float posPrev3;
float posPrev4;
float posPrev5;

//--------------------Random Position Variables--------------------
byte ranCheck;

float ranPos0;
float ranPos1;
float ranPos2;
float ranPos3;
float ranPos4;
float ranPos5;

float ranPosSmooth0;
float ranPosSmooth1;
float ranPosSmooth2;
float ranPosSmooth3;
float ranPosSmooth4;
float ranPosSmooth5;

float ranPosPrev0;
float ranPosPrev1;
float ranPosPrev2;
float ranPosPrev3;
float ranPosPrev4;
float ranPosPrev5;

//--------------------Lamp Position Variables--------------------
byte lampCheck;

float lampPos0 = 320;
float lampPos1 = 230;
float lampPos2 = 300;
float lampPos3 = 200;
float lampPos4 = 40;
float lampPos5 = 0;

float lampPosSmooth0;
float lampPosSmooth1;
float lampPosSmooth2;
float lampPosSmooth3;
float lampPosSmooth4;
float lampPosSmooth5;

float lampPosPrev0;
float lampPosPrev1;
float lampPosPrev2;
float lampPosPrev3;
float lampPosPrev4;
float lampPosPrev5;

//-------------------------Setup-------------------------
void setup() {
  Serial.begin(9600);
  
  pinMode(homeButton, INPUT);
  pinMode(randButton, INPUT);
  pinMode(lampButton, INPUT);
  pinMode(lampOutput, OUTPUT);

  digitalWrite(lampOutput, LOW);  
  
  HCPCA9685.Init(SERVO_MODE);
  HCPCA9685.Sleep(false);
  
  randomSeed(analogRead(0));

  ranPos0 = random(430);
  ranPos1 = random(370, 430);
  ranPos2 = random(100, 430);
  ranPos3 = random(200);
  ranPos4 = random(430);
  ranPos5 = 0;

  Serial.println("Welcome to Monday's Brain, Gilbert");
  Serial.println(" ");
  Serial.println("button1 ---> home");
  Serial.println("button2 ---> random position");
  Serial.println("button3 ---> lamp position");

}

//-------------------------Main Loop-------------------------
void loop() {
  homeButtonState = digitalRead(homeButton);
  randButtonState = digitalRead(randButton);
  lampButtonState = digitalRead(lampButton);

  
  if (homeButtonState == HIGH) {
    homing();
  }
  if (randButtonState == HIGH) {
    random_position();
  }
  if (lampButtonState == HIGH) {
    lamp_position();
  }
}
