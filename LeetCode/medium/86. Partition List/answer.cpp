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

// use make answer linked list

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* dummy = new ListNode();
    ListNode* answer = new ListNode();

    dummy->next = head;
    ListNode* cur = dummy;
    ListNode* answerCur = answer;

    while (cur && cur->next) {
      if (cur->next->val < x) {
        answerCur->next = cur->next;
        answerCur = answerCur->next;
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }

    answerCur->next = dummy->next;

    return answer->next;
  }
};