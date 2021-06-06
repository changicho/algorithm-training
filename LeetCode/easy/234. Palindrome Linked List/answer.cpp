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

// use array O(N) space

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    vector<int> array;

    while (head) {
      array.push_back(head->val);
      head = head->next;
    }

    int size = array.size();
    for (int i = 0; i < size / 2; i++) {
      if (array[i] != array[size - 1 - i]) return false;
    }
    return true;
  }
};

// use rabbit and turtle with reverse

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    ListNode* half = slow->next;

    while (half != NULL) {
      if (head->val != half->val) return false;
      head = head->next;
      half = half->next;
    }

    return true;
  }

  ListNode* reverse(ListNode* node) {
    ListNode *pre = NULL, *next = NULL;

    while (node != NULL) {
      next = node->next;
      node->next = pre;
      pre = node;
      node = next;
    }

    return pre;
  }
};