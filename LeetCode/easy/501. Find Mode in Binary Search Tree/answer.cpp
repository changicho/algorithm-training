#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// use brute force
// time : O(N)
// space : O(N)
class Solution {
 private:
  void recursive(TreeNode *node, unordered_map<int, int> &counts) {
    if (!node) return;

    counts[node->val]++;

    if (node->left) recursive(node->left, counts);
    if (node->right) recursive(node->right, counts);
  }

 public:
  vector<int> findMode(TreeNode *root) {
    unordered_map<int, int> counts;

    recursive(root, counts);

    int maximum = 0;
    for (auto &it : counts) {
      int key = it.first, val = it.second;
      maximum = max(maximum, val);
    }

    vector<int> answer;
    for (auto &it : counts) {
      int key = it.first, val = it.second;

      if (val == maximum) {
        answer.push_back(key);
      }
    }
    return answer;
  }
};

// use inOrder
// time : O(N)
// space : O(1)
class Solution {
 private:
  int maximum = 0, curCount = 0, curVal = INT_MIN;
  vector<int> answer;

  void inOrder(TreeNode *root) {
    if (root == NULL) return;

    inOrder(root->left);
    if (curVal == root->val) {
      curCount++;
    } else {
      curCount = 1;
    }

    if (curCount > maximum) {
      answer.clear();
      maximum = curCount;
      answer.push_back(root->val);
    } else if (curCount == maximum) {
      answer.push_back(root->val);
    }
    curVal = root->val;
    inOrder(root->right);
  }

 public:
  vector<int> findMode(TreeNode *root) {
    inOrder(root);

    return answer;
  }
};