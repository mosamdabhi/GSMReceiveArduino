#include <GSM.h>

char inchar; //Will hold the incoming character from the Serial Port.

// Again, this is done for testing on these arrays of LED as it suits the best for prototype. FOr any LED Matrix this can be extended
// By using the Serial.read() commands just as i have used here
// Include rest of the libraries if needed

 int led1 = 4;
 int led2 = 5;
 int led3 = 6;
 int led4 = 7; 
 int led5 = 8; 
 int led6 = 9; 
 int led7 = 10; 
 int led8 = 11; 
 int led9 = 12; 


 void setup()
 {
 // prepare the digital output pins
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
 pinMode(led6, OUTPUT);
 pinMode(led7, OUTPUT);
 pinMode(led8, OUTPUT);
 pinMode(led9, OUTPUT);
 
 
 // initially all are off
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);
 digitalWrite(led6, LOW);
 digitalWrite(led7, LOW);
 digitalWrite(led8, LOW);
 digitalWrite(led9, LOW);
 
 
 
 
 //Initialize GSM module serial port for communication.
 Serial.begin(9600);
 delay(2000); // give time for GSM module to register on network etc.
 Serial.println("AT+CMGF=1\r"); // set SMS mode to text
 delay(200);
 Serial.println("AT+CSMS=1\r"); 
 delay(200);
 
 Serial.println("AT+CNMI=2,2,0,0,0"); // set module to send SMS data to serial out upon receipt 
 delay(200);
 
 }

 void loop() 
 {
 //If a character comes in from the Cellular module...

 if(Serial.available() >0)
 {
    
//our program begins from here

 delay(10);
 inchar=Serial.read(); 
 if (inchar=='0')   // to catch the 1st 0 in our string 0#101#101#101
 {     
       inchar=Serial.read(); // read next char i.e '#'
       if (inchar=='#')
       {
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led1, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led1, HIGH);
             }
             
             
       delay(15); // i am randomly giving this input. Adjust according to your hardware and that would apply for all the delays i would be inputting in this code
             inchar=Serial.read(); //read next char i.e 0
             if (inchar=='0')
             {
                 digitalWrite(led2, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led2, HIGH);
             }
             
       delay(15);
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led3, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led3, HIGH);
             }      
       }
       //end of  1st 'if char==#' loop
       
       
       
       
       //for _____  #101  _______
       inchar=Serial.read(); // read next char i.e '#'
       if (inchar=='#')
       {
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led4, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led4, HIGH);
             }
             
             
       delay(15);
             inchar=Serial.read(); //read next char i.e 0
             if (inchar=='0')
             {
                 digitalWrite(led5, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led5, HIGH);
             }
             
       delay(15);
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led6, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led6, HIGH);
             }      
       } 
       //end of 2nd 'if char==#' loop
       
       
       
       
       //for _____ _____ #101
       inchar=Serial.read(); // read next char i.e '#'
       if (inchar=='#')
       {
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led7, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led7, HIGH);
             }
             
             
       delay(15);
             inchar=Serial.read(); //read next char i.e 0
             if (inchar=='0')
             {
                 digitalWrite(led8, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led8, HIGH);
             }
             
       delay(15);
             inchar=Serial.read(); //read next char i.e 1
             if (inchar=='0')
             {
                 digitalWrite(led9, LOW);
             } 
             else if (inchar=='1')
             {
                 digitalWrite(led9, HIGH);
             }      
       } 
       //end of 3rd 'if char==#' loop
       
       
       
 } // here, i am closing this "ckeck 0 in front of string" loop

 
 
 } // serial available condition close
 
 

} // LOOP function close
