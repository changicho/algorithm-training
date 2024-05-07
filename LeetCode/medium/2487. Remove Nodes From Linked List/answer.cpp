#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
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

// use monotonic stack
// time : O(N)
// space : O(N)
class Solution {
 public:
  ListNode* removeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(INT_MAX);
    dummy->next = head;
    ListNode* before = dummy;
    ListNode* cur = dummy->next;

    stack<ListNode*> stk;
    stk.push(dummy);

    while (cur) {
      while (stk.top()->val < cur->val) {
        stk.pop();
      }

      stk.top()->next = cur;
      stk.push(cur);
      cur = cur->next;
    }
    return dummy->next;
  }
};

// use reverse two pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    return prev;
  }

 public:
  ListNode* removeNodes(ListNode* head) {
    head = reverse(head);

    int maximum = 0;
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur) {
      maximum = max(maximum, cur->val);

      if (cur->val < maximum) {
        prev->next = cur->next;
        cur = cur->next;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }

    return reverse(head);
  }
};