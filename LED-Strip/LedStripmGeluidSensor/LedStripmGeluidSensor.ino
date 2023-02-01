int soundsensor = 2;
int LED = 3;

void setup(){
  pinMode (soundsensor, INPUT);
  pinMode (LED, OUTPUT);
}

void loop(){
  int statusSensor = digitalRead(soundsensor);
  if (statusSensor ==1) { digitalWrite(LED ,HIGH);
}

else{
  digitalWrite(LED ,LOW);
}
