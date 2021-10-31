#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

// use recursive

class Solution {
  void merge(Node* start, Node* end) {
    Node *cur = start, *before;

    while (cur) {
      if (cur->child) {
        // merge child with next
        merge(cur->child, cur->next);
        // merge current with child
        cur->next = cur->child;
        cur->next->prev = cur;
        cur->child = NULL;
      }
      before = cur;
      cur = cur->next;
    }

    before->next = end;
    if (end) end->prev = before;
  }

 public:
  Node* flatten(Node* head) {
    if (!head) return NULL;
    Node* cur = head;

    while (cur) {
      if (cur->child) {
        // merge child with next
        merge(cur->child, cur->next);
        // merge current with child
        cur->next = cur->child;
        cur->next->prev = cur;
        cur->child = NULL;
      }
      cur = cur->next;
    }

    return head;
  }
};

// use recursive short version

class Solution {
 public:
  Node* flatten(Node* head) {
    Node* cur = head;

    while (cur) {
      if (cur->child) {
        Node* next = cur->next;
        Node* child = flatten(cur->child);

        cur->next = child;
        child->prev = cur;
        cur->child = NULL;

        while (child->next) {
          child = child->next;
        }

        child->next = next;
        if (next) next->prev = child;

        cur = child;
      }
      cur = cur->next;
    }

    return head;
  }
};

// use iterate

class Solution {
 public:
  Node* flatten(Node* head) {
    Node* cur = head;

    while (cur) {
      if (cur->child) {
        Node* next = cur->next;
        cur->next = cur->child;
        cur->next->prev = cur;
        cur->child = NULL;

        Node* last = cur->next;
        while (last->next) last = last->next;
        last->next = next;
        if (last->next) last->next->prev = last;
      }

      cur = cur->next;
    }

    return head;
  }
};