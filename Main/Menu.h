#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include "LinkedList.h"

class Menu {
private:
  LinkedList<String> menu;
  Node<String>* currItem;

public:
    Menu();  // Constructor
    void addItem(const String& item); // Function
    void nextItem();
    String Current();

};

#endif
