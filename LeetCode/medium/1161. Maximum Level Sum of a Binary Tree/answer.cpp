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
  int maxLevelSum(TreeNode *root) {
    int maximum = INT_MIN;
    int answer = 0;

    queue<TreeNode *> q;
    q.push(root);

    int step = 1;
    while (!q.empty()) {
      int size = q.size();

      int curSum = 0;
      while (size--) {
        TreeNode *cur = q.front();
        q.pop();

        curSum += cur->val;

        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }

      if (maximum < curSum) {
        maximum = curSum;
        answer = step;
      }
      step++;
    }

    return answer;
  }
};