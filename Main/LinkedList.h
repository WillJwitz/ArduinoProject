#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <Arduino.h>

template <typename T>
class Node{
  public:
    T data;
    Node* next;

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
  if (!head) return;
  
  Node<T>* current = head;
  do {
    Node<T>* nextNode = current->next;
    delete current;
    current = nextNode;
  }while (current != head);
}

template <typename T>
void LinkedList<T>::append(T value) {
  Node<T>* newNode = new Node<T>(value);
  if (!head) {
    head = newNode;
    tail = newNode;
    newNode->next = head;
  }
  else{
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

template <typename T>
Node<T>* LinkedList<T>::getNext(Node<T>* node) {
  if(!head) return nullptr;
  if (node == nullptr) return head;
  
  return node->next;
}

#endif