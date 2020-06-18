#define PULSE_DURATION 1500
#define PHASE_OFFSET 100
byte themeHue;

void setup() {
  randomize();
  NewTheme();

}

void loop() {
  if (buttonDoubleClicked()) NewTheme();

    
  //emission
  FOREACH_FACE(f)
  {
  byte brightness = map((f * PHASE_OFFSET + millis()) % 16, 0, 16, 30, 160);  
  setColorOnFace(makeColorHSB(themeHue, 255, brightness), f);  
  }
  
  //fillament
  setColorOnFace(makeColorHSB(themeHue,255,255), 0);
}

int NewTheme(){
  themeHue = random(50) * 5;
  setColor(makeColorHSB(themeHue, 255, 255));
}
