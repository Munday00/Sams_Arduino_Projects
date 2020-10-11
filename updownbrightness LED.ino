int ledpin=9, buttonpinup=12, buttonpindown=13, ledstate=0, ledbright;
int buttonupold=0, buttonupnew, buttondownold=0, buttondownnew;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpinup, INPUT);
  pinMode(buttonpindown,INPUT);
}
void loop() {
buttonupnew=digitalRead(buttonpinup);
buttondownnew=digitalRead(buttonpindown);
Serial.println(ledbright);
 if(buttonupold==0&&buttonupnew==1){  //ie when the up brightness button was down and released the loop engages.
  ledbright=(1023./3.)*ledstate;     //3 brightness stages.
  analogWrite(ledpin, ledbright);
  ledstate++;
  if(ledstate>=4){
    ledstate=3;
   }
  }
 buttonupold=buttonupnew;  //important command to ensure light stays on, no other loop will enagage until button is pressed.
 if(buttondownold==0&&buttondownnew==1&&ledstate>=1){ //similar but down loop
  ledstate--;
  ledbright=(1023./3.)*ledstate;
  analogWrite(ledpin, ledbright);
   if(ledstate<=0){
   ledstate=0;
   }
 }buttondownold=buttondownnew;
}
   
  
