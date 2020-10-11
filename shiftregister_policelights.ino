
int latchpin=11, clockpin=9, datapin=12;
byte leds1=0x0F;
byte leds2=0xF0;
byte leds3=0xFF;
void setup() {
 pinMode(latchpin,OUTPUT);
 pinMode(clockpin,OUTPUT);
 pinMode(datapin,OUTPUT);
}

void loop() {

 digitalWrite(latchpin,LOW);
 shiftOut(datapin,clockpin,LSBFIRST,leds1);//causes led sets to flash like police lights, can be easily maniupulated to form binary counter using one byte leds and instructing an increment on each loop
 digitalWrite(latchpin,HIGH);
 delay(150);

 
 digitalWrite(latchpin,LOW);
 shiftOut(datapin,clockpin,LSBFIRST,leds2);
 digitalWrite(latchpin,HIGH);
 delay(150);
}
