#include <algorithm>
#include <iostream>
#include <queue>
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

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> answer;

    queue<TreeNode *> q;
    if (root) q.push(root);

    while (!q.empty()) {
      int curMax = INT_MIN;
      int size = q.size();

      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        curMax = max(curMax, cur->val);

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      answer.push_back(curMax);
    }
    return answer;
  }
};