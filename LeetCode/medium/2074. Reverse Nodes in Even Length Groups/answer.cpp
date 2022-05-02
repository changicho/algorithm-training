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

// use vector
// time : O(N)
// space : O(N)
class Solution {
 public:
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    ListNode* cur = head;

    vector<int> arr;
    while (cur) {
      arr.push_back(cur->val);

      cur = cur->next;
    }

    int size = arr.size();
    for (int i = 0, step = 1; i < size; i += step, step++) {
      int curSize = i + step < size ? step : size - i;
      if (curSize % 2 == 0) {
        reverse(arr.begin() + i, arr.begin() + i + curSize);
      }
    }

    ListNode* dummy = new ListNode();
    cur = dummy;
    for (int& num : arr) {
      cur->next = new ListNode(num);
      cur = cur->next;
    }

    return dummy->next;
  }
};

// use pointer

class Solution {
 private:
  ListNode* reverseList(ListNode* cur, int n) {
    ListNode *start = cur, *before = NULL;

    while (--n >= 0) {
      swap(cur->next, before);
      if (--n >= 0) swap(before->next, cur);
    }

    start->next = cur;
    return before;
  }

 public:
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    int group = 2, cnt = 0;
    ListNode *start = head, *cur = head->next;

    while (cur) {
      if (++cnt == group) {
        if (group % 2 == 0) {
          cur = start->next;
          start->next = reverseList(start->next, cnt);
        }
        start = cur;
        cnt = 0;
        group++;
      }
      cur = cur->next;
    }
    if (cnt % 2 == 0 && start->next) {
      start->next = reverseList(start->next, cnt);
    }

    return head;
  }
};