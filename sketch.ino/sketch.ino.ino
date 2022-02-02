#include <SoftwareSerial.h>

#define second 1000

SoftwareSerial BTserial(10, 11); // RX , TX

class BluetoothDevice {
  public:  
  BluetoothDevice(){
    BTserial.begin(9600);
  }
  void Send(int data){
    BTserial.print("1234");

    BTserial.print(",");

    BTserial.print("1234.0");

    BTserial.print(",");

    BTserial.print("1234 hPa");

    BTserial.print(",");

    BTserial.print("500 ml/s");

    BTserial.print(",");

    BTserial.print(data);

    BTserial.print(";");
  }
};

BluetoothDevice Device;

int soilSensorPin = A0;
int soilSensorValue;
int limit = 300;

void setup(){
  Serial.begin(9600);
  Device = BluetoothDevice();
}

void loop(){
  for(int i = 0;i <= 100;i++){
    soilSensorValue = soilSensorValue + analogRead(soilSensorPin);
    delay(1);
  }
  soilSensorValue = soilSensorValue/100;
  Device.Send(soilSensorValue);
  delay(5*second);
}
