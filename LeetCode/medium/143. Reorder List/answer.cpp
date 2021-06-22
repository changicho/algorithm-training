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

// use one pass space complexity : O(N)

class Solution {
 public:
  void reorderList(ListNode* head) {
    vector<ListNode*> array;

    ListNode* cur = head;
    ListNode* dummy;

    while (cur) {
      array.push_back(cur);
      cur = cur->next;
    }

    int size = array.size();
    for (int i = 0; i < size / 2; i++) {
      array[i]->next = array[size - 1 - i];
      array[size - 1 - i]->next = i + 1 < size / 2 ? array[i + 1] : NULL;
    }
    if (size % 2 == 1 && size > 1) {
      array[size / 2 + 1]->next = array[size / 2];
      array[size / 2]->next = NULL;
    }

    head = array[0];
  }
};

// use half reverse and reorder

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* middle = slow;
    ListNode* cur = slow->next;
    while (cur->next != NULL) {
      ListNode* temp = cur->next;
      cur->next = temp->next;
      temp->next = middle->next;
      middle->next = temp;
    }

    slow = head;
    fast = middle->next;
    while (slow != middle) {
      middle->next = fast->next;
      fast->next = slow->next;
      slow->next = fast;
      slow = fast->next;
      fast = middle->next;
    }
  }
};