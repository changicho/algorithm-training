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

// use two pointer
// time : O(L)
// space : O(1)
class Solution {
 private:
  int getLength(ListNode* head) {
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    return length;
  }

 public:
  ListNode* swapNodes(ListNode* head, int k) {
    int length = getLength(head);

    ListNode *from = head, *to = head;

    for (int i = 0; i < k - 1; i++) {
      from = from->next;
    }
    for (int i = 0; i < length - 1 - (k - 1); i++) {
      to = to->next;
    }

    swap(from->val, to->val);
    return head;
  }
};