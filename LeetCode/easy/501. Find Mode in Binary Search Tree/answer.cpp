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