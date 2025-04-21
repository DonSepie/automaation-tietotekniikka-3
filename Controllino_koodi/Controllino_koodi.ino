#include <controllino.h>
//#include <OneWire.h> //jos joskus tulee DS18B20 lämpötilasensori
//#include <DallasTemperature.h> //jos joskus tulee DS18B20 lämpötilasensori

//#define oneWireBus = 0; //onewire lämpösensori D0   
//OneWire oneWire(oneWireBus); //onewire lämpösensori kommunikointi
//DallasTemperature sensors(&oneWire); //onewire lämpösensori referenssi Dallasille

void setup() {

Serial.begin(9600); // alustetaan sarjaportti (USB) 9600 baudin nopeudelle
//sensors.begin(); //OneWire lämpöä varten initialisointi
}

void loop() {

  int light = lightsensor(); //valosensori CT0013LS
  int moist = moisturesensor(); //kutsutaan kukkaruukkumittari Grove moisture
  int sound = soundsensor(); //kutsutaan äänisensori LM358
  //int temperature = temperaturesensor(); //onewire DS18B20 lämpösensori
  
  String msg = " {\"lightsensor\": " + String(light) + ", " //lisätään valosensorin lukema JSON-stringiin
                  + "\"moisturesensor\": " + String(moist) + ", "    //lisätään joku toinen sensorilukema, näitä rivejä voi tähän lisätä
                  + "\"soundsensor\": " + String(sound) + "}";//lisätään vielä kolmas sensorilukema ja päätetään string

  Serial.println(msg); //kirjoitetaan dataviesti Arduinon USB-porttiin

  delay(1000); // pidetään sekunnin tauko

}

//Aliohjelma valosensorin lukuun
int lightsensor(){

  //luetaan sensorin mittausarvo analogiaportista A0 ja palautetaan se pääohjelmaan
  return analogRead(A0);

}

int moisturesensor() {
  //kytkös A1
  return analogRead(A1);

}

int soundsensor() {
  //kytkös A2
  return analogRead(A2);
  
}

// int temperaturesensor() //suurinpiirtein tällainen koodi onewirelle{
//   //kytkös D0
//   sensors.requestTemperatures();
//   return sensors.getTempCByIndex(0);
  
// }
