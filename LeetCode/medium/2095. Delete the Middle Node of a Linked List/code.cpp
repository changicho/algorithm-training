#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getLength(ListNode* head) {
    ListNode* cur = head;

    int ret = 0;
    while (cur) {
      ret++;
      cur = cur->next;
    }
    return ret;
  }

 public:
  ListNode* deleteMiddle(ListNode* head) {
    int size = getLength(head);
    if (size == 1) return NULL;
    ListNode* cur = head;
    for (int i = 0; i < size / 2 - 1; i++) {
      cur = cur->next;
    }

    cur->next = cur->next->next;

    return head;
  }
};