#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

template <typename T>
class Menu;

template <typename T>
class Node {
public:
  T data;
  void* obj;
  Node() : obj(nullptr) {}
  Node(const T& val) : data(val), obj(nullptr) {} 
};

template <typename T>
class Menu {
private:
  int size;
  int numI;
  Node<T>* items;
  int index;
  int insert;


public:

  Menu(int s) : size(s), index(0), insert(0), numI(0) {
    items = new Node<T>[s];
  }

  ~Menu() { delete[] items; }

  void append(const T& value) {
    items[insert] = Node<T>(value);
    insert = (insert + 1) % size;
    numI++;
  }

  void next() { index = (index + 1) % numI; }

  void prev() {
    if((index - 1) >= 0){
      index = (index - 1) % numI;
    } 
  }
  
  Node<T>* getItem() { return &items[index]; }


};
#endif
