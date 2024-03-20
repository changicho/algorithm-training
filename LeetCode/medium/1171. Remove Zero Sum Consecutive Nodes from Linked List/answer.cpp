#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// use brute force with array
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    vector<int> nums;

    ListNode *cur = head;
    while (cur) {
      int val = cur->val;
      cur = cur->next;

      nums.push_back(val);
    }

    int size = nums.size();
    vector<bool> isRemoved(size, false);
    for (int i = 0; i < size; i++) {
      if (isRemoved[i]) continue;
      int left = -1, right = -1;
      int sum = 0;
      for (int j = i; j < size; j++) {
        if (isRemoved[j]) break;

        sum += nums[j];
        if (sum == 0) {
          left = i, right = j;
          break;
        }
      }

      if (left == -1) continue;
      for (int k = left; k <= right; k++) {
        isRemoved[k] = true;
      }
    }

    ListNode *dummy = new ListNode();
    cur = dummy;
    for (int i = 0; i < size; i++) {
      if (isRemoved[i]) continue;

      cur->next = new ListNode(nums[i]);
      cur = cur->next;
    }
    return dummy->next;
  }
};

// use brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *cur = dummy;

    while (cur) {
      int sum = 0;
      ListNode *next = cur->next;

      while (next) {
        sum += next->val;
        if (sum == 0) {
          cur->next = next->next;
        }
        next = next->next;
      }

      cur = cur->next;
    }
    return dummy->next;
  }
};

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  ListNode *removeZeroSumSublists(ListNode *head) {
    int sum = 0;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *cur = head;
    ListNode *before = dummy;

    unordered_map<int, ListNode *> um;
    um[0] = before;

    while (cur) {
      sum += cur->val;

      if (um.count(sum) > 0) {
        ListNode *target = um[sum];

        ListNode *temp = target->next;
        int tempSum = sum + temp->val;
        while (tempSum != sum) {
          um.erase(tempSum);
          temp = temp->next;
          tempSum += temp->val;
        }

        target->next = cur->next;
      } else {
        um[sum] = cur;
      }

      before = cur;
      cur = cur->next;
    }

    return dummy->next;
  }
};