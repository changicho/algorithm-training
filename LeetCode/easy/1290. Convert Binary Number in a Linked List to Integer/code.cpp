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
  int getDecimalValue(ListNode* head) {
    int answer = 0;

    ListNode* cur = head;
    while (cur) {
      answer *= 2;
      answer += cur->val;
      cur = cur->next;
    }
    return answer;
  }
};