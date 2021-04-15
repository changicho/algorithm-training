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

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* cur = head;
    ListNode* dummy = new ListNode();
    ListNode* before = dummy;
    dummy->next = head;

    while (cur && cur->next) {
      ListNode* first = cur;
      ListNode* second = cur->next;

      first->next = second->next;
      before->next = second;
      second->next = first;

      before = first;

      cur = cur->next;
    }

    return dummy->next;
  }
};

// use size

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* cur = head;
    ListNode* dummy = new ListNode();
    ListNode* before = dummy;
    dummy->next = head;

    int size = 2;
    while (cur) {
      vector<ListNode*> v;
      for (int i = 0; i < size; i++) {
        v.push_back(cur);
        cur = cur->next;

        if (!cur) break;
      }

      if (v.size() != size) break;

      v.front()->next = v.back()->next;
      before->next = v.back();

      for (int i = size - 1; i >= 1; i--) {
        v[i]->next = v[i - 1];
      }

      before = v.front();
    }

    return dummy->next;
  }
};