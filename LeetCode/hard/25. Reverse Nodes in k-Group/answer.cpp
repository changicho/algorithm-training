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

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode* before = dummy;
    ListNode* cur = head;

    vector<ListNode*> v(k);
    while (cur) {
      int count = 0;
      for (int i = 0; i < k; i++) {
        v[i] = cur;
        count += 1;
        cur = cur->next;

        if (!cur) break;
      }

      if (count != k) break;

      v.front()->next = v.back()->next;
      before->next = v.back();

      for (int i = k - 1; i >= 1; i--) {
        v[i]->next = v[i - 1];
      }

      before = v.front();
    }

    return dummy->next;
  }
};

// only iterator

class Solution {
 public:
  int getLength(ListNode* head) {
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    return length;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode();
    ListNode* before = dummy;
    ListNode* cur = head;
    dummy->next = head;

    int count = getLength(head) / k;
    for (int i = 0; i < count; i++) {
      for (int j = 1; j < k; j++) {
        ListNode* temp = before->next;
        before->next = cur->next;
        cur->next = cur->next->next;
        before->next->next = temp;
      }
      before = cur;
      cur = cur->next;
    }

    return dummy->next;
  }
};
