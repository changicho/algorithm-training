#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int, int> counts;

    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode *before = dummy, *cur = dummy->next;

    while (cur) {
      counts[cur->val]++;
      cur = cur->next;
    }

    cur = dummy->next;

    while (cur) {
      if (counts[cur->val] >= 2) {
        before->next = cur->next;
        cur = cur->next;
        continue;
      }

      cur = cur->next;
      before = before->next;
    }

    return dummy->next;
  }
};