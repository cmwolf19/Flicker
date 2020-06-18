#define PHASE_MULTIPLIER 128
#define PULSE_DURATION 2048
#define BRIGHTNESS_MIN 80
#define BRIGHTNESS_MAX 200
byte themeHue;

void setup() {
  randomize();
  NewTheme();

}

void loop() {
  if (buttonDoubleClicked()) NewTheme();

  for (int f = 1; f != 6; f++) 
  {
    int pulseProgress = (millis()+ f*PHASE_MULTIPLIER) % PULSE_DURATION;
    int sinPulse = sin8_C(2*3.14*pulseProgress/PULSE_DURATION);
    byte pulseMapped = (BRIGHTNESS_MAX+BRIGHTNESS_MIN)/2 + (BRIGHTNESS_MAX-BRIGHTNESS_MIN)*sinPulse/2;
    setColorOnFace(makeColorHSB(themeHue, 255, pulseMapped), f);
  }

  /*//emission
  FOREACH_FACE(f)
  {
  byte brightness = map((f * PHASE_OFFSET + millis()) % 16, 0, 16, 30, 160);  
  setColorOnFace(makeColorHSB(themeHue, 255, brightness), f);  
  }
  */
  
  //fillament
  setColorOnFace(makeColorHSB(themeHue,128,255), 0);
}

void NewTheme(){
  themeHue = random(50) * 5;
  setColor(makeColorHSB(themeHue, 255, 255));
}
