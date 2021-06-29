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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use recursive & rabbit and turtle

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    return recursive(head, NULL);
  }

 private:
  TreeNode *recursive(ListNode *left, ListNode *right) {
    if (left == right) return NULL;
    if (left->next == right) {
      TreeNode *root = new TreeNode(left->val);
      return root;
    }

    ListNode *mid = getMid(left, right);

    TreeNode *root = new TreeNode(mid->val);
    root->left = recursive(left, mid);
    root->right = recursive(mid->next, right);
    return root;
  }

  ListNode *getMid(ListNode *left, ListNode *right) {
    ListNode *slow = left, *fast = left;
    while (fast != right && fast->next != right) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

// use recursive and array

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    vector<int> array;
    ListNode *cur = head;

    while (cur) {
      array.push_back(cur->val);
      cur = cur->next;
    }

    int size = array.size();
    return recursive(array, 0, size);
  }

 private:
  TreeNode *recursive(vector<int> &array, int left, int right) {
    if (left == right) return NULL;
    if (left + 1 == right) {
      TreeNode *root = new TreeNode(array[left]);
      return root;
    }

    int mid = left + (right - left) / 2;

    TreeNode *root = new TreeNode(array[mid]);
    root->left = recursive(array, left, mid);
    root->right = recursive(array, mid + 1, right);
    return root;
  }
};