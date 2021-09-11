#include <RF24Network.h>

#include <RF24.h>

#include <SPI.h>

RF24 radio(9,10); 
RF24Network network(radio);
const uint16_t base00 = 00;

float nilai01;
struct package{
  float nilai;
  };
  typedef struct package Package;
  Package data;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90,00); //chanel,alamat nyalira
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  network.update();
  while(network.available()){
    RF24NetworkHeader header;
    network.read(header,&data,sizeof(data));
    if (header.from_node == 01){
      nilai01 = data.nilai;
    }
  }

  Serial.print("Nilai :");
  Serial.println(nilai01);
  delay(1000);
}
