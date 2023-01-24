Touch led sensor code RAW: #include <FastLED.h>
#define ctsPin 2 
#define LED_PIN     5
#define NUM_LEDS    500
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define TOUCH_SENSOR 2
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

//CRGBPalette16 currentPalette;
//TBlendType    currentBlending;

//extern CRGBPalette16 myRedWhiteBluePalette;
//extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

     Serial.begin(9600);
       pinMode(NUM_LEDS, OUTPUT);
       pinMode(TOUCH_SENSOR, INPUT);


}
void loop() {


    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */



    FastLED.delay(3000 / UPDATES_PER_SECOND);
      int ctsValue = digitalRead(ctsPin);

      if (ctsValue == HIGH) {
           //digitalWrite(LED_PIN, HIGH);
           Serial.println("TOUCHED");
               for( int i = 0; i < NUM_LEDS; i++) {
                leds[i] = CRGB:: Green;
               }
               FastLED.show();
     }
     else
        {
             Serial.println("not touched");
             for( int i = 0; i < NUM_LEDS; i++) {
                leds[i] = CRGB:: Black;
               }
               FastLED.show(); 
          }
      delay(0.9);
}
