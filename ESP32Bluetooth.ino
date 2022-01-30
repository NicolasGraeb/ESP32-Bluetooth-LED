#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
String message="";
char inComingChar;
const int led=13;
void setup() {
  SerialBT.begin("ESP32");
  Serial.println("Connected:");
  pinMode(led,OUTPUT);
Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    char inComingChar=SerialBT.read();
    if(inComingChar !='\n'){
      message+=String(inComingChar);
    }
    else{
      message="";
    }
    Serial.write(inComingChar);
  }
 if(message=="led_on"){
  digitalWrite(led,HIGH);
  
 }
 else if(message=="led_off"){
  digitalWrite(led,LOW);
 }
 delay(20);
 
}
