int speedpin=5, dir1=4, dir2=3;
int mdir; 
double mspeed;
int vrx=A0;//vrx is the x direction of the joystick.

void setup() {
 pinMode(speedpin, OUTPUT);
 pinMode(dir1,OUTPUT);
 pinMode(dir2,OUTPUT);
 pinMode(vrx, INPUT);
 Serial.begin(9600);
}

void loop() {
 mdir=analogRead(vrx);
 Serial.println(mdir);
 if(mdir>=515){ //at undisturbed position 1023/2~512 motor will stay stationary, therefore we programme either direction to control dir and speed
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  mspeed=(255./508)*mdir-259;
  analogWrite(speedpin, mspeed);
  }
 if(mdir<=510){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  mspeed=(-255./510)*mdir+255;
  analogWrite(speedpin, mspeed);
 }
}
