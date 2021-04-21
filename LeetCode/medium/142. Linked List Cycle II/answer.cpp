#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    bool hasCycle = false;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) {
        hasCycle = true;
        break;
      }
    }

    if (hasCycle) {
      slow = head;
      while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
      }
      return fast;
    }
    return NULL;
  }
};