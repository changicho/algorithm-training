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
    int length = 0;
    while (head != NULL) {
      length += 1;
      head = head->next;
    }
    return length;
  }

 public:
  ListNode* rotateRight(ListNode* head, int k) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    dummy->next = head;

    int length = getLength(head);
    if (length < 2) {
      return head;
    }

    k %= length;
    if (k == 0) {
      return head;
    }

    for (int i = 0; i < length - k; i++) {
      cur = cur->next;
    }

    ListNode* after = cur->next;
    ListNode* before = cur;

    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = head;
    before->next = NULL;
    dummy->next = after;

    return dummy->next;
  }
};

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    int size = 0;
    ListNode* first = head;
    ListNode* last = NULL;

    ListNode* cur = head;
    while (cur) {
      size++;
      last = cur;
      cur = cur->next;
    }

    if (k == 0 || size == 0 || k % size == 0) return head;

    int target = size - (k % size);

    cur = head;
    while ((target - 1) > 0) {
      target--;
      cur = cur->next;
    }
    ListNode* newFirst = cur->next;
    cur->next = NULL;
    last->next = first;

    return newFirst;
  }
};