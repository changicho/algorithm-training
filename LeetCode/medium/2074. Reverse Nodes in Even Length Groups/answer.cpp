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
// time : O(N)
// space : O(1)
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

// use pointer
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getLength(ListNode* head) {
    int length = 0;
    while (head) {
      head = head->next;
      length++;
    }
    return length;
  }

  void reverse(ListNode* before, int length) {
    ListNode* head = before->next;

    for (int i = 0; i < length - 1 && head->next; i++) {
      ListNode* target = head->next;
      head->next = head->next->next;
      target->next = before->next;
      before->next = target;
    }
  }

 public:
  ListNode* reverseEvenLengthGroups(ListNode* head) {
    int length = getLength(head);

    ListNode* before = new ListNode();
    ListNode* cur = head;
    before->next = cur;

    for (int i = 0, step = 1; i < length; i += step, step++) {
      int curSize = i + step < length ? step : length - i;

      if (curSize % 2 == 0) {
        reverse(before, curSize);

        before = cur;
        cur = cur->next;
      } else {
        for (int j = 0; j < curSize; j++) {
          before = cur;
          cur = cur->next;
        }
      }
    }

    return head;
  }
};