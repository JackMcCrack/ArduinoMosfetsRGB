// Arduino code to control and RGB LED strip
// Uses a toggle switch to switch between color-fade mode
// and individual RGB control mode
// adapted from http://learn.adafruit.com/rgb-led-strips/example-code

const int RED = 9;    // define digital output pins for individual red,
const int GREEN = 10;  //green and blue channels
const int BLUE = 11;


int FADESPEED = 0;  // initiate fade speed set by potentiometer

int r = 0;  // initialize the red, green and blue values

int g = 0;

int b = 0;

void setup() {
  pinMode(RED,   OUTPUT);    // define digital pins as outputs and inputs as needed
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE,  OUTPUT);

}

void loop() {
  int r_new = random(13) + 1;
  int g_new = random(7) + 1;
  int b_new = random(9) + 1;

  for (int i = 10000; i > 0; i--) {
    if (i % r_new != 0) {
      pinon(RED);
    } else {
      pinoff(RED);
    }

    if (i % g_new == 0) {
      pinon(GREEN);
    } else {
      pinoff(GREEN);
    }

    if (i % b_new == 0) {
      pinon(BLUE);
    } else {
      pinoff(BLUE);
    }
    delay(.5);
  }
  delay(1);
}





void pinon(int pin) {
  digitalWrite(pin, HIGH);
}
void pinoff(int pin) {
  digitalWrite(pin, LOW);
}
