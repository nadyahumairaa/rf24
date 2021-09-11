#include <RF24Network.h>4
#include <RF24Network_config.h>
#include <Sync.h>

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <Wire.h>

#include <SPI.h>

RF24 radio(9,10); 
RF24Network network(radio);
const uint16_t nomor_kelompok = 05;
const uint16_t base = 000;

float nilaisensor;
struct package{
  float nilai;
  };
  typedef struct package Package;
  Package data;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  radio.begin();
  network.begin(90,01);
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  network.update();
  nilaisensor = 125;
  data.nilai = nilaisensor;
  RF24NetworkHeader header2(baseq);
  bool ok1 = network.write(header2,&data,sizeof(data));
  Serial.print("Nilai :");
  Serial.println(data.nilai);

}
