#include "Menu.h"
#include <Arduino.h>


char SBUFF[32];

Menu::Menu() : currItem(nullptr) {}

void Menu::addItem(const String &item) {
  menu.append(item);
  if (currItem == nullptr){
    currItem = menu.getNext();
  }
}

void Menu::nextItem() {
  if (currItem) {
    currItem = menu.getNext(currItem);
  }
  Serial.begin(9600);
  sprintf(SBUFF, "Got next item: %s", currItem->data.c_str());
  Serial.println(SBUFF);
}

String Menu::Current(){
  return currItem ? currItem->data : "";
}