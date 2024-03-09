#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  string gameResult(ListNode *head) {
    int even = 0, odd = 0;

    ListNode *cur = head;
    while (cur) {
      ListNode *first = cur;
      cur = cur->next;
      ListNode *second = cur;
      cur = cur->next;

      if (first->val > second->val) {
        even++;
      } else if (first->val < second->val) {
        odd++;
      }
    }

    if (even < odd)
      return "Odd";
    else if (even > odd)
      return "Even";
    else
      return "Tie";
  }
};