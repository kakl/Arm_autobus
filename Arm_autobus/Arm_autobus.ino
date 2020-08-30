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

int nahorudolu = 150;
int dopredudozadu = 60;
int otevritzavrit = 120;
int zavora = 52;
int otaceni = 164;

void setup() 
{ 
  Serial.begin(9600);
  
  myservo1.attach(2); //servo celisti
  myservo1.write(otevritzavrit);
  delay(1000);  

  myservo4.attach(5); //servo nahoru 
  myservo4.write(nahorudolu);
  delay(1000);  

  myservo2.attach(3); //servo dopredu
  myservo2.write(dopredudozadu);
  delay(1000);  

  myservo3.attach(4); //servo otaceni
  myservo3.write(otaceni);
  delay(1000);  

  myservo5.attach(6); //servo zavora rameno 
  myservo5.write(zavora);
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
  vpred(80, 10, 0);
  delay(1000);  

  dolu(70, 10, 0);
  delay(1000); 

  vpred(90, 10, 0);
  delay(1000);  

  dolu(63, 10, 0);
  delay(1000); 

zavora_nahoru(164, 5, 0);
 
  zavrit(70, 40, 0);
  delay(1000); 

zavora_dolu(52, 5, 1);
delay(1000); 

  nahoru(150, 10, 0);
  delay(1000);  


  vpravo(130, 20, 0);
  delay(1000); 

    vpred(110, 20, 0);
    delay(1000);  

  otevrit(120, 40, 1);
  delay(1000); 
  
    vzad(50, 5, 0);
    delay(2000); 

  vlevo(164, 20, 0);
  delay(1000);       

    //vpred(85, 20, 0);
    //delay(1000);  

  delay(2000);
   
} 


int vpred(int angle_high, int time, int stav){//Servo2 min 180 max 68

  myservo2.attach(3);
  for(pos = dopredudozadu; pos <= angle_high; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  dopredudozadu = pos;
  if(stav==1)
    myservo2.detach();

}

int vzad(int angle_low, int time, int stav){//Servo2 min 180 max 68

  myservo2.attach(3);
  for(pos = dopredudozadu; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  dopredudozadu = pos;
  if(stav==1)
    myservo2.detach();

}

int dolu(int angle_low, int time, int stav){//Servo4 min 14 max 132

  myservo4.attach(5);
  for(pos = nahorudolu; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  nahorudolu = pos;
  if(stav==1)
    myservo4.detach();

}

int nahoru(int angle_high, int time, int stav){//Servo4 min 14 max 132

  myservo4.attach(5);
  for(pos = nahorudolu; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo4.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  nahorudolu = pos;
  if(stav==1)
    myservo4.detach();

}

int vlevo(int angle_high, int time, int stav){//Servo3 min 0 max 180

  myservo3.attach(4);
  for(pos = otaceni; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  otaceni = pos;
  if(stav==1)
    myservo3.detach();

}

int vpravo(int angle_low, int time, int stav){//Servo3 min 0 max 180

  myservo3.attach(4);
  for(pos = otaceni; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo3.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  otaceni = pos;
  if(stav==1)
    myservo3.detach();

}


int otevrit(int angle_high, int time, int stav){//Servo1 min 63 max 120

  myservo1.attach(2);
  for(pos = otevritzavrit; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  otevritzavrit = pos;
  if(stav==1)
    myservo1.detach();

}

int zavrit(int angle_low, int time, int stav){//Servo1 min 63 max 120

  myservo1.attach(2);
  for(pos = otevritzavrit; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  otevritzavrit = pos;
  if(stav==1)
    myservo1.detach();

}

int zavora_nahoru(int angle_high, int time, int stav){//Servo1 min 63 max 120

  myservo5.attach(6);
  for(pos = zavora; pos<=angle_high; pos+=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  zavora = pos;
  if(stav==1)
    myservo5.detach();

}

int zavora_dolu(int angle_low, int time, int stav){//Servo1 min 63 max 120

  myservo5.attach(6);
  for(pos = zavora; pos>=angle_low; pos-=1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo5.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(time);                      
  }
  zavora = pos;
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
