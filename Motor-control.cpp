
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


// g++ -std=c++14 Lab6EX2.cpp -o Lab6EX2 -lwiringPi, to compile
//setting button IO pins up 
int button1=4;
int button2=1;
int flag=0;
int i=0;

void pause_button(){
    cout<<"Stopped"<<endl;
    delay(100);
    if(digitalRead(button1)==1){
        flag=1-flag;
        cout<<flag<<endl;
        if(flag==1){//to stop motor
            digitalWrite(2,LOW);
            digitalWrite(3,LOW);
        }else{//to start motor 
            digitalWrite(2,HIGH);
            digitalWrite(3,LOW);
            pwmWrite(26,350);


        }
    }
}
void speed_button(){
  
    if(digitalRead(button2)==1){
        
        delay(100);
        cout<<i<<endl;
       
        
        switch(++i){
            case 1:
                  delay(150);
                  pwmWrite(26,300);
                 cout<<"Low Speed"<<endl;//speed 1
           break;
            case 2:
                 delay(150);
                 pwmWrite(26,500);
                  cout<<"Medium speed"<<endl;//speed 2
           break;
            case 3:
                delay(150);
                 pwmWrite(26,850);
                  cout<<"High Speed"<<endl;//speed 3
            break;
            
                }
            }
        }


int main(void){
    
    wiringPiSetup();
    /* 1. set mode for the three I/O pins, the pin mode of the PWM pin should be PWM_OUTPUT */
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,INPUT);
    pinMode(1,INPUT);

    pinMode(26,PWM_OUTPUT);//speed control



//The stop start button interupt 
wiringPiISR(button1,INT_EDGE_BOTH,&pause_button);//call pause function 
wiringPiISR(button2,INT_EDGE_BOTH,&speed_button);//call speed function




    while(1){
       
    // control the motor using two buttons 

    }
    return 0;
}

