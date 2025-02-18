#include "Menu.h"
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

Menu menu;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  menu.addItem("HI");
  menu.addItem("I'M");
  menu.addItem("ALIVE");


  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB14_tr);


  u8g2.drawStr(20, 20, "Hello");
  u8g2.sendBuffer();

  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(500);
  u8g2.clearBuffer();
  
  //char sBuff[128];
  
  String out = menu.Current();
  const char* buff = out.c_str();
  

  int width = u8g2.getStrWidth(buff);
  int height = u8g2.getMaxCharHeight();

  int x = (128 - width) / 2; // horiz center
  int y = (64 + height) / 2; // vert center
  /* Serial Debug Statements
  sprintf(sBuff, "H: %d", u8g2.getBufferTileHeight());
  Serial.println(sBuff);
  sprintf(sBuff, "W: %d", u8g2.getBufferTileWidth());
  Serial.println(sBuff);
  */
  u8g2.drawStr(x, y, buff);
  u8g2.sendBuffer();
  menu.nextItem();
}
