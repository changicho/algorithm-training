#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// use two pointer

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* before;
    ListNode* cur;
    ListNode* dummy = new ListNode();

    dummy->next = head;
    cur = head;
    before = dummy;

    while (cur) {
      if (cur->val == val) {
        before->next = cur->next;

      } else {
        before = before->next;
      }

      cur = cur->next;
    }

    return dummy->next;
  }
};

// use one pointer

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    dummy->next = head;

    while (cur && cur->next) {
      if (cur->next->val == val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return dummy->next;
  }
};
