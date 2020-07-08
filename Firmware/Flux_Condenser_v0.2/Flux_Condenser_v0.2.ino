int led1 = PA0;
int led2 = PA1;
int led3 = PA2;
int led4 = PA3;
int led5 = PA4;
int led6 = PA5;
int led7 = PA6;
int led8 = PA7;

void setup() {                
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);    
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  delay(50); 
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led6, LOW);
  delay(50);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led7, LOW);
  delay(50);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led8, LOW);
  delay(50);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led3, LOW);
  delay(50);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led4, LOW);
  delay(50);
  digitalWrite(led5, LOW);
}
