#include <EEPROM.h>

const int led1 = 16;
const int led2 = 0;
const int led3 = 1;
const int led4 = 7;
const int led5 = 8;
const int led6 = 9;
const int led7 = 10;
const int led8 = 11;
const int button = 14;

//---BUTTON HOLD TIME PRESETS---//

//Counter Value
float pressLength_ms = 0;

//Animation Type
int singleBeam = 1000;
int multiBeam = 2000;

//Animation Speed
int slow = 3000;
int fast = 4000;

//LED Brightness
int led100 = 5000;
int led75 = 6000;
int led50 = 7000;
int led25 = 8000;

//------------------------------//

int buttonState = 1;

byte startupStateVal;
byte animationType;
byte animationSpeed;
byte ledBrightness;
byte delayVal;
float brightnessScaleVal;

void setup() {               
    pinMode(led1, OUTPUT); 
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
    pinMode(led8, OUTPUT); 
    pinMode(button, INPUT);   

    byte startupState = digitalRead(button);
    EEPROM.write(1, startupState);
   
//  EEPROM.write(3, 0);     // Values (0,1)             // Animation Type
//  EEPROM.write(5, 50);    // Values (75,50)           // Animation Speed
//  EEPROM.write(7, 255);   // Values (255,191,127,63)  // LED Brightness

}

void loop() {
    startupStateVal = EEPROM.read(1);
    animationType = EEPROM.read(3);
    animationSpeed = EEPROM.read(5);
    ledBrightness = EEPROM.read(7);
    
    switch(startupStateVal) {
        case 0:
            showConfig();
            buttonHoldTimer();
            setConfig();
        break;
        
        case 1:
            buttonState = digitalRead(button);
            if(buttonState == 0){
                if(animationType == 0){
                    multiBeamAnimationFlash();
                }
                else if(animationType == 1){
                    singleBeamAnimationFlash();
                } 
            }
            else if(buttonState == 1){
                if(animationType == 0){
                    multiBeamAnimation();
                }
                else if(animationType == 1){
                    singleBeamAnimation();
                } 
            } 
        break;
    }
}

void showConfig(){
    while (digitalRead(button) == HIGH ){ 
        if(animationType == 0){
            analogWrite(led1, 0);
            analogWrite(led2, ledBrightness);
        }
        else if(animationType == 1){
            analogWrite(led1, ledBrightness);
            analogWrite(led2, 0);
        }

        if(animationSpeed == 50){
            analogWrite(led3, 0);
            analogWrite(led4, ledBrightness);
        }
        else if(animationSpeed == 75){
            analogWrite(led3, ledBrightness);
            analogWrite(led4, 0);
        }
        
        if(ledBrightness == 63){
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, ledBrightness);
        }
        else if(ledBrightness == 127){
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, ledBrightness);
            analogWrite(led8, ledBrightness);
        }
        else if(ledBrightness == 191){
            analogWrite(led5, 0);
            analogWrite(led6, ledBrightness);
            analogWrite(led7, ledBrightness);
            analogWrite(led8, ledBrightness);         
        }
        else if(ledBrightness == 255){
            analogWrite(led5, ledBrightness);
            analogWrite(led6, ledBrightness);
            analogWrite(led7, ledBrightness);
            analogWrite(led8, ledBrightness);
        }    
    }            
}

void buttonHoldTimer(){
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
    analogWrite(led5, 0);
    analogWrite(led6, 0);
    analogWrite(led7, 0);
    analogWrite(led8, 0);
    
    while (digitalRead(button) == LOW ){ 
        delay(50);
        pressLength_ms = pressLength_ms + 50; 
        
        if(pressLength_ms >= led25){
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, ledBrightness);  
        } 
        else if(pressLength_ms >= led50){ 
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, ledBrightness);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= led75){
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, ledBrightness);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= led100){
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, ledBrightness);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= fast){ 
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, ledBrightness);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= slow){ 
            analogWrite(led1, 0);
            analogWrite(led2, 0);
            analogWrite(led3, ledBrightness);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= multiBeam){ 
            analogWrite(led1, 0);
            analogWrite(led2, ledBrightness);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }
        else if(pressLength_ms >= singleBeam){  
            analogWrite(led1, ledBrightness);
            analogWrite(led2, 0);
            analogWrite(led3, 0);
            analogWrite(led4, 0);
            analogWrite(led5, 0);
            analogWrite(led6, 0);
            analogWrite(led7, 0);
            analogWrite(led8, 0);  
        }      
    }
}

void setConfig(){
    if(pressLength_ms >= led25){
        EEPROM.write(7, 63);  
    } 
    else if(pressLength_ms >= led50){ 
        EEPROM.write(7, 127);  
    }
    else if(pressLength_ms >= led75){
        EEPROM.write(7, 191);  
    }
    else if(pressLength_ms >= led100){
        EEPROM.write(7, 255);  
    }
    else if(pressLength_ms >= fast){ 
        EEPROM.write(5, 50);  
    }
    else if(pressLength_ms >= slow){ 
        EEPROM.write(5, 75);  
    }
    else if(pressLength_ms >= multiBeam){ 
        EEPROM.write(3, 0);  
    }
    else if(pressLength_ms >= singleBeam){  
        EEPROM.write(3, 1);  
    }
    pressLength_ms = 0;
}

void singleBeamAnimation(){
    float brightnessScaleVal = ledBrightness/255.00;
    analogWrite(led1, 10*brightnessScaleVal);
    delay(animationSpeed-10); 
    analogWrite(led2, 30*brightnessScaleVal);
    delay(animationSpeed-10); 
    analogWrite(led3, 60*brightnessScaleVal);
    delay(animationSpeed-10);
    analogWrite(led4, 100*brightnessScaleVal);
    delay(animationSpeed);
    analogWrite(led5, 150*brightnessScaleVal);
    delay(animationSpeed-10);
    analogWrite(led1, 0);
    analogWrite(led2, 10*brightnessScaleVal);
    analogWrite(led3, 30*brightnessScaleVal);
    analogWrite(led4, 60*brightnessScaleVal);
    analogWrite(led5, 100*brightnessScaleVal);
    analogWrite(led6, 180*brightnessScaleVal);
    delay(animationSpeed-10);
    analogWrite(led2, 0);
    analogWrite(led3, 10*brightnessScaleVal);
    analogWrite(led4, 30*brightnessScaleVal);
    analogWrite(led5, 70*brightnessScaleVal);
    analogWrite(led6, 130*brightnessScaleVal);
    analogWrite(led7, 200*brightnessScaleVal);
    delay(animationSpeed-10);
    analogWrite(led3, 0);
    analogWrite(led4, 20*brightnessScaleVal);
    analogWrite(led5, 80*brightnessScaleVal);
    analogWrite(led6, 150*brightnessScaleVal);
    analogWrite(led7, 180*brightnessScaleVal);
    analogWrite(led8, 255*brightnessScaleVal);
    delay(animationSpeed-10);
    analogWrite(led4, 0);
    delay(animationSpeed-10);
    analogWrite(led5, 0);
    delay(animationSpeed-10);
    analogWrite(led6, 0);
    delay(animationSpeed-10);
    analogWrite(led7, 0);
    delay(animationSpeed-10);
    analogWrite(led8, 0);
}

void singleBeamAnimationFlash(){
    float brightnessScaleVal = ledBrightness/255.00;
    for(int del=40;del>0;del--){
        analogWrite(led1, 10*brightnessScaleVal);
        delay(del); 
        analogWrite(led2, 30*brightnessScaleVal);
        delay(del); 
        analogWrite(led3, 60*brightnessScaleVal);
        delay(del);
        analogWrite(led4, 100*brightnessScaleVal);
        delay(del);
        analogWrite(led5, 150*brightnessScaleVal);
        delay(del);
        analogWrite(led1, 0);
        analogWrite(led2, 10*brightnessScaleVal);
        analogWrite(led3, 30*brightnessScaleVal);
        analogWrite(led4, 60*brightnessScaleVal);
        analogWrite(led5, 100*brightnessScaleVal);
        analogWrite(led6, 180*brightnessScaleVal);
        delay(del);
        analogWrite(led2, 0);
        analogWrite(led3, 10*brightnessScaleVal);
        analogWrite(led4, 30*brightnessScaleVal);
        analogWrite(led5, 70*brightnessScaleVal);
        analogWrite(led6, 130*brightnessScaleVal);
        analogWrite(led7, 200*brightnessScaleVal);
        delay(del);
        analogWrite(led3, 0);
        analogWrite(led4, 20*brightnessScaleVal);
        analogWrite(led5, 80*brightnessScaleVal);
        analogWrite(led6, 150*brightnessScaleVal);
        analogWrite(led7, 180*brightnessScaleVal);
        analogWrite(led8, 255*brightnessScaleVal);
        delay(del);
        analogWrite(led4, 0);
        delay(del);
        analogWrite(led5, 0);
        delay(del);
        analogWrite(led6, 0);
        delay(del);
        analogWrite(led7, 0);
        delay(del);
        analogWrite(led8, 0);
    }

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
}

void multiBeamAnimation(){
    float brightnessScaleVal = ledBrightness/255.00;
    analogWrite(led1, 31*brightnessScaleVal);
    analogWrite(led6, 191*brightnessScaleVal);
    analogWrite(led7, 223*brightnessScaleVal);
    delay(animationSpeed); 
    analogWrite(led1, 31*brightnessScaleVal);
    analogWrite(led2, 63*brightnessScaleVal);
    analogWrite(led7, 223*brightnessScaleVal);
    analogWrite(led8, 255*brightnessScaleVal);
    analogWrite(led6, 0);
    delay(animationSpeed);
    analogWrite(led2, 63*brightnessScaleVal);
    analogWrite(led3, 95*brightnessScaleVal);
    analogWrite(led8, 255*brightnessScaleVal);
    analogWrite(led1, 0);
    analogWrite(led7, 0);
    delay(animationSpeed);
    analogWrite(led3, 95*brightnessScaleVal);
    analogWrite(led4, 127*brightnessScaleVal);
    analogWrite(led2, 0);
    analogWrite(led8, 0);
    delay(animationSpeed);
    analogWrite(led4, 127*brightnessScaleVal);
    analogWrite(led5, 159*brightnessScaleVal);
    analogWrite(led3, 0);
    delay(animationSpeed);
    analogWrite(led5, 159*brightnessScaleVal);
    analogWrite(led6, 191*brightnessScaleVal);
    analogWrite(led4, 0);
    delay(animationSpeed);
    analogWrite(led5, 0);
}

void multiBeamAnimationFlash(){
    float brightnessScaleVal = ledBrightness/255.00;
    for(int del=50;del>0;del--){
        analogWrite(led1, 32*brightnessScaleVal);
        analogWrite(led6, 192*brightnessScaleVal);
        analogWrite(led7, 224*brightnessScaleVal);
        delay(del); 
        analogWrite(led1, 32*brightnessScaleVal);
        analogWrite(led2, 64*brightnessScaleVal);
        analogWrite(led7, 224*brightnessScaleVal);
        analogWrite(led8, 254*brightnessScaleVal);
        analogWrite(led6, 0);
        delay(del);
        analogWrite(led2, 64*brightnessScaleVal);
        analogWrite(led3, 96*brightnessScaleVal);
        analogWrite(led8, 254*brightnessScaleVal);
        analogWrite(led1, 0);
        analogWrite(led7, 0);
        delay(del);
        analogWrite(led3, 96*brightnessScaleVal);
        analogWrite(led4, 128*brightnessScaleVal);
        analogWrite(led2, 0);
        analogWrite(led8, 0);
        delay(del);
        analogWrite(led4, 128*brightnessScaleVal);
        analogWrite(led5, 160*brightnessScaleVal);
        analogWrite(led3, 0);
        delay(del);
        analogWrite(led5, 160*brightnessScaleVal);
        analogWrite(led6, 192*brightnessScaleVal);
        analogWrite(led4, 0);
        delay(del);
        analogWrite(led5, 0);
    }

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(60);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
} 
