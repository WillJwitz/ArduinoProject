#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <Arduino.h>

template <typename T>
class Node{
  public:
    T data;
    Node* next

    Node(T value) : data(value), next(nullptr) {}
};

