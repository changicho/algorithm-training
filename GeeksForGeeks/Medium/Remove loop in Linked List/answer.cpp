#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// use set

class Solution {
 public:
  void removeLoop(Node* head) {
    unordered_set<Node*> s;

    while (head != NULL) {
      if (s.find(head->next) != s.end()) {
        head->next = NULL;
        return;
      }
      s.insert(head);
      head = head->next;
    }
  }
};

// use floyd

class Solution {
 public:
  void removeLoop(Node* head) {
    if (head->next == NULL) return;
    Node *first = head->next, *second = head->next->next;

    while (first != second) {
      if (second->next == NULL || second->next->next == NULL) return;
      first = first->next;
      second = second->next->next;
    }

    first = head;
    while (first != second) {
      first = first->next;
      second = second->next;
    }

    first = head;
    int count = 0;
    while (true) {
      if (first->next == second) {
        count += 1;
      }
      if (count == 2) break;
      first = first->next;
    }

    first->next = NULL;
  }
};