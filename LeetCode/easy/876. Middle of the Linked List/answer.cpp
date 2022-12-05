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

// use length check
// time : O(N)
// space : O(1)
class Solution {
 private:
  int getLength(ListNode* head) {
    ListNode* node = head;

    int length = 0;
    while (node) {
      node = node->next;
      length++;
    }
    return length;
  }

 public:
  ListNode* middleNode(ListNode* head) {
    int length = getLength(head);

    ListNode* node = head;
    for (int i = 0; i < length / 2; i++) {
      node = node->next;
    }
    return node;
  }
};

// use turtle & rabbit
// time : O(N)
// space : O(1)
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *fast = head, *slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }
};