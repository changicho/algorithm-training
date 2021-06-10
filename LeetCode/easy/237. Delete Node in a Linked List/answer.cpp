#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// use rewrite

class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

// use shift

class Solution {
 public:
  void deleteNode(ListNode* node) {
    while (node->next->next) {
      node->val = node->next->val;
      node = node->next;
    }
    node->val = node->next->val;
    node->next = NULL;
  }
};