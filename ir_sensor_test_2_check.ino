int sen1_pin = 12;
int sen2_pin = 14;
int sen1_valu = 0;
int sen2_valu = 0;
int value1 = 0;
int value2 = 0;
int count = 0;
int sen_count = 0;
int direction = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
 // hw_timer_t *timer = timerBegin(0,80,true);

}

void loop() {
  // put your main code here, to run repeatedly:
  //value1 = 0;
  //value2 = 0;
  sen1_valu = analogRead(sen1_pin);
  sen2_valu = analogRead(sen2_pin);

  //Serial.print(sen1_valu);
  //Serial.print('\t');
 // Serial.println(sen2_valu);
  //delay(500);

  if (sen1_valu<500){
    value1 = 1;
    sen_count = sen_count +1;
    if (value1 == 1){
      if(sen2_valu<500){
     // value2 = true;
        Serial.println("Clockwise");
        direction = 1;
        value1 = 0;
        value2 = 0;
      //delay(100);
    }
  }
   // delay(100);
   // if(sen_count==3){
    //  sen_count=0;
    //}
   //Serial.println(sen_count);
  //delay(500);
  }

  if (sen2_valu<500){
    value2 = 1;
    if (value2 == 1){
      if(sen1_valu<500){
     // value1 = true;
        Serial.println("Counter Clockwise");
        direction = 2;
        value1 = 0;
        value2 = 0;
      //delay(100);
    }
  }
   // delay(100);
  }

  

  
 // Serial.println("count- " +count);
 if(sen_count==3 && direction == 1){
  count = count+1;
  //Serial.println(count);
  sen_count = 0;
  direction = 0;
 }
  if(sen_count==3 && direction == 2){
  count = count-1;
  //Serial.println(count);
  sen_count = 0;
  direction = 0;
 }

  
 // if(value1 == true && value2 == true){
 //   Serial.println("Clockwise");
 //   value1 = false;
  //  value2 = false;
 // }

 /* Serial.print(value1);
  Serial.print('\t');
  Serial.println(value2);
  //value1 = false;
  //value2 = false;
  //delay(5000);*/

}
