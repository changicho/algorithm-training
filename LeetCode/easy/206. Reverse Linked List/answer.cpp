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

// use one pass

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode *befoe = dummy, *target = head;

    while (target) {
      ListNode* temp = target->next;
      target->next = dummy->next;
      dummy->next = target;
      head->next = temp;
      target = temp;
    }

    return dummy->next;
  }
};