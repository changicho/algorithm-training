#include <algorithm>
#include <iostream>
#include <string>
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

class Solution {
 public:
  Node* rotate(Node* head, int k) {
    Node* cur = head;
    Node* dummy = new Node(-1);
    Node* before = dummy;

    dummy->next = head;

    for (int i = 0; i < k; i++) {
      before = before->next;
    }
    if (before->next == NULL) return head;

    cur = before->next;
    before->next = NULL;
    dummy->next = cur;

    while (cur != NULL && cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = head;

    return dummy->next;
  }
};
