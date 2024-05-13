//-------------------------Lamp Position Function-------------------------
void lamp_position() {
  bool moving = true;

  bool serv0 = true;
  bool serv1 = true;
  bool serv2 = true;
  bool serv3 = true;
  bool serv4 = true;
  bool serv5 = true;

  lampCheck = 1;
    
  while (moving = true) {
    if (lampPos0 > pos0 && serv0 == true) {  //-----------------------------------smoothing for servo0
      lampPosSmooth0 = pos0 + ((lampPos0 - pos0) * 0.025) + (lampPosPrev0 * 0.975);
      //Serial.println(lampPosSmooth0);
      lampPosPrev0 = ((lampPos0 - pos0) * 0.025) + (lampPosPrev0 * 0.975);
      if (lampPosSmooth0 == lampPos0) {
        serv0 = false;
      }
    }
    if (lampPos0 < pos0 && serv0 == true) {
      lampPosSmooth0 = pos0 - (((pos0 - lampPos0) * 0.025) + (lampPosPrev0 * 0.975));
      //Serial.println(lampPosSmooth0);
      lampPosPrev0 = (((pos0 - lampPos0) * 0.025) + (lampPosPrev0 * 0.975));
      if (lampPosSmooth0 == lampPos0) {
        serv0 = false;
      }
    }
    if (lampPos1 > pos1 && serv1 == true) {  //-----------------------------------smoothing for servo1
      lampPosSmooth1 = pos1 + ((lampPos1 - pos1) * 0.025) + (lampPosPrev1 * 0.975);
      //Serial.println(lampPosSmooth1);
      lampPosPrev1 = ((lampPos1 - pos1) * 0.025) + (lampPosPrev1 * 0.975);
      if (lampPosSmooth1 == lampPos1) {
        serv1 = false;
      }
    }
    if (lampPos1 < pos1 && serv1 == true) {
      lampPosSmooth1 = pos1 - (((pos1 - lampPos1) * 0.025) + (lampPosPrev1 * 0.975));
      //Serial.println(lampPosSmooth1);
      lampPosPrev1 = (((pos1 - lampPos1) * 0.025) + (lampPosPrev1 * 0.975));
      if (lampPosSmooth1 == lampPos1) {
        serv1 = false;
      }
    }
    if (lampPos2 > pos2 && serv2 == true) {  //-----------------------------------smoothing for servo2
      lampPosSmooth2 = pos2 + ((lampPos2 - pos2) * 0.025) + (lampPosPrev2 * 0.975);
      //Serial.println(lampPosSmooth2);
      lampPosPrev2 = ((lampPos2 - pos2) * 0.025) + (lampPosPrev2 * 0.975);
      if (lampPosSmooth2 == lampPos2) {
        serv2 = false;
      }
    }
    if (lampPos2 < pos2 && serv2 == true) {
      lampPosSmooth2 = pos2 - (((pos2 - lampPos2) * 0.025) + (lampPosPrev2 * 0.975));
      //Serial.println(lampPosSmooth2);
      lampPosPrev2 = (((pos2 - lampPos2) * 0.025) + (lampPosPrev2 * 0.975));
      if (lampPosSmooth2 == lampPos2) {
        serv2 = false;
      }
    }
    if (lampPos3 > pos3 && serv3 == true) {  //-----------------------------------smoothing for servo3
      lampPosSmooth3 = pos3 + ((lampPos3 - pos3) * 0.025) + (lampPosPrev3 * 0.975);
      //Serial.println(lampPosSmooth3);
      lampPosPrev3 = ((lampPos3 - pos3) * 0.025) + (lampPosPrev3 * 0.975);
      if (lampPosSmooth3 == lampPos3) {
        serv3 = false;
      }
    }
    if (lampPos3 < pos3 && serv3 == true) {
      lampPosSmooth3 = pos3 - (((pos3 - lampPos3) * 0.025) + (lampPosPrev3 * 0.975));
      //Serial.println(lampPosSmooth3);
      lampPosPrev3 = (((pos3 - lampPos3) * 0.025) + (lampPosPrev3 * 0.975));
      if (lampPosSmooth3 == lampPos3) {
        serv3 = false;
      }
    }
    if (lampPos4 > pos4 && serv4 == true) {  //-----------------------------------smoothing for servo4
      lampPosSmooth4 = pos4 + ((lampPos4 - pos4) * 0.025) + (lampPosPrev4 * 0.975);
      //Serial.println(lampPosSmooth4);
      lampPosPrev4 = ((lampPos4 - pos4) * 0.025) + (lampPosPrev4 * 0.975);
      if (lampPosSmooth4 == lampPos4) {
        serv4 = false;
      }
    }
    if (lampPos4 < pos4 && serv4 == true) {
      lampPosSmooth4 = pos4 - (((pos4 - lampPos4) * 0.025) + (lampPosPrev4 * 0.975));
      //Serial.println(lampPosSmooth4);
      lampPosPrev4 = (((pos4 - lampPos4) * 0.025) + (lampPosPrev4 * 0.975));
      if (lampPosSmooth4 == lampPos4) {
        serv4 = false;
      }
    }
    if (lampPos5 > pos5 && serv5 == true) {  //-----------------------------------smoothing for servo5
      lampPosSmooth5 = pos5 + ((lampPos5 - pos5) * 0.025) + (lampPosPrev5 * 0.975);
      //Serial.println(lampPosSmooth5);
      lampPosPrev5 = ((lampPos5 - pos5) * 0.025) + (lampPosPrev5 * 0.975);
      if (lampPosSmooth5 == lampPos5) {
        serv5 = false;
      }
    }
    if (lampPos5 < pos5 && serv5 == true) {
      lampPosSmooth5 = pos5 - (((pos5 - lampPos5) * 0.025) + (lampPosPrev5 * 0.975));
      //Serial.println(lampPosSmooth5);
      lampPosPrev5 = (((pos5 - lampPos5) * 0.025) + (lampPosPrev5 * 0.975));
      if (lampPosSmooth5 == lampPos5) {
        serv5 = false;
      }
    }
    

    // Writing values to servos
    HCPCA9685.Servo(0, lampPosSmooth0);
    HCPCA9685.Servo(1, lampPosSmooth1);
    HCPCA9685.Servo(2, lampPosSmooth2);
    HCPCA9685.Servo(4, lampPosSmooth3);
    HCPCA9685.Servo(6, lampPosSmooth4);
    HCPCA9685.Servo(8, lampPosSmooth5);

    digitalWrite(lampOutput, HIGH);
        
    delay(12);

    Serial.println("moving...");

    if (abs(lampPosSmooth0 - lampPos0) < 0.15) {  // exit loop when finished moving
      Serial.println("done.");
      
      lampPosSmooth0 = 0;
      lampPosSmooth1 = 0;
      lampPosSmooth2 = 0;
      lampPosSmooth3 = 0;
      lampPosSmooth4 = 0;
      lampPosSmooth5 = 0;
      
      lampPosPrev0 = 0;
      lampPosPrev1 = 0;
      lampPosPrev2 = 0;
      lampPosPrev3 = 0;
      lampPosPrev4 = 0;
      lampPosPrev5 = 0;
      
      break;
    }
  }
  return;
}
