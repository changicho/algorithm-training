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

// use reverse & one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  ListNode* reverse(ListNode* node) {
    ListNode* prev = NULL;
    ListNode* cur = node;

    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;

      prev = cur;
      cur = next;
    }

    return prev;
  }

 public:
  ListNode* doubleIt(ListNode* head) {
    head = reverse(head);
    ListNode* dummy = new ListNode();

    dummy->next = head;
    ListNode* cur = dummy->next;
    ListNode* before = dummy;
    int carry = 0;

    while (cur) {
      int val = cur->val * 2 + carry;
      carry = 0;

      if (val >= 10) {
        carry = 1;
        val %= 10;
      }

      cur->val = val;
      before = cur;
      cur = cur->next;
    }

    if (carry > 0) {
      before->next = new ListNode(1);
    }

    return reverse(head);
  }
};