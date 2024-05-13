//-------------------------Random Position Function-------------------------
void random_position() {
  bool moving = true;

  bool serv0 = true;
  bool serv1 = true;
  bool serv2 = true;
  bool serv3 = true;
  bool serv4 = true;
  bool serv5 = true;

  ranCheck = 1;
    
  while (moving = true) {
    if (ranPos0 > pos0 && serv0 == true) {  //-----------------------------------smoothing for servo0
      ranPosSmooth0 = pos0 + ((ranPos0 - pos0) * 0.025) + (ranPosPrev0 * 0.975);
      //Serial.println(ranPosSmooth0);
      ranPosPrev0 = ((ranPos0 - pos0) * 0.025) + (ranPosPrev0 * 0.975);
      if (ranPosSmooth0 == ranPos0) {
        serv0 = false;
      }
    }
    if (ranPos0 < pos0 && serv0 == true) {
      ranPosSmooth0 = pos0 - (((pos0 - ranPos0) * 0.025) + (ranPosPrev0 * 0.975));
      //Serial.println(ranPosSmooth0);
      ranPosPrev0 = (((pos0 - ranPos0) * 0.025) + (ranPosPrev0 * 0.975));
      if (ranPosSmooth0 == ranPos0) {
        serv0 = false;
      }
    }
    if (ranPos1 > pos1 && serv1 == true) {  //-----------------------------------smoothing for servo1
      ranPosSmooth1 = pos1 + ((ranPos1 - pos1) * 0.025) + (ranPosPrev1 * 0.975);
      //Serial.println(ranPosSmooth1);
      ranPosPrev1 = ((ranPos1 - pos1) * 0.025) + (ranPosPrev1 * 0.975);
      if (ranPosSmooth1 == ranPos1) {
        serv1 = false;
      }
    }
    if (ranPos1 < pos1 && serv1 == true) {
      ranPosSmooth1 = pos1 - (((pos1 - ranPos1) * 0.025) + (ranPosPrev1 * 0.975));
      //Serial.println(ranPosSmooth1);
      ranPosPrev1 = (((pos1 - ranPos1) * 0.025) + (ranPosPrev1 * 0.975));
      if (ranPosSmooth1 == ranPos1) {
        serv1 = false;
      }
    }
    if (ranPos2 > pos2 && serv2 == true) {  //-----------------------------------smoothing for servo2
      ranPosSmooth2 = pos2 + ((ranPos2 - pos2) * 0.025) + (ranPosPrev2 * 0.975);
      //Serial.println(ranPosSmooth2);
      ranPosPrev2 = ((ranPos2 - pos2) * 0.025) + (ranPosPrev2 * 0.975);
      if (ranPosSmooth2 == ranPos2) {
        serv2 = false;
      }
    }
    if (ranPos2 < pos2 && serv2 == true) {
      ranPosSmooth2 = pos2 - (((pos2 - ranPos2) * 0.025) + (ranPosPrev2 * 0.975));
      //Serial.println(ranPosSmooth2);
      ranPosPrev2 = (((pos2 - ranPos2) * 0.025) + (ranPosPrev2 * 0.975));
      if (ranPosSmooth2 == ranPos2) {
        serv2 = false;
      }
    }
    if (ranPos3 > pos3 && serv3 == true) {  //-----------------------------------smoothing for servo3
      ranPosSmooth3 = pos3 + ((ranPos3 - pos3) * 0.025) + (ranPosPrev3 * 0.975);
      //Serial.println(ranPosSmooth3);
      ranPosPrev3 = ((ranPos3 - pos3) * 0.025) + (ranPosPrev3 * 0.975);
      if (ranPosSmooth3 == ranPos3) {
        serv3 = false;
      }
    }
    if (ranPos3 < pos3 && serv3 == true) {
      ranPosSmooth3 = pos3 - (((pos3 - ranPos3) * 0.025) + (ranPosPrev3 * 0.975));
      //Serial.println(ranPosSmooth3);
      ranPosPrev3 = (((pos3 - ranPos3) * 0.025) + (ranPosPrev3 * 0.975));
      if (ranPosSmooth3 == ranPos3) {
        serv3 = false;
      }
    }
    if (ranPos4 > pos4 && serv4 == true) {  //-----------------------------------smoothing for servo4
      ranPosSmooth4 = pos4 + ((ranPos4 - pos4) * 0.025) + (ranPosPrev4 * 0.975);
      //Serial.println(ranPosSmooth4);
      ranPosPrev4 = ((ranPos4 - pos4) * 0.025) + (ranPosPrev4 * 0.975);
      if (ranPosSmooth4 == ranPos4) {
        serv4 = false;
      }
    }
    if (ranPos4 < pos4 && serv4 == true) {
      ranPosSmooth4 = pos4 - (((pos4 - ranPos4) * 0.025) + (ranPosPrev4 * 0.975));
      //Serial.println(ranPosSmooth4);
      ranPosPrev4 = (((pos4 - ranPos4) * 0.025) + (ranPosPrev4 * 0.975));
      if (ranPosSmooth4 == ranPos4) {
        serv4 = false;
      }
    }
    if (ranPos5 > pos5 && serv5 == true) {  //-----------------------------------smoothing for servo5
      ranPosSmooth5 = pos5 + ((ranPos5 - pos5) * 0.025) + (ranPosPrev5 * 0.975);
      //Serial.println(ranPosSmooth5);
      ranPosPrev5 = ((ranPos5 - pos5) * 0.025) + (ranPosPrev5 * 0.975);
      if (ranPosSmooth5 == ranPos5) {
        serv5 = false;
      }
    }
    if (ranPos5 < pos5 && serv5 == true) {
      ranPosSmooth5 = pos5 - (((pos5 - ranPos5) * 0.025) + (ranPosPrev5 * 0.975));
      //Serial.println(ranPosSmooth5);
      ranPosPrev5 = (((pos5 - ranPos5) * 0.025) + (ranPosPrev5 * 0.975));
      if (ranPosSmooth5 == ranPos5) {
        serv5 = false;
      }
    }
    

    // Writing values to servos
    HCPCA9685.Servo(0, ranPosSmooth0);
    HCPCA9685.Servo(1, ranPosSmooth1);
    HCPCA9685.Servo(2, ranPosSmooth2);
    HCPCA9685.Servo(4, ranPosSmooth3);
    HCPCA9685.Servo(6, ranPosSmooth4);
    HCPCA9685.Servo(8, ranPosSmooth5);

    digitalWrite(lampOutput, LOW);

    delay(12);

    Serial.println("randomizing...");

    if (abs(ranPosSmooth0 - ranPos0) < 0.15) {  // exit loop when finished randomizing
      Serial.println("done.");
      
      ranPosSmooth0 = 0;
      ranPosSmooth1 = 0;
      ranPosSmooth2 = 0;
      ranPosSmooth3 = 0;
      ranPosSmooth4 = 0;
      ranPosSmooth5 = 0;
      
      ranPosPrev0 = 0;
      ranPosPrev1 = 0;
      ranPosPrev2 = 0;
      ranPosPrev3 = 0;
      ranPosPrev4 = 0;
      ranPosPrev5 = 0;
      
      break;
    }
  }
  return;
}
