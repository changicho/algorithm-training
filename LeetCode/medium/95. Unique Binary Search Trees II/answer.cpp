#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
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

// use dynamic programming (top down)
// time : O(4^N / sqrt(N))
// space : O(4^N / sqrt(N))
class Solution {
 public:
  vector<TreeNode*> dp[9][9];

  vector<TreeNode*> generateTrees(int n) { return generateSubTrees(1, n); }

  vector<TreeNode*> generateSubTrees(int from, int to) {
    if (from > to) return {NULL};
    if (from == to) return {new TreeNode(from)};
    if (!dp[from][to].empty()) return dp[from][to];
    vector<TreeNode*> res;

    vector<TreeNode*> leftSubTree, rightSubTree;

    for (int cur = from; cur <= to; cur++) {
      leftSubTree = generateSubTrees(from, cur - 1);
      rightSubTree = generateSubTrees(cur + 1, to);

      for (TreeNode* leftNode : leftSubTree) {
        for (TreeNode* rightNode : rightSubTree) {
          TreeNode* root = new TreeNode(cur);
          root->left = leftNode;
          root->right = rightNode;
          res.push_back(root);
        }
      }
    }
    dp[from][to] = res;
    return res;
  }
};

// use dynamic programming (bottom up)
// time : O(4^N / sqrt(N))
// space : O(4^N / sqrt(N))
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> dp[9][9];
    for (int i = 1; i <= n; i++) {
      dp[i][i].push_back(new TreeNode(i));
    }

    for (int nodes = 2; nodes <= n; nodes++) {
      for (int start = 1; start <= n - nodes + 1; start++) {
        int end = start + nodes - 1;
        for (int i = start; i <= end; i++) {
          vector<TreeNode*> leftSubtrees =
              i - 1 >= start ? dp[start][i - 1] : vector<TreeNode*>({NULL});
          vector<TreeNode*> rightSubtrees =
              i + 1 <= end ? dp[i + 1][end] : vector<TreeNode*>({NULL});

          for (auto left : leftSubtrees) {
            for (auto right : rightSubtrees) {
              TreeNode* root = new TreeNode(i, left, right);
              dp[start][end].push_back(root);
            }
          }
        }
      }
    }
    return dp[1][n];
  }
};