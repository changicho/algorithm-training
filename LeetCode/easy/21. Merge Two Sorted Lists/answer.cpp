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

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ret = new ListNode(0);
    ListNode* cur = ret;

    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    if (l1 != NULL) {
      cur->next = l1;
    } else {
      cur->next = l2;
    }

    ret = ret->next;
    return ret;
  }
};

// use recursive

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (b == NULL) {
      return a;
    }
    if (a == NULL || (a->val > b->val)) {
      swap(a, b);
    }

    a->next = mergeTwoLists(a->next, b);
    return a;
  }
};