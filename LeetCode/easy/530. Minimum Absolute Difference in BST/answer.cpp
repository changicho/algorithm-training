#include <algorithm>
#include <iostream>
#include <string>
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

// use inOrder
// time : O(N)
// space : O(N)
class Solution {
 private:
  void recursive(TreeNode *node, vector<int> &nums) {
    if (!node) return;

    if (node->left) {
      recursive(node->left, nums);
    }
    nums.push_back(node->val);
    if (node->right) {
      recursive(node->right, nums);
    }
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    int answer = 100001;

    vector<int> nums;
    recursive(root, nums);

    for (int i = 0; i < nums.size() - 1; i++) {
      answer = min(answer, abs(nums[i] - nums[i + 1]));
    }

    return answer;
  }
};

// use inOrder (space optimized)
// time : O(N)
// space : O(H)
class Solution {
 private:
  int answer = INT_MAX;
  int prev = -1;

  void recursive(TreeNode *node) {
    if (!node) return;

    recursive(node->left);

    if (prev != -1) answer = min(answer, abs(node->val - prev));
    prev = node->val;

    recursive(node->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    recursive(root);

    return answer;
  }
};