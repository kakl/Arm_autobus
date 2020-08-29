/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.
 
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
 */

#include <Servo.h> 

Servo myservo1;  // create servo object to control a servo 
Servo myservo2;                
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pos = 0;    // variable to store the servo position 
char c = ' ';
int potpin = 2;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin


void setup() 
{ 
  Serial.begin(9600);
  
  myservo1.attach(2); //servo celisti
  myservo1.write(120);
  delay(1000);  

  myservo4.attach(5); //servo nahoru 
  myservo4.write(140);
  delay(1000);  

  myservo2.attach(3); //servo dopredu
  myservo2.write(60);
  delay(1000);  

  myservo3.attach(4); //servo otaceni
  myservo3.write(163);
  delay(1000);  

  myservo5.attach(6); //servo zavora rameno 
  myservo5.write(52);
  delay(1000); 

  vpred(60, 88, 10, 0);
  delay(1000);  

} 

//Servo1 min 63 max 120
//Servo2 min 166 max 40
//Servo3 min 0 max 180
//Servo4 min 50 max 132
//Servo5 min  max 

//167  136 otaceni
//prvni rameno zacatek 122 konec 138
//druhe rameno zacatek 77 konec 168
//zavora dole 52 nahore 164

//149


#define DORAZ 110
#define trychtyr 140

void loop() 
{ 
  //test();

  dolu(140, 55, 10, 0);
  delay(1000); 

zavora_nahoru(52, 164, 5, 0);

  zavrit(120, 70, 40, 0);
  delay(1000); 

zavora_dolu(52, 164, 5, 0);
delay(1000); 

  nahoru(55, 140, 10, 0);
  delay(1000);  


  vpravo(163, 132, 20, 0);
  delay(1000); 

    vpred(88, 110, 20, 0);
    delay(1000);  

  otevrit(70, 120, 40, 0);
  delay(1000); 
  
    vzad(110, 50, 5, 0);
    delay(2000); 

  vlevo(132, 163, 20, 0);
  delay(1000);       

    vpred(50, 88, 20, 0);
    delay(1000);  

delay(2000);

return;
      myservo1.attach(2);//servo celisti
      myservo1.write(120);

      myservo2.attach(3);//servo prvni rameno
      myservo2.write(80);
      delay(1000);
      myservo4.attach(5);//servo druhe rameno
      myservo4.write(149);
      
      //vlevo(133, 168, 20, 1);//vlevo(136, 167, 20, 1)
      //delay(400);
      
      //myservo3.detach();
      //myservo2.detach();


      zavora_nahoru(52, 164, 5, 1);
      //myservo2.attach(3);//servo prvni rameno
      //myservo2.write(80);
      //delay(1000);
      //myservo4.attach(5);//servo druhe rameno
      //myservo4.write(149);
      
      //vlevo(133, 168, 20, 1);//vlevo(136, 167, 20, 1)
      //delay(400);
      
      //myservo3.detach();
      //myservo2.detach();

      nahoru(77, DORAZ-40, 40, 1);
      delay(400);
      dolu(77, 140, 40, 0);

delay(2000);
      
return;      
      //otevrit(63, 120, 20, 1);
      
      dolu(77, 140, 25, 0);
      //dolu(77, 125, 20, 0);
      //!!!vpred(120, 123, 4, 0);
      vpred(60, DORAZ, 30, 0);
      
      //myservo2.write(125);
      //zavrit(71, 120, 40, 0);
      zavrit(71, DORAZ, 40, 0);
      
      //vzad(80, 100, 10, 0);
      
      nahoru(77, DORAZ, 10, 1);
      vpravo(133, 168, 20, 1);
      vpred(80, 140, 20, 0);
      zavora_dolu(52, 164, 5, 1);
      otevrit(70, 120, 20, 1);
      vzad(80, 138, 20, 0);
      dolu(149, 168, 20, 1);
      delay(1000);
      //vpred(122, 168, 20, 0);
      //dolu(77, 168, 20, 0);//27
      /*
      myservo2.attach(3);//servo prvni rameno
      //myservo2.write(130);//130
      vpred(122, 168, 20, 0);
      delay(400);
      
      zavrit(71, 120, 40, 0);
      delay(400);
      myservo2.detach();
      
      vzad(75, 130, 20, 0);
      
      delay(400);
      vpravo(136, 167, 20, 0);
      nahoru(14, 118, 20, 0);//27 100
      vpred(122, 138, 20, 0);
      delay(400);
      zavora_dolu(52, 164, 5, 1);
      
      otevrit(70, 120, 20, 1);
      myservo2.detach();
      myservo4.detach();
      myservo1.detach();
      
      myservo3.detach();
      vzad(68, 130, 20, 0);
      myservo2.detach();
     //pocatecni pozice natoceni 132
     //konecna pozice natoceni 97 kdy pusti kulicku
     
     //pocatek druhe rameno 27 (32)
      */
    
    
    
   
} 


int vpred(int angle_low, int angle_high, int time, int stav){//Servo2 min 180 max 68

  myservo2.attach(3);
  for(pos = angle_low; pos <= angle_high; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo2.detach();

}

int vzad(int angle_high, int angle_low, int time, int stav){//Servo2 min 180 max 68

  myservo2.attach(3);
  for(pos = angle_high; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo2.detach();

}

int dolu(int angle_high, int angle_low, int time, int stav){//Servo4 min 14 max 132

  //myservo4.attach(5);
  for(pos = angle_high; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo4.detach();

}

int nahoru(int angle_low, int angle_high, int time, int stav){//Servo4 min 14 max 132

  //myservo4.attach(5);
  for(pos = angle_low; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo4.detach();

}

int vlevo(int angle_low, int angle_high, int time, int stav){//Servo3 min 0 max 180

  //myservo3.attach(4);
  for(pos = angle_low; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo3.detach();

}

int vpravo(int angle_high, int angle_low, int time, int stav){//Servo3 min 0 max 180

  //myservo3.attach(4);
  for(pos = angle_high; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo3.detach();

}


int otevrit(int angle_low, int angle_high, int time, int stav){//Servo1 min 63 max 120

  //myservo1.attach(2);
  for(pos = angle_low; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo1.detach();

}

int zavrit(int angle_high, int angle_low, int time, int stav){//Servo1 min 63 max 120

  //myservo1.attach(2);
  for(pos = angle_high; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo1.detach();

}

int zavora_nahoru(int angle_low, int angle_high, int time, int stav){//Servo1 min 63 max 120

  //myservo5.attach(6);
  for(pos = angle_low; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo5.detach();

}

int zavora_dolu(int angle_low, int angle_high, int time, int stav){//Servo1 min 63 max 120

  //myservo5.attach(6);
  for(pos = angle_high; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  if(stav==1)
    myservo5.detach();

}

void test(){

  //myservo3.attach(4);
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.println(val);
  myservo4.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  //myservo3.detach();

}
