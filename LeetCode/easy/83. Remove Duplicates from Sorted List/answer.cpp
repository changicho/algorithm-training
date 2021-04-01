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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* answer = new ListNode;
    ListNode* cur = answer;

    int before = -101;
    while (head != NULL) {
      if (head->val != before) {
        before = head->val;

        cur->next = new ListNode(head->val);
        cur = cur->next;
      }
      head = head->next;
    }

    answer = answer->next;
    return answer;
  }
};

// use only head, cur

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL && cur->next != NULL) {
      if (cur->next->val == cur->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }

    return head;
  }
};