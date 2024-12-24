#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// use DFS
// time : O(N)
// space : O(log_2(N))
class Solution {
 private:
  void recursive(TreeNode* left, TreeNode* right, int depth) {
    if (!left || !right) return;

    if (depth % 2 == 0) {
      swap(left->val, right->val);
    }

    recursive(left->left, right->right, depth + 1);
    recursive(left->right, right->left, depth + 1);
  }

 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    recursive(root->left, root->right, 0);

    return root;
  }
};

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  void recursive(TreeNode* node, int depth) {
    if (depth % 2 == 0) {
      if (node->left && node->right) {
        swap(node->left->val, node->right->val);
      }
    }

    if (node->left) recursive(node->left, depth + 1);
    if (node->right) recursive(node->right, depth + 1);
  }

 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);
    int step = 0;

    while (!q.empty()) {
      int size = q.size();
      vector<TreeNode*> nodes;
      vector<int> vals;
      while (size--) {
        TreeNode* cur = q.front();
        q.pop();

        nodes.push_back(cur);
        vals.push_back(cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      if (step % 2 == 1) {
        int size = vals.size();

        for (int i = 0; i < size; i++) {
          nodes[i]->val = vals[size - 1 - i];
        }
      }

      step++;
    }

    return root;
  }
};