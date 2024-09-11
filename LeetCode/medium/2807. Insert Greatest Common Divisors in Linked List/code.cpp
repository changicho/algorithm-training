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
// space : O(N)
class Solution {
 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* before = head;

    ListNode* cur = head->next;

    while (cur) {
      int val = gcd(cur->val, before->val);
      before->next = new ListNode(val, cur);

      before = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};