#include <algorithm>
#include <iostream>
#include <queue>
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

// use sort

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> nums;

    for (ListNode* node : lists) {
      while (node) {
        nums.push_back(node->val);
        node = node->next;
      }
    }
    sort(nums.begin(), nums.end());

    ListNode* dummy = new ListNode();
    ListNode* before = dummy;
    for (int num : nums) {
      before->next = new ListNode(num);
      before = before->next;
    }

    return dummy->next;
  }
};

// use mergeTwoLists

class Solution {
 private:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *before = dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        before->next = l1;
        l1 = l1->next;
      } else {
        before->next = l2;
        l2 = l2->next;
      }
      before = before->next;
    }

    before->next = l1 ? l1 : l2;
    return dummy->next;
  }

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ret = NULL;
    for (ListNode* list : lists) {
      ret = mergeTwoLists(list, ret);
    }
    return ret;
  }
};

// use merge sort (divide and conquer)

class Solution {
 private:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *before = dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        before->next = l1;
        l1 = l1->next;
      } else {
        before->next = l2;
        l2 = l2->next;
      }
      before = before->next;
    }

    before->next = l1 ? l1 : l2;
    return dummy->next;
  }

  ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
    if (right < left) return NULL;
    if (left == right) return lists[left];
    if (left + 1 == right) return mergeTwoLists(lists[left], lists[right]);

    int mid = left + (right - left) / 2;
    ListNode* leftPart = mergeKLists(lists, left, mid);
    ListNode* rightPart = mergeKLists(lists, mid + 1, right);

    return mergeTwoLists(leftPart, rightPart);
  }

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeKLists(lists, 0, lists.size() - 1);
  }
};

// use heap

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;

    auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

    for (ListNode* list : lists) {
      if (list) pq.push(list);
    }

    ListNode *dummy = new ListNode(), *before = dummy;
    while (!pq.empty()) {
      ListNode* cur = pq.top();
      pq.pop();

      before->next = cur;
      before = before->next;

      if (cur->next) {
        pq.push(cur->next);
      }
    }
    return dummy->next;
  }
};