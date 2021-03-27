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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* answer = new ListNode();
    ListNode* curNode = answer;

    bool carry = false;

    while (l1 || l2 || carry) {
      int cur = 0;

      if (l1) {
        cur += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        cur += l2->val;
        l2 = l2->next;
      }
      if (carry) {
        cur += 1;
        carry = false;
      }

      if (cur >= 10) {
        cur -= 10;
        carry = true;
      }

      ListNode* next = new ListNode(cur);
      curNode->next = next;
      curNode = curNode->next;
    }

    return answer->next;
  }
};