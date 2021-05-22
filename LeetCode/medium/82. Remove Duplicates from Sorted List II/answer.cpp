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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode;
    ListNode* before;
    ListNode* cur = head;

    dummy->next = head;
    before = dummy;
    while (cur) {
      if (cur->next && cur->val == cur->next->val) {
        while (cur->next && cur->val == cur->next->val) {
          cur = cur->next;
        }

        before->next = cur->next;
      } else {
        before = before->next;
      }

      cur = cur->next;
    }

    return dummy->next;
  }
};