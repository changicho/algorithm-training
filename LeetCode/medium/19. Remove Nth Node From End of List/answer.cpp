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

// two pass : go from head twice

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start->next = head;

    int size = 0;
    ListNode* target = head;
    while (target != NULL) {
      size++;
      target = target->next;
    }

    size -= n;
    target = start;
    for (int i = 0; i < size; i++) {
      target = target->next;
    }
    target->next = target->next->next;

    return start->next;
  }
};

// one pass : go from head once

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = new ListNode();
    start->next = head;

    ListNode* first = start;
    ListNode* second = start;

    for (int i = 0; i < n + 1; i++) {
      first = first->next;
    }

    while (first) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;

    return start->next;
  }
};