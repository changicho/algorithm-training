#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

// get length

int getMiddle(Node *head) {
  Node *cur = head;
  int length = 0;

  while (cur != NULL) {
    length += 1;
    cur = cur->next;
  }

  length /= 2;

  cur = head;
  for (int i = 0; i < length; i++) {
    cur = cur->next;
  }

  return cur->data;
}

// rabbit and turtle

int getMiddle(Node *head) {
  Node *turtle = head, *rabbit = head;
  int length = 0;

  while (rabbit != NULL && rabbit->next != NULL) {
    turtle = turtle->next;
    rabbit = rabbit->next->next;
  }

  return turtle->data;
}