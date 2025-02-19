#include "Menu.h"
#include <U8g2lib.h>
#include <BasicEncoder.h>

#define RECLK 2  // rotary encoder clk pin
#define REDT 3  // data/direction rotary encoder pin
#define RESW 4  // reotary encoder switch

// init screen object
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

BasicEncoder encoder(RECLK, REDT);

Menu<String> menu(6);  // init menu object with 6 items

int lastStateCLK;
int currentStateCLK;
bool rotating = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // initiallize Serial terminal
  
  u8g2.begin();  // start screen
  u8g2.clearBuffer();  // clear screen buffer
  u8g2.setFont(u8g2_font_ncenB14_tr);  // set print out font

  
  // Setting up menu items for example
  menu.append("HI");
  menu.append("I'm");
  menu.append("ALIVE");

  //Opening message
  u8g2.drawStr(20, 20, "Hello");
  u8g2.sendBuffer();
  
  //Delay before starting loop
  delay(2000);

  u8g2.clearBuffer();  //clear buffer
  const char* buff = menu.getItem()->data.c_str();  // get string 
  
  int width = u8g2.getStrWidth(buff);  // get width
  int height = u8g2.getMaxCharHeight();  // get height

  // centering calculations
  int x = (128 - width) / 2; // horiz center
  int y = (64 + height) / 2; // vert center

  // draw
  u8g2.drawStr(x, y, buff);
  u8g2.sendBuffer();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

  encoder.service();
  int encoder_change = encoder.get_change();

  
  // If state changes, determine direction
  if (encoder_change) {
    if (encoder_change == -1) {
      Serial.println("Rotated Left");
      
      menu.prev();  // left - getprev
      //Change screen
      u8g2.clearBuffer();  //clear buffer
      const char* buff = menu.getItem()->data.c_str();  // get string 
  
      int width = u8g2.getStrWidth(buff);  // get width
      int height = u8g2.getMaxCharHeight();  // get height

      // centering calculations
      int x = (128 - width) / 2; // horiz center
      int y = (64 + height) / 2; // vert center

      // draw
      u8g2.drawStr(x, y, buff);
      u8g2.sendBuffer();
      delay(50);
    } else {
        Serial.println("Rotated right");

        menu.next();  // right-getnext
        //Change screen
        u8g2.clearBuffer();  //clear buffer
        const char* buff = menu.getItem()->data.c_str();  // get string 
  
        int width = u8g2.getStrWidth(buff);  // get width
        int height = u8g2.getMaxCharHeight();  // get height

        // centering calculations
        int x = (128 - width) / 2; // horiz center
        int y = (64 + height) / 2; // vert center

        //draw
        u8g2.drawStr(x, y, buff);
        u8g2.sendBuffer();
        delay(50);
    }
  }


  /*
  if (digitalRead(RESW) == LOW) {
    Serial.println("Button Pressed");
    delay(200); // Debounce delay
  }
  */
}
