#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> s;

    ListNode *cur = headA;

    while (cur != NULL) {
      s.insert(cur);
      cur = cur->next;
    }

    cur = headB;

    while (cur != NULL) {
      if (s.find(cur) != s.end()) {
        return cur;
      }
      cur = cur->next;
    }

    return NULL;
  }
};

// use count

class Solution {
 public:
  int countListNode(ListNode *head) {
    int count = 0;
    while (head) {
      count++;
      head = head->next;
    }
    return count;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int countA = 0, countB = 0;

    countA = countListNode(headA);
    countB = countListNode(headB);

    if (countA < countB) {
      swap(countA, countB);
      swap(headA, headB);
    }

    int diff = abs(countA - countB);

    for (int i = 0; i < diff; i++) {
      headA = headA->next;
    }

    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};

// use two pointer

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pointerA = headA, *pointerB = headB;
    while (pointerA != pointerB) {
      if (pointerA != NULL) {
        pointerA = pointerA->next;
      } else {
        pointerA = headB;
      }

      if (pointerB != NULL) {
        pointerB = pointerB->next;
      } else {
        pointerB = headA;
      }
    }
    return pointerA;
  }
};