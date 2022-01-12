// RAMPS CONTROLLER
// e.g. https://www.banggood.com/custlink/mGvd428bCG
// Pinout: https://reprap.org/mediawiki/images/thumb/c/ca/Arduinomega1-4connectors.png/800px-Arduinomega1-4connectors.png

// DEFINES
// Button definitions retrieved from Marlin pins.h
#define KILL_PIN 41 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_RS 16 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_ENABLE 17 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_D4 23 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_D5 25 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_D6 27 //[RAMPS14-SMART-ADAPTER]  
#define LCD_PINS_D7 29 //[RAMPS14-SMART-ADAPTER]  
#define BTN_EN1 31 //[RAMPS14-SMART-ADAPTER]  
#define BTN_EN2 33 //[RAMPS14-SMART-ADAPTER]  
#define BTN_ENC 35 //[RAMPS14-SMART-ADAPTER]  
#define BEEPER 37 //[RAMPS14-SMART-ADAPTER] / 37 = enabled; -1 = disabled / (if you don't like the beep sound ;-)
#define SDCARDDETECT 49 //[RAMPS14-SMART-ADAPTER]
#define SDSS               53
#define LED_PIN            13

// INCLUDES
// 20x04 character LCD display
#include <LiquidCrystal.h>
// Rotary encoder
#include <Encoder.h>
// Debouncing buttons and other inputs
#include <Bounce2.h>

// GLOBALS
// initialize the library by associating any needed LCD interface pin
LiquidCrystal lcd(LCD_PINS_RS, LCD_PINS_ENABLE, LCD_PINS_D4, LCD_PINS_D5, LCD_PINS_D6, LCD_PINS_D7);
// Create a char array to store the contents of the LCD screen
char displayBuffer[4][20];
// Encoder object
Encoder encoder(BTN_EN2, BTN_EN1);
long lastEncoderPosition  = -999;
long currentEncoderPosition;
// encButton is when encoder button (LS1) is pushed in
Bounce2::Button encButton = Bounce2::Button();
// button is the small black button (K1)
Bounce2::Button button = Bounce2::Button();

void updateDisplay() {
  for(int i=0; i<4; i++) {
    lcd.setCursor(0,i);
    lcd.print(displayBuffer[i]);
  }
}

// Display a string on LCD screen and via serial connection
// Scrolls existing output up one line
void logMessage(char* message){
  for(int i=2; i<3; i++){
    strncpy(displayBuffer[i], displayBuffer[i+1], sizeof(displayBuffer[i]));
  }
  // Note use of right-padding to fill whole line
  snprintf(displayBuffer[3], sizeof(displayBuffer[3]), "%-20s", message);
  Serial.println(message);
  updateDisplay();
}

// Display a PROGMEM string on LCD screen and via serial connection
void logMessage(const __FlashStringHelper* message){
  for(int i=2; i<3; i++){
    strncpy(displayBuffer[i], displayBuffer[i+1], sizeof(displayBuffer[i]));
  }
  // Note use of right-padding to fill whole line
  snprintf_P(displayBuffer[3], sizeof(displayBuffer[3]), PSTR("%-20S") , message);
  Serial.println(message);
  updateDisplay();
}

void setup() {
  // Start serial connection  
  Serial.begin(115200);
  // Print some welcome information
  Serial.println(__FILE__ __DATE__);

  // Start the LCD display with specified columns and rows
  lcd.begin(20, 4);
  
  // Print a message to the LCD
  sprintf(displayBuffer[0], "%-16s %3s", "RAMPS Display", "1.0");
  sprintf(displayBuffer[1], "Encoder: %-7d", currentEncoderPosition>>2);  
  updateDisplay();
   
  // Initialise the input pins that have switches attached
  encButton.attach(BTN_ENC, INPUT_PULLUP);
  button.attach(KILL_PIN, INPUT_PULLUP);

  logMessage(F("Done"));  
}

void loop() {
  // INPUTS
  button.update();
  encButton.update();
  // Read rotary encoder input
  currentEncoderPosition = encoder.read();
  // If it's changed, output new value
  if (currentEncoderPosition != lastEncoderPosition) {
    lastEncoderPosition = currentEncoderPosition;
    // This updates the whole display, but causes encoder read to lag
    // sprintf(displayBuffer[1], "Encoder: %-7d", currentEncoderPosition>>2); 
    // updateDisplay();
    // So, we'll just update the section of the display that shows the encoder output
    char encValue[4];
    // Convert signed long value to string and right-pad with spaces
    // (to ensure any leftover characters from previous readings are blanked)
    snprintf(encValue, 4, "%-4ld", currentEncoderPosition>>2);
    strncpy(displayBuffer[1,9], encValue, 4);
    lcd.setCursor(9,1);
    lcd.print(encValue);
  }

  if(encButton.pressed()) {
    logMessage(F("encButton Pressed"));
    delay(100);
  }
  if(button.pressed()) {
    logMessage(F("button Pressed"));
    digitalWrite(BEEPER, HIGH);
    delay(100);
    digitalWrite(BEEPER, LOW);
  }
}
