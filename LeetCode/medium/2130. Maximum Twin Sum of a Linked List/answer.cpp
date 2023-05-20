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

// use array
// time : O(N)
// space : O(N)
class Solution {
 public:
  int pairSum(ListNode* head) {
    vector<int> nums;
    ListNode* cur = head;
    while (cur) {
      nums.push_back(cur->val);
      cur = cur->next;
    }

    int answer = 0;
    int size = nums.size();
    for (int i = 0; i < size / 2; i++) {
      int curSum = nums[i] + nums[size - 1 - i];

      answer = max(answer, curSum);
    }
    return answer;
  }
};

// use reverse linked list
// time : O(N)
// space : O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 private:
  int getLength(ListNode* head) {
    int length = 0;
    ListNode* cur = head;
    while (cur) {
      length++;
      cur = cur->next;
    }
    return length;
  }

  ListNode* reverse(ListNode* head, int size) {
    size--;

    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* cur = head;
    while (size--) {
      // dummy ... cur next nnext;
      // dummy next ... cur nnext;
      ListNode* next = cur->next;

      cur->next = next->next;
      next->next = dummy->next;
      dummy->next = next;
    }

    return dummy->next;
  }

 public:
  int pairSum(ListNode* head) {
    int length = getLength(head);
    int answer = 0;

    ListNode* start = reverse(head, length / 2);

    ListNode *first = start, *second = start;

    for (int i = 0; i < length / 2; i++) {
      second = second->next;
    }

    for (int i = 0; i < length / 2; i++) {
      int curSum = first->val + second->val;
      answer = max(answer, curSum);

      first = first->next;
      second = second->next;
    }

    return answer;
  }
};