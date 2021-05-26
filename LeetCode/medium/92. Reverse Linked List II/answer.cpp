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

// use array

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode*> array;

    ListNode* dummy = new ListNode(-1, head);
    ListNode* cur = head;

    array.push_back(dummy);
    while (cur) {
      array.push_back(cur);
      cur = cur->next;
    }
    array.push_back(NULL);

    // reverse(array.begin() + left, array.begin() + right + 1);
    int diff = (right - left) + 1;
    for (int i = 0; i < diff / 2; i++) {
      swap(array[left + i], array[right - i]);
    }

    for (int i = left - 1; i <= right; i++) {
      array[i]->next = array[i + 1];
    }

    return array[1];
  }
};

// use one pass

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    ListNode* pre = dummy;
    ListNode* cur;
    dummy->next = head;

    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }
    cur = pre->next;

    for (int i = 0; i < right - left; i++) {
      ListNode* temp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = temp;
    }
    return dummy->next;
  }
};

// use one pass other way

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *pre = dummy, *cur, *next;

    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }
    cur = pre->next;
    next = cur->next;

    for (int i = 0; i < right - left; i++) {
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
      next = cur->next;
    }
    return dummy->next;
  }
};