#include <algorithm>
#include <climits>
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
// space : O(1)
class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int minimum = INT_MAX, maximum = INT_MIN;

    int beforeI = -1;
    int firstI = -1;
    int i = 1;
    ListNode *cur = head->next, *before = head;

    while (cur->next) {
      cur = cur->next;

      int left = before->val;
      int target = before->next->val;
      int right = cur->val;

      if (left < target && target > right || left > target && target < right) {
        if (beforeI != -1) {
          minimum = min(minimum, i - beforeI);
        }
        if (firstI != -1) {
          maximum = max(maximum, i - firstI);
        }

        if (firstI == -1) firstI = i;
        beforeI = i;
      }

      i++;
      before = before->next;
    }

    if (minimum == INT_MAX || maximum == INT_MIN) {
      return {-1, -1};
    }
    return {minimum, maximum};
  }
};