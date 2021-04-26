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
  bool detectLoop(Node* head) {
    unordered_set<Node*> s;

    while (head) {
      if (s.find(head) != s.end()) return true;

      s.insert(head);
      head = head->next;
    }

    return false;
  }
};

// use count

class Solution {
 public:
  bool detectLoop(Node* head) {
    int count = 20001;

    while (count > 0) {
      count -= 1;
      head = head->next;

      if (head == NULL) return false;
    }

    return true;
  }
};