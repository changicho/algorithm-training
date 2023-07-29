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

// use reverse linked list
// time : O(N + M)
// space : O(N + M)
class Solution {
 private:
  ListNode* reverse(ListNode* node) {
    ListNode* prev = NULL;

    while (node) {
      ListNode* next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }

    // return tail. tail is prev
    return prev;
  }

 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1), l2 = reverse(l2);

    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;

    int carry = 0;
    while (l1 || l2 || carry > 0) {
      int val = 0;
      if (l1) {
        val += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        val += l2->val;
        l2 = l2->next;
      }
      val += carry;

      if (val >= 10) {
        carry = 1;
        val %= 10;
      } else {
        carry = 0;
      }
      ListNode* node = new ListNode(val);

      cur->next = node;
      cur = cur->next;
    }

    return reverse(dummy->next);
  }
};
