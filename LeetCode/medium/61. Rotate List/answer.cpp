#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    dummy->next = head;

    int length = getLength(head);
    if (length < 2) {
      return head;
    }

    k %= length;
    if (k == 0) {
      return head;
    }

    for (int i = 0; i < length - k; i++) {
      cur = cur->next;
    }

    ListNode *after = cur->next;
    ListNode *before = cur;

    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = head;
    before->next = NULL;
    dummy->next = after;

    return dummy->next;
  }

  int getLength(ListNode *head) {
    int length = 0;
    while (head != NULL) {
      length += 1;
      head = head->next;
    }
    return length;
  }
};