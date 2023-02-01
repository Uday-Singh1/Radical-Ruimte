int soundsensor = 2;  //  Here I define the SoundSensor to pin 2 in the Arduino Uno.
int LED = 3;          //  Here I define the LED-Strip to pin 3 in the Arduino Uno.

void setup(){ //  Here I create a setup function.
  pinMode (soundsensor, INPUT); //  I set the value to input because it records the sound.
  pinMode (LED, OUTPUT);        //  I set the value to output because it displays the light.
}

void loop(){  //  Here I create a loop function.
  int statusSensor = digitalRead(soundsensor);  //  The digitalRead reads the current situation at that moment.
  if (statusSensor ==1) { digitalWrite(LED ,HIGH);  //  Checks if the value of 'statusSensor' is equal to 1 and sets the 'LED' pin
                                                    //  to high state (5V) to turn on the connected component if it is.
}

else{ //  If the loop function is not used, this function will go in.
  digitalWrite(LED ,LOW); //  Sets the specified digital pin 'LED' to a low state (0V) which turns off the connected component.
}
