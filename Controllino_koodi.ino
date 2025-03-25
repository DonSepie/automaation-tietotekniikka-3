void setup() {

Serial.begin(9600); // alustetaan sarjaportti (USB) 9600 baudin nopeudelle

}

void loop() {

  int light = lightsensor(); //kutsutaan aliohjelmaa, joka lukee valosensorin
  int s2 = sensor2(); //kutsutaan sensori 2
  int s3 = sensor3(); //kutsutaan sensori 3
  
  String msg = " {\"lightsensor\": " + String(light) + ", " //lisätään valosensorin lukema JSON-stringiin
                  + "\"sensor2\": " + String(s2) + ", "    //lisätään joku toinen sensorilukema, näitä rivejä voi tähän lisätä
                  + "\"sensor3\": " + String(s3) + "}";//lisätään vielä kolmas sensorilukema ja päätetään string

  Serial.println(msg); //kirjoitetaan dataviesti Arduinon USB-porttiin

  delay(1000); // pidetään sekunnin tauko

}

//Aliohjelma valosensorin lukuun
int lightsensor(){

  //luetaan sensorin mittausarvo analogiaportista A0 ja palautetaan se pääohjelmaan
  return analogRead(A0);

}

int sensor2() {

  return 123;

}

int sensor3() {

  return 234;
  
}
