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

// use two BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<int> sumByLevels;

    while (!q.empty()) {
      int sum = 0;
      int size = q.size();
      while (size--) {
        TreeNode* cur = q.front();
        q.pop();

        sum += cur->val;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      sumByLevels.push_back(sum);
    }

    q.push(root);
    int level = 1;
    root->val = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode* cur = q.front();
        q.pop();

        int siblingSum = (cur->left ? cur->left->val : 0) +
                         (cur->right ? cur->right->val : 0);

        // update children's value
        if (cur->left) {
          cur->left->val = sumByLevels[level] - siblingSum;
          q.push(cur->left);
        }
        if (cur->right) {
          cur->right->val = sumByLevels[level] - siblingSum;
          q.push(cur->right);
        }
      }
      level++;
    }

    return root;
  }
};