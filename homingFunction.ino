//-------------------------Homing Function-------------------------
void homing() {
  bool moving = true;
  
  bool serv0 = true;
  bool serv1 = true;
  bool serv2 = true;
  bool serv3 = true;
  bool serv4 = true;
  bool serv5 = true;
  
  //-----Homing from Lamp Position-----
  if (lampCheck == 1) {
    while (moving = true) {
      if (lampPos0 < pos0 && serv0 == true) {  //-----------------------------------smoothing for servo0
        posSmooth0 = lampPos0 + ((pos0 - lampPos0) * 0.02) + (posPrev0 * 0.98);
        //Serial.println(posSmooth0);
        posPrev0 = ((pos0 - lampPos0) * 0.02) + (posPrev0 * 0.98);
        if (posSmooth0 == pos0) {
          serv0 = false;
        }
      }
      if (lampPos0 > pos0 && serv0 == true) {
        posSmooth0 = lampPos0 - (((lampPos0 - pos0) * 0.02) + (posPrev0 * 0.98));
        //Serial.println(posSmooth0);
        posPrev0 = ((lampPos0 - pos0) * 0.02) + (posPrev0 * 0.98);
        if (posSmooth0 == pos0) {
          serv0 = false;
        }
      }
      if (lampPos1 < pos1 && serv1 == true) {  //-----------------------------------smoothing for servo1
        posSmooth1 = lampPos1 + ((pos1 - lampPos1) * 0.02) + (posPrev1 * 0.98);
        //Serial.println(posSmooth1);
        posPrev1 = ((pos1 - lampPos1) * 0.02) + (posPrev1 * 0.98);
        if (posSmooth1 == pos1) {
          serv1 = false;
        }
      }
      if (lampPos1 > pos1 && serv1 == true) {
        posSmooth1 = lampPos1 - (((lampPos1 - pos1) * 0.02) + (posPrev1 * 0.98));
        //Serial.println(posSmooth1);
        posPrev1 = ((lampPos1 - pos1) * 0.02) + (posPrev1 * 0.98);
        if (posSmooth1 == pos1) {
          serv1 = false;
        }
      }
      if (lampPos2 < pos2 && serv2 == true) {  //-----------------------------------smoothing for servo2
        posSmooth2 = lampPos2 + ((pos2 - lampPos2) * 0.02) + (posPrev2 * 0.98);
        //Serial.println(posSmooth2);
        posPrev2 = ((pos2 - lampPos2) * 0.02) + (posPrev2 * 0.98);
        if (posSmooth2 == pos2) {
          serv2 = false;
        }
      }
      if (lampPos2 > pos2 && serv2 == true) {
        posSmooth2 = lampPos2 - (((lampPos2 - pos2) * 0.02) + (posPrev2 * 0.98));
        //Serial.println(posSmooth2);
        posPrev2 = ((lampPos2 - pos2) * 0.02) + (posPrev2 * 0.98);
        if (posSmooth2 == pos2) {
          serv2 = false;
        }
      }
      if (lampPos3 < pos3 && serv3 == true) {  //-----------------------------------smoothing for servo3
        posSmooth3 = lampPos3 + ((pos3 - lampPos3) * 0.02) + (posPrev3 * 0.98);
        //Serial.println(posSmooth3);
        posPrev3 = ((pos3 - lampPos3) * 0.02) + (posPrev3 * 0.98);
        if (posSmooth3 == pos3) {
          serv3 = false;
        }
      }
      if (lampPos3 > pos3 && serv3 == true) {
        posSmooth3 = lampPos3 - (((lampPos3 - pos3) * 0.02) + (posPrev3 * 0.98));
        //Serial.println(posSmooth3);
        posPrev3 = ((lampPos3 - pos3) * 0.02) + (posPrev3 * 0.98);
        if (posSmooth3 == pos3) {
          serv3 = false;
        }
      }
      if (lampPos4 < pos4 && serv4 == true) {  //-----------------------------------smoothing for servo4
        posSmooth4 = lampPos4 + ((pos4 - lampPos4) * 0.02) + (posPrev4 * 0.98);
        //Serial.println(posSmooth4);
        posPrev4 = ((pos4 - lampPos4) * 0.02) + (posPrev4 * 0.98);
        if (posSmooth4 == pos4) {
          serv4 = false;
        }
      }
      if (lampPos4 > pos4 && serv4 == true) {
        posSmooth4 = lampPos4 - (((lampPos4 - pos4) * 0.02) + (posPrev4 * 0.98));
        //Serial.println(posSmooth4);
        posPrev4 = ((lampPos4 - pos4) * 0.02) + (posPrev4 * 0.98);
        if (posSmooth4 == pos4) {
          serv4 = false;
        }
      }
      if (lampPos5 < pos5 && serv5 == true) {  //-----------------------------------smoothing for servo5
        posSmooth5 = lampPos5 + ((pos5 - lampPos5) * 0.02) + (posPrev5 * 0.98);
        //Serial.println(posSmooth5);
        posPrev5 = ((pos5 - lampPos5) * 0.02) + (posPrev5 * 0.98);
        if (posSmooth5 == pos5) {
          serv5 = false;
        }
      }
      if (lampPos5 > pos5 && serv5 == true) {
        posSmooth5 = lampPos5 - (((lampPos5 - pos5) * 0.02) + (posPrev5 * 0.98));
        //Serial.println(posSmooth5);
        posPrev5 = ((lampPos5 - pos5) * 0.02) + (posPrev5 * 0.98);
        if (posSmooth5 == pos5) {
          serv5 = false;
        }
      }

      // Writing values to servos
      HCPCA9685.Servo(0, posSmooth0);
      HCPCA9685.Servo(1, posSmooth1);
      HCPCA9685.Servo(2, posSmooth2);
      HCPCA9685.Servo(4, posSmooth3);
      HCPCA9685.Servo(6, posSmooth4);
      HCPCA9685.Servo(8, posSmooth5);

      digitalWrite(lampOutput, LOW);
    
      delay(20);

      Serial.println("homing...");

      //Serial.print(posSmooth0);
      //Serial.print("   ");
      //Serial.println(pos0);
      
      if (abs(posSmooth0 - pos0) < 0.15) {  // exit loop when finished homing
        Serial.println("done.");
        
        posSmooth0 = 0;
        posSmooth1 = 0;
        posSmooth2 = 0;
        posSmooth3 = 0;
        posSmooth4 = 0;
        posSmooth5 = 0;
        
        posPrev0 = 0;
        posPrev1 = 0;
        posPrev2 = 0;
        posPrev3 = 0;
        posPrev4 = 0;
        posPrev5 = 0;

        lampCheck = 0;
        ranCheck = 0;
        
        break;
      }
    }
    return;
  }

  //-----Homing from Random Position-----
  if (ranCheck == 1) {
    while (moving = true) {
      if (ranPos0 < pos0 && serv0 == true) {  //-----------------------------------smoothing for servo0
        posSmooth0 = ranPos0 + ((pos0 - ranPos0) * 0.02) + (posPrev0 * 0.98);
        //Serial.println(posSmooth0);
        posPrev0 = ((pos0 - ranPos0) * 0.02) + (posPrev0 * 0.98);
        if (posSmooth0 == pos0) {
          serv0 = false;
        }
      }
      if (ranPos0 > pos0 && serv0 == true) {
        posSmooth0 = ranPos0 - (((ranPos0 - pos0) * 0.02) + (posPrev0 * 0.98));
        //Serial.println(posSmooth0);
        posPrev0 = ((ranPos0 - pos0) * 0.02) + (posPrev0 * 0.98);
        if (posSmooth0 == pos0) {
          serv0 = false;
        }
      }
      if (ranPos1 < pos1 && serv1 == true) {  //-----------------------------------smoothing for servo1
        posSmooth1 = ranPos1 + ((pos1 - ranPos1) * 0.02) + (posPrev1 * 0.98);
        //Serial.println(posSmooth1);
        posPrev1 = ((pos1 - ranPos1) * 0.02) + (posPrev1 * 0.98);
        if (posSmooth1 == pos1) {
          serv1 = false;
        }
      }
      if (ranPos1 > pos1 && serv1 == true) {
        posSmooth1 = ranPos1 - (((ranPos1 - pos1) * 0.02) + (posPrev1 * 0.98));
        //Serial.println(posSmooth1);
        posPrev1 = ((ranPos1 - pos1) * 0.02) + (posPrev1 * 0.98);
        if (posSmooth1 == pos1) {
          serv1 = false;
        }
      }
      if (ranPos2 < pos2 && serv2 == true) {  //-----------------------------------smoothing for servo2
        posSmooth2 = ranPos2 + ((pos2 - ranPos2) * 0.02) + (posPrev2 * 0.98);
        //Serial.println(posSmooth2);
        posPrev2 = ((pos2 - ranPos2) * 0.02) + (posPrev2 * 0.98);
        if (posSmooth2 == pos2) {
          serv2 = false;
        }
      }
      if (ranPos2 > pos2 && serv2 == true) {
        posSmooth2 = ranPos2 - (((ranPos2 - pos2) * 0.02) + (posPrev2 * 0.98));
        //Serial.println(posSmooth2);
        posPrev2 = ((ranPos2 - pos2) * 0.02) + (posPrev2 * 0.98);
        if (posSmooth2 == pos2) {
          serv2 = false;
        }
      }
      if (ranPos3 < pos3 && serv3 == true) {  //-----------------------------------smoothing for servo3
        posSmooth3 = ranPos3 + ((pos3 - ranPos3) * 0.02) + (posPrev3 * 0.98);
        //Serial.println(posSmooth3);
        posPrev3 = ((pos3 - ranPos3) * 0.02) + (posPrev3 * 0.98);
        if (posSmooth3 == pos3) {
          serv3 = false;
        }
      }
      if (ranPos3 > pos3 && serv3 == true) {
        posSmooth3 = ranPos3 - (((ranPos3 - pos3) * 0.02) + (posPrev3 * 0.98));
        //Serial.println(posSmooth3);
        posPrev3 = ((ranPos3 - pos3) * 0.02) + (posPrev3 * 0.98);
        if (posSmooth3 == pos3) {
          serv3 = false;
        }
      }
      if (ranPos4 < pos4 && serv4 == true) {  //-----------------------------------smoothing for servo4
        posSmooth4 = ranPos4 + ((pos4 - ranPos4) * 0.02) + (posPrev4 * 0.98);
        //Serial.println(posSmooth4);
        posPrev4 = ((pos4 - ranPos4) * 0.02) + (posPrev4 * 0.98);
        if (posSmooth4 == pos4) {
          serv4 = false;
        }
      }
      if (ranPos4 > pos4 && serv4 == true) {
        posSmooth4 = ranPos4 - (((ranPos4 - pos4) * 0.02) + (posPrev4 * 0.98));
        //Serial.println(posSmooth4);
        posPrev4 = ((ranPos4 - pos4) * 0.02) + (posPrev4 * 0.98);
        if (posSmooth4 == pos4) {
          serv4 = false;
        }
      }
      if (ranPos5 < pos5 && serv5 == true) {  //-----------------------------------smoothing for servo5
        posSmooth5 = ranPos5 + ((pos5 - ranPos5) * 0.02) + (posPrev5 * 0.98);
        //Serial.println(posSmooth5);
        posPrev5 = ((pos5 - ranPos5) * 0.02) + (posPrev5 * 0.98);
        if (posSmooth5 == pos5) {
          serv5 = false;
        }
      }
      if (ranPos5 > pos5 && serv5 == true) {
        posSmooth5 = ranPos5 - (((ranPos5 - pos5) * 0.02) + (posPrev5 * 0.98));
        //Serial.println(posSmooth5);
        posPrev5 = ((ranPos5 - pos5) * 0.02) + (posPrev5 * 0.98);
        if (posSmooth5 == pos5) {
          serv5 = false;
        }
      }

      // Writing values to servos
      HCPCA9685.Servo(0, posSmooth0);
      HCPCA9685.Servo(1, posSmooth1);
      HCPCA9685.Servo(2, posSmooth2);
      HCPCA9685.Servo(4, posSmooth3);
      HCPCA9685.Servo(6, posSmooth4);
      HCPCA9685.Servo(8, posSmooth5);
    
      delay(12);

      Serial.println("homing...");

      //Serial.print(posSmooth0);
      //Serial.print("   ");
      //Serial.println(pos0);
      
      if (abs(posSmooth0 - pos0) < 0.15) {  // exit loop when finished homing
        Serial.println("done.");
        
        posSmooth0 = 0;
        posSmooth1 = 0;
        posSmooth2 = 0;
        posSmooth3 = 0;
        posSmooth4 = 0;
        posSmooth5 = 0;
        
        posPrev0 = 0;
        posPrev1 = 0;
        posPrev2 = 0;
        posPrev3 = 0;
        posPrev4 = 0;
        posPrev5 = 0;

        lampCheck = 0;
        ranCheck = 0;
        
        break;
      }
    }
    return;
  }
}
