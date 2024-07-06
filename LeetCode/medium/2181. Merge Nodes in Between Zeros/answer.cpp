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
// time : O(N)
// space : O(N)
class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode();
    ListNode* dummyCur = dummy;
    ListNode* cur = head;
    int sum = 0;

    while (cur) {
      if (cur->val != 0) {
        sum += cur->val;
      } else if (sum > 0) {
        dummyCur->next = new ListNode(sum);
        sum = 0;
        dummyCur = dummyCur->next;
      }

      cur = cur->next;
    }

    return dummy->next;
  }
};