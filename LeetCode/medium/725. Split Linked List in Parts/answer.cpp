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

// use length check and split
// time : O(N)
// space : O(K)
class Solution {
 private:
  int getLength(ListNode* node) {
    int length = 0;
    while (node) {
      length++;
      node = node->next;
    }
    return length;
  }

 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> answer(k);

    int length = getLength(head);

    int mods = length % k;
    int remain = length / k;

    ListNode* cur = head;
    ListNode* before = NULL;
    for (int i = 0; i < k; i++) {
      answer[i] = cur;

      int size = remain + (mods > 0);
      mods--;

      while (size--) {
        before = cur;
        if (cur) cur = cur->next;
      }

      if (before) before->next = NULL;
    }
    return answer;
  }
};