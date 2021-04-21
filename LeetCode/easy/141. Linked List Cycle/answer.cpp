#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// use set

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    set<ListNode *> s;
    ListNode *cur = head;
    bool answer = false;

    while (cur) {
      if (s.find(cur) != s.end()) {
        answer = true;
        break;
      }
      s.insert(cur);
      cur = cur->next;
    }

    return answer;
  }
};

// use max size

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    int count = 20001;
    while (count--) {
      if (head == NULL) {
        return false;
      }
      head = head->next;
    }

    return true;
  }
};

// floyd cycle detection algorithm

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        return true;
      }
    }

    return false;
  }
};
