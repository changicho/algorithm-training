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

// use one pass
// time : O(N + M)
// space : O(1)
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* dummy = new ListNode();
    dummy->next = list1;

    ListNode* cur = dummy;
    ListNode *left = NULL, *right = NULL;
    int i = 0;
    while (cur) {
      if (i == a) {
        left = cur;
      } else if (i == b + 1) {
        right = cur;
      }

      cur = cur->next;
      i++;
    }

    left->next = list2;
    cur = list2;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = right->next;

    return dummy->next;
  }
};