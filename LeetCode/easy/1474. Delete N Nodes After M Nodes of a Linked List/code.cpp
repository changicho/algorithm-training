#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
  ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* cur = head;

    while (cur) {
      for (int i = 0; i < m - 1 && cur; i++) {
        cur = cur->next;
      }
      if (!cur) break;

      ListNode* before = cur;
      cur = cur->next;
      for (int i = 0; i < n && cur; i++) {
        cur = cur->next;
      }
      before->next = cur;
      if (!cur) break;
    }
    return dummy->next;
  }
};