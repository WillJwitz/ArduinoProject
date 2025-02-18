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

template <typename T>
class LinkedList{
  private:
    Node<T>* head;
    Node<T>* tail;
    int size;

  public:
    LinkedList();
    ~LinkedList();
    void append(T value);
    Node<T>* getNext(Node<T>* node = nullptr);

};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* current = head;
  while (current) {
    Node<T>* temp = current;
    current = current->next;
    delete temp;
  }
}

template <typename T>
void LinkedList<T>::append(T value) {
  Node<T>* newNode = new Node<T>(value);
  if (!head) {
    head = newNode;
    if (!tail) {
      tail = newNode;
      head->next = newNode;
      tail->next = head;
    }
  }
  else{
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

Node<T>* LinkedList<T>::getNext(Node<T>* node) {
  if (node == nullptr) {
    node = head;
  }
  return node ? node->next : nullptr;
}

