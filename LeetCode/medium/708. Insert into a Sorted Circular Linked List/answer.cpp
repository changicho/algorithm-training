#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

// use iteration
// time : O(N)
// space : O(1)
class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    Node* node = new Node(insertVal);

    // Edge case
    if (!head) {
      node->next = node;
      return node;
    }

    int minimum = head->val;
    int maximum = head->val;

    Node* cur = head;
    cur = cur->next;
    // O(N)
    while (cur != head) {
      minimum = min(minimum, cur->val);
      maximum = max(maximum, cur->val);
      cur = cur->next;
    }
    // out of range case
    if (insertVal < minimum || maximum < insertVal) {
      // can insert any position case
      if (minimum == maximum) {
        node->next = head->next;
        head->next = node;

        return head;
      }

      // find last maximum node
      cur = head;
      while (cur->val <= cur->next->val) {
        cur = cur->next;
      }

      node->next = cur->next;
      cur->next = node;

      return head;
    }

    // find position to insert
    cur = head;
    while (true) {
      if (cur->val <= insertVal && insertVal <= cur->next->val) {
        break;
      }

      cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

    return head;
  }
};

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    Node* node = new Node(insertVal);

    if (!head) {
      node->next = node;
      return node;
    }

    Node* prev = head;
    Node* next = head->next;
    bool inserted = false;

    while (true) {
      bool isCenter = (prev->val <= insertVal && insertVal <= next->val);
      bool isLower = (prev->val > next->val && insertVal < next->val);
      bool isUpper = (prev->val > next->val && insertVal > prev->val);

      if (isCenter || isLower || isUpper) {
        prev->next = new Node(insertVal, next);
        inserted = true;
        break;
      }

      prev = prev->next;
      next = next->next;

      if (prev == head) break;
    }

    if (!inserted) {
      prev->next = new Node(insertVal, next);
    }

    return head;
  }
};
